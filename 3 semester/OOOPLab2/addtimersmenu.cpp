#include "addtimersmenu.h"
#include "ui_addtimersmenu.h"

#include <QTime>

addTimersMenu::addTimersMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTimersMenu)
{
    this->ui->setupUi(this);

    this->timerName = new QLabel;

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");
    this->ui->timerName->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxHours->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxMinutes->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxSeconds->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxMiliseconds->setStyleSheet("border: 1px solid black");

    // Обмеження на інпути
    this->ui->spinBoxHours->setRange(0, maxHours);
    this->ui->spinBoxMinutes->setRange(0, 59);
    this->ui->spinBoxSeconds->setRange(0, 59);
    this->ui->spinBoxMiliseconds->setRange(0, 999);
    this->ui->timerName->setMaxLength(maxTimerNameLenght);

    // startTimersButton - пуск таймерів
    connect(this->ui->startTimersButton, SIGNAL(clicked()), this, SLOT(startTimers()));
    // backButton - вихід
    connect(this->ui->backButton, SIGNAL(clicked()), this, SLOT(close()));
}

addTimersMenu::~addTimersMenu()
{
    delete this->ui;
    delete this->timerName;
}

QTime addTimersMenu::getEndTime()
{
    return this->endTime;
}

QLabel* addTimersMenu::getTimerName()
{
    return this->timerName;
}

bool addTimersMenu::isAlarm()
{
    return this->alarm;
}

void addTimersMenu::startTimers()
{
    setTime();
    addTimersMenu::accept();
}

void addTimersMenu::setTime()
{
    int hours = this->ui->spinBoxHours->value();
    int minutes = this->ui->spinBoxMinutes->value();
    int seconds = this->ui->spinBoxSeconds->value();
    int miliseconds =this-> ui->spinBoxMiliseconds->value();

    this->endTime.setHMS(hours, minutes, seconds, miliseconds);
    this->timerName->setText(this->ui->timerName->text());
    this->alarm = this->ui->checkedAlarm->isChecked();
}
