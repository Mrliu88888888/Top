#include "FpsItem.h"
#include <qtimer.h>
#include <qrandom.h>

FpsItem::FpsItem()
    : fps_(0)
{
    auto tmr = new QTimer(this);
    connect(tmr, &QTimer::timeout, this, [this]() {
        fps_ = QRandomGenerator::global()->bounded(100);
        emit fpsChanged();
    });
    tmr->start(1000);
}
