#include "LiteStudio.h"
#include "ui_LiteStudio.h"
#include <qdebug.h>
#include "LiteRPC.h"

#define COMMAND_START_CHARACTER ">"

LiteStudio::LiteStudio(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LiteStudio)
    , lite_(new LiteRPC())
{
    ui->setupUi(this);

    connect(ui->btnConnect, &QPushButton::clicked, this, [this]() {
        if (ui->leUrl->text().isEmpty()) {
            return;
        }
        qDebug() << "connect: " << lite_->connect(ui->leUrl->text().toStdString());
    });
    connect(ui->btnClose, &QPushButton::clicked, this, [this]() { lite_->close(); });
    connect(ui->btnExec, &QPushButton::clicked, this, [this]() {
        if (ui->leSql->text().isEmpty()) {
            return;
        }

        ui->teResult->append(QString("%1 %2").arg(COMMAND_START_CHARACTER).arg(ui->leSql->text()));
        ui->leSql->clear();

        std::string output;
        lite_->exec(ui->leSql->text().toStdString(), &output);
        ui->teResult->append(QString::fromStdString(output));
    });
}

LiteStudio::~LiteStudio()
{
    delete lite_;
    delete ui;
}
