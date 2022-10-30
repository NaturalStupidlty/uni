#include "addtimersmenu.h"
#include "ui_addtimersmenu.h"

#include <QTime>

addTimersMenu::addTimersMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTimersMenu)
{
    ui->setupUi(this);

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // Обмеження на інпут спінбоксів
    ui->spinBox->setRange(0, maxHours);
    ui->spinBox_2->setRange(0, 59);
    ui->spinBox_3->setRange(0, 59);
    ui->spinBox_4->setRange(0, 999);

    // startTimersButton - пуск таймерів
    connect(ui->startTimersButton, SIGNAL(clicked()), this, SLOT(startTimers()));
}

addTimersMenu::~addTimersMenu()
{
    delete ui;
}

QTime addTimersMenu::getEndTime()
{
    return endTime;
}

void addTimersMenu::startTimers()
{
    setTime();
    addTimersMenu::accept();
}

void addTimersMenu::setTime()
{
    int hours = ui->spinBox->text().toInt();
    int minutes = ui->spinBox_2->text().toInt();
    int seconds = ui->spinBox_3->text().toInt();
    int miliseconds = ui->spinBox_4->text().toInt();

    endTime.setHMS(hours, minutes, seconds, miliseconds);
}
