#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>
#include <QLabel>
#include <QListWidgetItem>

class Timer : public QObject
{
    Q_OBJECT
public:
    // Конструктори
    Timer();
    Timer(QTime time, QString name, bool alarm);

    // Деструктор
    ~Timer();

    // Гетери
    QTime getEndTime();
    QTime getLastUpdateTime();
    QLabel* getTime();
    QLabel* getName();
    QListWidgetItem* getInfo();
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
    // Інформація, що відображається
    QListWidgetItem* info;

    // Час
    QLabel* time;

    // Ім'я
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
