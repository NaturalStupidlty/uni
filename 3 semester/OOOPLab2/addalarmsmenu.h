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

private slots:
    // Запуск таймерів
    void startTimers();

private:
    // Інтерфейс
    Ui::addAlarmsMenu *ui;

    // Обмеження на введення кількості годин
    const ulong maxHours = 23;
    const uint maxTimerNameLenght = 24;

    // Час завершення таймера
    QTime endTime;
    // Назва таймера
    QLabel* timerName;

    // Встановити endTime за даними, що
    // були введені в spinBoxes
    void setTime();
};

#endif // ADDALARMSMENU_H
