#pragma once

#include <QWidget>

namespace Ui {
class LiteStudio;
}

class LiteRPC;
class LiteStudio : public QWidget
{
    Q_OBJECT

public:
    explicit LiteStudio(QWidget* parent = nullptr);
    ~LiteStudio();

private:
    Ui::LiteStudio* ui;

    private:
    LiteRPC* lite_;
};
