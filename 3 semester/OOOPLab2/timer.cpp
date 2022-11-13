#include "timer.h"
#include <QMessageBox>

Timer::Timer()
{
    endTime.setHMS(0, 0, 0);
    zeroTime.setHMS(0, 0, 0);
    info = new TimerInfo("", "");
}

Timer::Timer(QTime time)
{
    endTime = time;
    zeroTime.setHMS(0, 0, 0);
    info = new TimerInfo("", "");
}

QTime Timer::getEndTime()
{
    return endTime;
}

QTime Timer::getZeroTime()
{
    return zeroTime;
}

void Timer::setEndTime(QTime newTime)
{
    endTime = newTime;
}

void Timer::start()
{
    QTimer::singleShot(0, this, SLOT(updateTime()));
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
    info->setTime(endTime.toString("hh:mm:ss.zzz"));
    if (endTime == zeroTime || stopped)
    {     
        stop();
    }
    else
    {
        QTimer::singleShot(1, this, SLOT(updateTime()));
    }
}

void Timer::stop()
{
    QMessageBox timerOver;
    timerOver.setWindowTitle("Час таймера вийшов.");
    timerOver.setText((this->info->getName())->text());
    timerOver.exec();
    this->timer.stop();
}

