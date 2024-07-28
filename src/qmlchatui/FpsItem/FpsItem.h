#pragma once

#include <qquickitem.h>

class FpsItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int fps MEMBER fps_ NOTIFY fpsChanged)
public:
    explicit FpsItem(QQuickItem* parent = nullptr);

signals:
    void fpsChanged();

private:
    int fps_;
    int frameCount_;
};
