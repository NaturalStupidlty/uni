#ifndef ADDALARMSMENU_H
#define ADDALARMSMENU_H

#include <QDialog>
#include <QLabel>
#include <QTime>

namespace Ui {
class addAlarmsMenu;
}

class addAlarmsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit addAlarmsMenu(QWidget *parent = nullptr);
    ~addAlarmsMenu();

    // Гетери
    QTime getEndTime();
    QLabel* getTimerName();
    QString getTimerSound();

private slots:
    // Запуск таймерів
    void startTimers();

    // Знайти звук
    void findSound();

private:
    // Інтерфейс
    Ui::addAlarmsMenu *ui;

    // Обмеження на введення кількості годин
    const ulong maxHours = 23;
    // Обмеження на довжину ім'я таймера
    const uint maxTimerNameLenght = 24;
    // Кількість мілісекунд в добі
    const uint msecsInADay = 86400000;

    // Час завершення таймера
    QTime endTime;
    // Назва таймера
    QLabel* timerName;

    // Встановити endTime за даними, що
    // були введені в spinBoxes
    void setTime();
};

#endif // ADDALARMSMENU_H
