#ifndef TIMERINFO_H
#define TIMERINFO_H

#include <QWidget>
#include <QLabel>

class TimerInfo : public QWidget
{
    Q_OBJECT
public:
    explicit TimerInfo(QWidget *parent = nullptr);
    TimerInfo(QString time, QString name);
    ~TimerInfo();

    // Сетери
    void setTime(QString newTime);
    void setName(QString newName);
    void setAlarm(bool alarm);

    // Гетери
    QLabel* getTime();
    QLabel* getName();
    bool isAlarm();

private:
    // Час, що відображається
    QLabel* time;
    // Ім'я, що відображається
    QLabel* name;
    // Чи це будильник
    bool alarm;
};

#endif // TIMERINFO_H
