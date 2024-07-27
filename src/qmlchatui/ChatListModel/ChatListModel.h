#pragma once

#include <qabstractitemmodel.h>

class ChatListModelPrivate;
class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ChatListModel(QObject* parent = nullptr);
    ~ChatListModel();

    Q_INVOKABLE int      rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex& index, int role) const override;
    Q_INVOKABLE virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addChat(const QString& name, const QString& msg);
    Q_INVOKABLE void removeChat(const int index);

private:
    ChatListModelPrivate* d_ptr;
};
