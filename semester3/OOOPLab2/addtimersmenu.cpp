#include "addtimersmenu.h"
#include "ui_addtimersmenu.h"
#include "timer.h"

#include <QFileDialog>

addTimersMenu::addTimersMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTimersMenu)
{
    this->ui->setupUi(this);

    this->timerName = new QLabel;
    Timer temporary;
    this->ui->findSoundPath->setText(temporary.getDefaultSound());

    // колір фону - чорний
    this->setStyleSheet("background-color: black;");
    this->ui->timerName->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxHours->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxMinutes->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxSeconds->setStyleSheet("border: 1px solid black");
    this->ui->spinBoxMiliseconds->setStyleSheet("border: 1px solid black");
    this->ui->findSoundPath->setStyleSheet("border: 1px solid black");

    // Обмеження на інпути
    this->ui->spinBoxHours->setRange(0, this->maxHours);
    this->ui->spinBoxMinutes->setRange(0, 59);
    this->ui->spinBoxSeconds->setRange(0, 59);
    this->ui->spinBoxMiliseconds->setRange(0, 999);
    this->ui->timerName->setMaxLength(this->maxTimerNameLenght);

    // startTimersButton - пуск таймерів
    connect(this->ui->startTimersButton, SIGNAL(clicked()), this, SLOT(startTimers()));

    // backButton - вихід
    connect(this->ui->backButton, SIGNAL(clicked()), this, SLOT(close()));

    // Обрати шлях
    connect(this->ui->findSoundButton, SIGNAL(clicked()), this, SLOT(findSound()));
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

QString addTimersMenu::getTimerSound()
{
    return this->ui->findSoundPath->text();
}

void addTimersMenu::startTimers()
{
    setTime();
    addTimersMenu::accept();
}

void addTimersMenu::findSound()
{
    this->ui->findSoundPath->setText(QFileDialog::getOpenFileName(this, "Оберіть свій звук для таймера"));
    if (this->ui->findSoundPath->text() == "")
    {
        Timer temporary;
        this->ui->findSoundPath->setText(temporary.getDefaultSound());
    }
}


void addTimersMenu::setTime()
{
    int hours = this->ui->spinBoxHours->value();
    int minutes = this->ui->spinBoxMinutes->value();
    int seconds = this->ui->spinBoxSeconds->value();
    int miliseconds =this-> ui->spinBoxMiliseconds->value();

    this->endTime.setHMS(hours, minutes, seconds, miliseconds);
    this->timerName->setText(this->ui->timerName->text());
}
