#pragma once

#include <qquickitem.h>

class FpsItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int fps MEMBER fps_ NOTIFY fpsChanged)
public:
    explicit FpsItem();

signals:
    void fpsChanged();

private:
    int fps_;
};
