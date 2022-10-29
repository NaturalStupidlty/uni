#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtimersmenu.h"

#include <QMessageBox>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");

    // Нульовий час 00:00:00
    zeroTime.setHMS(0, 0, 0);

    // setTimerButton викликає timersMenu
    connect(ui->setTimerButton, SIGNAL(clicked()), this, SLOT(timersMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timersMenu()
{
    // Створюємо меню
    addTimersMenu menu;
    menu.setModal(true);
    menu.exec();

    // Встановлюємо час завершення таймера
    endTime = menu.getEndTime();
    if (endTime != zeroTime)
    {
            addTimers();
    }
    else
    {
        QMessageBox::warning(this, "Entered time is incorrect!", "Please, enter valid time for the timer");

    }
}

void MainWindow::addTimers()
{
    // Показати час
    QTimer::singleShot(0, this, SLOT(displayTime()));
}

void MainWindow::displayTime()
{
    // Зворотній відлік по 1 мілісекунді
    endTime = endTime.addMSecs(-1);
    if (endTime == zeroTime)
    {
        ui->timerTime->setText(endTime.toString("hh:mm:ss.zzz"));
        stopTimer();
    }
    else
    {
        ui->timerTime->setText(endTime.toString("hh:mm:ss.zzz"));
        QTimer::singleShot(1, this, SLOT(displayTime()));
    }
}


void MainWindow::stopTimer()
{
    // Зупиняємо
    timer.stop();
}
