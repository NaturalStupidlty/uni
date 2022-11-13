#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include "timerinfo.h"

class Timer : public QObject
{
    Q_OBJECT
public:
    // Конструктори
    Timer();
    Timer(QTime time);

    // Деструктор
    ~Timer(){delete info;};

    // Гетери
    QTime getEndTime();
    QTime getZeroTime();

    // Сетери
    void setEndTime(QTime newTime);

    // Додати новий таймер
    void start();

    // Чи таймер зупинений
    bool stopped = false;

    // Призупинити таймер
    void pause();

    // Відновити таймер
    void cont();

    // TODO: може через гетер
    // інформація про таймер
    TimerInfo* info;

private:
    // Час закінчення таймера
    QTime endTime;

    // Нульовий час
    // (потрібний для завершення роботи таймера)
    QTime zeroTime;

    // Таймер для відліку
    QTimer timer;

    // Зупинити таймер
    void stop();
public slots:


private slots:
    // Оновити час
    void updateTime();

};

#endif // TIMER_H
