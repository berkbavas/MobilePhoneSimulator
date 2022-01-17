#ifndef SCROLLHANDLER_H
#define SCROLLHANDLER_H

#include <QObject>

class ScrollHandler : public QObject
{
    Q_OBJECT
public:
    explicit ScrollHandler(QObject *parent = nullptr);

    int menuSize() const;
    void setMenuSize(int newMenuSize);

    int currentIndex() const;
    void setCurrentIndex(int newCurrentIndex);

    int firstVisibleIndex() const;
    void setFirstVisibleIndex(int newFirstVisibleIndex);

    int lastVisibleIndex() const;
    void setLastVisibleIndex(int newLastVisibleIndex);

public slots:
    bool increment();
    bool decrement();
    void reset();

private slots:
    void update();

signals:
    void menuSizeChanged();
    void currentIndexChanged();
    void firstVisibleIndexChanged();
    void lastVisibleIndexChanged();

private:
    int mMenuSize;
    int mCurrentIndex;
    int mFirstVisibleIndex;
    int mLastVisibleIndex;

    Q_PROPERTY(int menuSize READ menuSize WRITE setMenuSize NOTIFY menuSizeChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int firstVisibleIndex READ firstVisibleIndex WRITE setFirstVisibleIndex NOTIFY firstVisibleIndexChanged)
    Q_PROPERTY(int lastVisibleIndex READ lastVisibleIndex WRITE setLastVisibleIndex NOTIFY lastVisibleIndexChanged)
};

#endif // SCROLLHANDLER_H
