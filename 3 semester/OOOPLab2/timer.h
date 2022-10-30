#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QLabel>

class Timer : public QObject
{
    Q_OBJECT
public:
    // Конструктори
    Timer();
    Timer(QTime time);
    Timer(QTime time, QString timerName);

    // Деструктор
    ~Timer();



    // Часу залишилося
    QLabel* time;



    // Гетери
    QTime getEndTime();
    QTime getZeroTime();
    QString getName();

    // Сетери
    void setEndTime(QTime newTime);
    void setName(QString newName);

    // Додати новий таймер
    void createTimer(QLabel* timeLeft);

    // Призупинити таймер
    void pause();

    // Відновити таймер
    void cont();

private:
    // Чи таймер зупинений
    bool stopped = false;

    // Час закінчення таймера
    QTime endTime;

    // Назва таймера
    QString name;

    // Нульовий час
    // (потрібний для завершення роботи таймера)
    QTime zeroTime;

    // Таймер для відліку
    QTimer timer;

    // Почати таймер
    void start();

    // Зупинити таймер
    void stop();
public slots:


private slots:
    // Оновити час
    void updateTime();

};

#endif // TIMER_H
