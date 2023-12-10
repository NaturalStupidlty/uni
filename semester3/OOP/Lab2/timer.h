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
    QString getSound();
    QString getDefaultSound();
    QListWidgetItem* getInfo();
    bool isAlarm();
    bool isPaused();

    // Сетери
    void setEndTime(QTime newTime);
    void setLastUpdateTime(QTime newUpdateTime);
    void setTime(QString newTime);
    void setName(QString newName);
    void setSound(QString newSound);
    void setAlarm(bool alarm);
    void setPaused(bool stop);

private:
    // Інформація, що відображається
    QListWidgetItem* info;

    // Час
    QLabel* time;

    // Ім'я
    QLabel* name;

    QString sound;
    QString defaultSound = "qrc:/resource/sounds/sound.mp3";

    // Чи це будильник
    bool alarm;

    // Чи таймер зупинений
    bool paused = false;

    // Час закінчення таймера
    QTime endTime;

    // Час останнього оновлення
    QTime lastUpdateTime;
};

#endif // TIMER_H
