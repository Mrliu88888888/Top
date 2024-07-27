#pragma once

#include <qurl.h>

class ChatListModelPrivate
{
public:
    explicit ChatListModelPrivate() {}

    enum ChatRole : int
    {
        Avatar = Qt::UserRole + 1,
        Name,
        Msg,
        Time
    };

    struct ChatInfo
    {
        QUrl    avatar;
        QString name;
        QString msg;
        QString time;
    };
    QList<ChatInfo> data;
};
