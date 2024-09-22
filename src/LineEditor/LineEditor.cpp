#include "LineEditor.h"

#include <QMap>

LineEditor::LineEditor(QObject *parent)
    : QObject{parent}
    , mEditMode(LineEditor::EditMode::All)
    , mCurrentButton(Enums::Button::None)
    , mCurrentCharset(nullptr)
    , mLine()
    , mEditingChar()
    , mUpperCaseEnabled(false)
    , mCharacterLimit(10)
    , mEditing(false)
    , mBlinkingTimeElapsed(0)
    , mEditingTimeElapsed(0)

{}

void LineEditor::onAction(Action *action)
{
    switch (action->button())
    {
    case Enums::Button::Zero:
    case Enums::Button::One:
    case Enums::Button::Two:
    case Enums::Button::Three:
    case Enums::Button::Four:
    case Enums::Button::Five:
    case Enums::Button::Six:
    case Enums::Button::Seven:
    case Enums::Button::Eight:
    case Enums::Button::Nine:
        if (getNumberOfRemainingCharacters() != 0)
        {
            if (mEditMode == EditMode::All)
            {
                mEditing = true;
                mEditingTimeElapsed = 0;
                if (mCurrentButton == action->button())
                {
                    if (mCurrentCharset)
                        mEditingChar = isUpperCaseEnabled() ? mCurrentCharset->next().toUpper()
                                                            : mCurrentCharset->next();
                }
                else
                {
                    mCurrentButton = action->button();
                    mLine += mEditingChar;
                    mCurrentCharset = ALL_CHARSET_MAP.value(mCurrentButton, nullptr);
                    if (mCurrentCharset)
                    {
                        mCurrentCharset->reset();
                        mEditingChar = isUpperCaseEnabled() ? mCurrentCharset->next().toUpper()
                                                            : mCurrentCharset->next();
                    }
                }
            }
            else if (mEditMode == EditMode::OnlyNumbers)
            {
                mCurrentButton = action->button();
                mCurrentCharset = NUMBER_CHARSET_MAP.value(mCurrentButton, nullptr);
                if (mCurrentCharset)
                {
                    mLine += mCurrentCharset->next();
                }
            }
        }
        action->setConsumed(true);
        break;
    case Enums::Button::Square:
        mCurrentButton = action->button();
        mEditing = true;
        mEditingTimeElapsed = 0;
        mUpperCaseEnabled = !mUpperCaseEnabled;
        action->setConsumed(true);
        break;
    case Enums::Button::Clear:
        mCurrentButton = action->button();
        mCurrentCharset = nullptr;
        mEditing = true;
        mEditingTimeElapsed = 0;

        if (mLine.isEmpty())
        {
            action->setConsumed(false);
            return;
        }

        if (mEditMode == EditMode::All)
        {
            if (mEditingChar.isEmpty())
                mLine = mLine.left(mLine.length() - 1);
            else
                mEditingChar.clear();
        }
        else if (mEditMode == EditMode::OnlyNumbers)
        {
            mLine = mLine.left(mLine.length() - 1);
        }
        action->setConsumed(true);
        break;
    case Enums::Button::Enter:
        mLine += mEditingChar;
        action->setConsumed(false);
        break;
    case Enums::Button::Up:
    case Enums::Button::Down:
        mLine += mEditingChar;
        mEditingChar.clear();
        mEditing = false;
        mCurrentButton = action->button();
        mCurrentCharset = nullptr;
        break;
    default:
        break;
    }
}

void LineEditor::update(quint64 milisecondsElapsed)
{
    if (mBlinkingTimeElapsed < 500)
    {
        mCursor = "▏";
    }
    else if (mBlinkingTimeElapsed < 1000)
    {
        mCursor = " ";
    }
    else
    {
        mBlinkingTimeElapsed = 0;
    }

    if (mEditMode == EditMode::All && mEditing && mEditingTimeElapsed > 2000)
    {
        mLine += mEditingChar;
        mEditingChar.clear();
        mEditing = false;
        mCurrentButton = Enums::Button::None;
        mCurrentCharset = nullptr;
    }

    mBlinkingTimeElapsed += milisecondsElapsed;
    mEditingTimeElapsed += milisecondsElapsed;
}

void LineEditor::reset()
{
    mEditMode = LineEditor::EditMode::All;
    mCurrentButton = Enums::Button::None;
    mCurrentCharset = nullptr;
    mLine.clear();
    mEditingChar.clear();
    mCharacterLimit = 10;
    mEditing = false;
    mBlinkingTimeElapsed = 0;
    mEditingTimeElapsed = 0;
}

bool LineEditor::isUpperCaseEnabled()
{
    return mUpperCaseEnabled || mLine.isEmpty();
}

QString LineEditor::getVisualLine()
{
    return mLine + mEditingChar + mCursor;
}

QString LineEditor::getHint()
{
    if (mEditMode == EditMode::All)
    {
        if (mEditing)
            if (mCurrentCharset)
                return isUpperCaseEnabled() ? mCurrentCharset->hint().toUpper() + " ⇧"
                                            : mCurrentCharset->hint();
            else
                return isUpperCaseEnabled() ? "⇧" : "";
        else
            return isUpperCaseEnabled() ? "⇧" : "";
    }
    else
    {
        return "";
    }
}

int LineEditor::getNumberOfRemainingCharacters()
{
    return mCharacterLimit - mLine.length() - mEditingChar.length();
}

int LineEditor::characterLimit() const
{
    return mCharacterLimit;
}

void LineEditor::setCharacterLimit(int newCharacterLimit)
{
    mCharacterLimit = newCharacterLimit;
}

const QString &LineEditor::line() const
{
    return mLine;
}

void LineEditor::setLine(const QString &newLine)
{
    mLine = newLine;
}

LineEditor::EditMode LineEditor::editMode() const
{
    return mEditMode;
}

void LineEditor::setEditMode(EditMode newEditMode)
{
    mEditMode = newEditMode;
}

const QMap<Enums::Button, Charset *> LineEditor::ALL_CHARSET_MAP = { //
    {Enums::Button::Zero, new Charset(" 0", "␣0")},
    {Enums::Button::One, new Charset("")},
    {Enums::Button::Two, new Charset("abc2")},
    {Enums::Button::Three, new Charset("def3")},
    {Enums::Button::Four, new Charset("ghi4")},
    {Enums::Button::Five, new Charset("jkl5")},
    {Enums::Button::Six, new Charset("mno6")},
    {Enums::Button::Seven, new Charset("pqrs7")},
    {Enums::Button::Eight, new Charset("tuv8")},
    {Enums::Button::Nine, new Charset("wxyz9")}};

const QMap<Enums::Button, Charset *> LineEditor::NUMBER_CHARSET_MAP = {
    {Enums::Button::Zero, new Charset("0")},
    {Enums::Button::One, new Charset("1")},
    {Enums::Button::Two, new Charset("2")},
    {Enums::Button::Three, new Charset("3")},
    {Enums::Button::Four, new Charset("4")},
    {Enums::Button::Five, new Charset("5")},
    {Enums::Button::Six, new Charset("6")},
    {Enums::Button::Seven, new Charset("7")},
    {Enums::Button::Eight, new Charset("8")},
    {Enums::Button::Nine, new Charset("9")},
};
