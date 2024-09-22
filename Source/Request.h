#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>

class Request : public QObject
{
    Q_OBJECT
public:
    enum class Status { //
        Created,
        Pending,
        Processing,
        Processed,
        Finished
    };

    explicit Request(QObject *parent = nullptr);

    Status status() const;
    void setStatus(Status newStatus);

private:
    Status mStatus;
};

#endif // REQUEST_H
