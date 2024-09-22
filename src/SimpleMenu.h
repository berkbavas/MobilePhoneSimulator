#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

#include "Item.h"

#include <QObject>

class SimpleMenu : public Item
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QStringList rows READ rows WRITE setRows NOTIFY rowsChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int firstVisibleIndex READ firstVisibleIndex WRITE setFirstVisibleIndex NOTIFY firstVisibleIndexChanged)
    Q_PROPERTY(int lastVisibleIndex READ lastVisibleIndex WRITE setLastVisibleIndex NOTIFY lastVisibleIndexChanged)

public:
    explicit SimpleMenu(QObject *parent = nullptr);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QStringList &rows() const;
    void setRows(const QStringList &newRows);

    int currentIndex() const;
    void setCurrentIndex(int newCurrentIndex);

    int firstVisibleIndex() const;
    void setFirstVisibleIndex(int newFirstVisibleIndex);

    int lastVisibleIndex() const;
    void setLastVisibleIndex(int newLastVisibleIndex);

public slots:
    void addRow(const QString &row);
    void setRow(int index, const QString &row);
    void clearAll();
    void clearRows();
    void increment();
    void decrement();
    void reset();
    void update();

signals:
    void titleChanged();
    void rowsChanged();
    void currentIndexChanged();
    void firstVisibleIndexChanged();
    void lastVisibleIndexChanged();

private:
    QString mTitle;
    QStringList mRows;

    // Scroll
    int mCurrentIndex;
    int mFirstVisibleIndex;
    int mLastVisibleIndex;
};

#endif // SIMPLEMENU_H
