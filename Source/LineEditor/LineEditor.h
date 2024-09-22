#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#include "Action.h"
#include "Charset.h"
#include "Enums.h"

#include <QObject>

class LineEditor : public QObject
{
    Q_OBJECT
public:
    explicit LineEditor(QObject *parent = nullptr);

    enum class EditMode { //
        All,
        OnlyNumbers
    };

    EditMode editMode() const;
    void setEditMode(EditMode newEditMode);

    const QString &line() const;
    void setLine(const QString &newLine);

    int characterLimit() const;
    void setCharacterLimit(int newCharacterLimit);

public slots:
    void update(quint64 milisecondsElapsed);
    void onAction(Action *action);
    void reset();
    bool isUpperCaseEnabled();
    QString getVisualLine();
    QString getHint();
    int getNumberOfRemainingCharacters();

private:
    EditMode mEditMode;
    Enums::Button mCurrentButton;
    Charset *mCurrentCharset;
    QString mLine;
    QString mEditingChar;
    QString mCursor;
    bool mUpperCaseEnabled;
    int mCharacterLimit;
    bool mEditing;

    quint64 mBlinkingTimeElapsed;
    quint64 mEditingTimeElapsed;

    static const QMap<Enums::Button, Charset *> ALL_CHARSET_MAP;
    static const QMap<Enums::Button, Charset *> NUMBER_CHARSET_MAP;
};

#endif // LINEEDITOR_H
