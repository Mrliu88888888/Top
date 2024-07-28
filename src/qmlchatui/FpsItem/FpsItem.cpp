#include "FpsItem.h"
#include <qtimer.h>
#include <qquickwindow.h>

FpsItem::FpsItem(QQuickItem* parent)
    : QQuickItem(parent)
    , fps_(0)
    , frameCount_(0)
{
    auto tmr = new QTimer(this);
    connect(tmr, &QTimer::timeout, this, [this]() {
        fps_        = frameCount_;
        frameCount_ = 0;
        emit fpsChanged();
    });
    tmr->start(1000);

    connect(this, &QQuickItem::windowChanged, this, [this]() {
        if (window()) {
            connect(
                window(),
                &QQuickWindow::afterRendering,
                this,
                [this]() { ++frameCount_; },
                Qt::DirectConnection);
        }
    });
}
