#include "ChatListModel.h"
#include "ChatListModel_p.h"
#include <qdatetime.h>

ChatListModel::ChatListModel(QObject* parent)
    : QAbstractListModel(parent)
    , d_ptr(new ChatListModelPrivate())
{}

ChatListModel::~ChatListModel()
{
    delete d_ptr;
}

int ChatListModel::rowCount(const QModelIndex& parent) const
{
    return d_ptr->data.size();
}

QVariant ChatListModel::data(const QModelIndex& index, int role) const
{
    const auto& chat = d_ptr->data.at(index.row());
    switch (role) {
    case ChatListModelPrivate::ChatRole::Avatar: return chat.avatar;
    case ChatListModelPrivate::ChatRole::Name: return chat.name;
    case ChatListModelPrivate::ChatRole::Msg: return chat.msg;
    case ChatListModelPrivate::ChatRole::Time: return chat.time;
    default: return QVariant();
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    return QHash<int, QByteArray>{{ChatListModelPrivate::ChatRole::Avatar, "avatar"},
                                  {ChatListModelPrivate::ChatRole::Name, "name"},
                                  {ChatListModelPrivate::ChatRole::Msg, "msg"},
                                  {ChatListModelPrivate::ChatRole::Time, "time"}};
}

void ChatListModel::addChat(const QString& name, const QString& msg)
{
    beginInsertRows(QModelIndex(), d_ptr->data.size(), d_ptr->data.size());
    d_ptr->data.append(ChatListModelPrivate::ChatInfo{
        "qrc:/chat/res/chat/sd.png",
        name,
        msg,
        QTime::currentTime().toString(),
    });
    endInsertRows();
}

void ChatListModel::removeChat(const int index)
{
    if (index < 0) {
        return;
    }
    beginRemoveRows(QModelIndex(), index, index);
    d_ptr->data.removeAt(index);
    endRemoveRows();
}
