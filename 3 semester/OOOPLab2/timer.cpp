#include "timer.h"
#include <QVariant>

Timer::Timer()
{
    this->endTime.setHMS(0, 0, 0);

    this->time = new QLabel;
    this->name = new QLabel;
    this->info = new QListWidgetItem("00:00:00:000");

    this->info->setTextAlignment(Qt::AlignCenter);
//    this->time->setAlignment(Qt::AlignCenter);
//    this->name->setAlignment(Qt::AlignCenter);

      this->info->setFont(QFont("JetBrains Mono NL", 20));
//    this->time->setFont(QFont("JetBrains Mono NL", 18));
//    this->name->setFont(QFont("Montserrat", 18));

    this->lastUpdateTime = QTime::currentTime();
}

Timer::Timer(QTime time, QString name, bool alarm)
{
    this->endTime = time;
    this->alarm = alarm;

    this->name = new QLabel;
    this->time = new QLabel;

    this->name->setText(name);
    this->time->setText(time.toString("00:00:00:000"));

    this->info = new QListWidgetItem("00:00:00:000");
    QVariant data(name);
    this->info->setData(Qt::UserRole, data);

    this->info->setTextAlignment(Qt::AlignCenter);
//    this->time->setAlignment(Qt::AlignCenter);
//    this->name->setAlignment(Qt::AlignCenter);

    this->info->setFont(QFont("JetBrains Mono NL", 20));
//    this->time->setFont(QFont("JetBrains Mono NL", 18));
//    this->name->setFont(QFont("Montserrat", 18));

    this->lastUpdateTime = QTime::currentTime();
}

Timer::~Timer()
{
    delete this->time;
    delete this->name;
    delete this->info;
}

QTime Timer::getEndTime()
{
    return endTime;
}

QTime Timer::getLastUpdateTime()
{
    return this->lastUpdateTime;
}

void Timer::setEndTime(QTime newTime)
{
    this->endTime = newTime;
}

void Timer::setLastUpdateTime(QTime newUpdateTime)
{
    this->lastUpdateTime = newUpdateTime;
}

void Timer::setTime(QString newTime)
{
    this->time->setText(newTime);
    this->info->setText(newTime);
}

void Timer::setName(QString newName)
{
    this->name->setText(newName);
    this->info->setData(Qt::UserRole, newName);
}

void Timer::setAlarm(bool alarm)
{
    this->alarm = alarm;
}

void Timer::setPaused(bool stop)
{
    this->paused = stop;
}

QLabel* Timer::getTime()
{
    return this->time;
}

QLabel* Timer::getName()
{
    return this->name;
}

QListWidgetItem *Timer::getInfo()
{
    return this->info;
}

bool Timer::isAlarm()
{
    return this->alarm;
}

bool Timer::isPaused()
{
    return this->paused;
}
