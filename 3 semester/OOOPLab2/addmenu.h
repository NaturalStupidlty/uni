#ifndef ADDMENU_H
#define ADDMENU_H

#include <QDialog>
#include <QTime>
#include <QLabel>

namespace Ui {
class AddMenu;
}

class AddMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddMenu(QWidget *parent = nullptr);
    ~AddMenu();

    // Гетери
    QTime getEndTime();
    QLabel* getTimerName();
    bool isAlarm();

private slots:
    // Додавання таймера
    void addTimer();

    //Додавання будильника
    void addAlarm();

private:
    // Інтерфейс
    Ui::AddMenu *ui;

    // Час завершення таймера
    QTime endTime;

    // Назва таймера
    QLabel* timerName;

    // Чи це будильник
    bool alarm;
};

#endif // ADDMENU_H
