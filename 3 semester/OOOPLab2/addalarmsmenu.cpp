#include "addalarmsmenu.h"
#include "ui_addalarmsmenu.h"

addAlarmsMenu::addAlarmsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAlarmsMenu)
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

addAlarmsMenu::~addAlarmsMenu()
{
    delete this->ui;
    delete this->timerName;
}

QTime addAlarmsMenu::getEndTime()
{
    return this->endTime;
}

QLabel* addAlarmsMenu::getTimerName()
{
    return this->timerName;
}

void addAlarmsMenu::startTimers()
{
    setTime();
    addAlarmsMenu::accept();
}

void addAlarmsMenu::setTime()
{
    int hours = this->ui->spinBoxHours->value();
    int minutes = this->ui->spinBoxMinutes->value();
    int seconds = this->ui->spinBoxSeconds->value();
    int miliseconds = this-> ui->spinBoxMiliseconds->value();

    this->endTime.setHMS(hours, minutes, seconds, miliseconds);
    QTime currentTime = QTime::currentTime();
    if (currentTime > this->endTime)
    {
        const int msecsInADay = 86400000;
        this->endTime = this->endTime.addMSecs(msecsInADay - currentTime.msecsSinceStartOfDay());
    }
    this->endTime = this->endTime.addMSecs(-currentTime.msecsSinceStartOfDay());
    this->timerName->setText(this->ui->timerName->text());
}
