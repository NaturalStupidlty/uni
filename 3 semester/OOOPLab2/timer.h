#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>
#include <QLabel>

class Timer : public QObject
{
    Q_OBJECT
public:
    // Конструктори
    Timer();
    Timer(QTime time);

    // Деструктор
    ~Timer();

    // Гетери
    QTime getEndTime();
    QTime getLastUpdateTime();
    QLabel* getTime();
    QLabel* getName();
    bool isAlarm();
    bool isStopped();

    // Сетери
    void setEndTime(QTime newTime);
    void setLastUpdateTime(QTime newUpdateTime);
    void setTime(QString newTime);
    void setName(QString newName);
    void setAlarm(bool alarm);
    void setStopped(bool stop);

private:
    // Час, що відображається
    QLabel* time;

    // Ім'я, що відображається
    QLabel* name;

    // Чи це будильник
    bool alarm;

    // Чи таймер зупинений
    bool stopped = false;

    // Час закінчення таймера
    QTime endTime;

    // Час останнього оновлення
    QTime lastUpdateTime;
};

#endif // TIMER_H
