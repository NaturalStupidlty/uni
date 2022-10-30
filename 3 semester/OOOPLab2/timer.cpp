#include "timer.h"

Timer::Timer()
{
    endTime.setHMS(0, 0, 0);
    name = " ";
    zeroTime.setHMS(0, 0, 0);
}

Timer::Timer(QTime time)
{
    endTime = time;
    name = " ";
    zeroTime.setHMS(0, 0, 0);
}

Timer::Timer(QTime time, QString timerName)
{
    endTime = time;
    name = timerName;
    zeroTime.setHMS(0, 0, 0);
}

Timer::~Timer()
{
    delete time;
}


QTime Timer::getEndTime()
{
    return endTime;
}

QTime Timer::getZeroTime()
{
    return zeroTime;
}

QString Timer::getName()
{
    return name;
}


void Timer::setEndTime(QTime newTime)
{
    endTime = newTime;
}

void Timer::setName(QString newName)
{
    name = newName;
}


void Timer::createTimer(QLabel* timeLeft)
{
    // Показати час
    time = timeLeft;
    start();
}

void Timer::pause()
{
    stopped = true;
}

void Timer::cont()
{
    stopped = false;
    start();
}


void Timer::updateTime()
{
    // Зворотній відлік по 1 мілісекунді
    endTime = endTime.addMSecs(-1);
    if (endTime == zeroTime || stopped)
    {
        time->setText(endTime.toString("hh:mm:ss.zzz"));
        stop();
    }
    else
    {
        time->setText(endTime.toString("hh:mm:ss.zzz"));
        QTimer::singleShot(1, this, SLOT(updateTime()));
    }
}

void Timer::start()
{
    QTimer::singleShot(0, this, SLOT(updateTime()));
}

void Timer::stop()
{
    timer.stop();
}

