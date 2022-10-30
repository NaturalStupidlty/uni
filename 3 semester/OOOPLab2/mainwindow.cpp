#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtimersmenu.h"

#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // setTimerButton викликає timersMenu
    connect(ui->setTimerButton, SIGNAL(clicked(bool)), this, SLOT(timersMenu()));

    // pauseTimerButton призупиняє таймер
    connect(ui->pauseTimerButton, SIGNAL(clicked(bool)), this, SLOT(pauseTimer()));

    // continueTimerButton продовжує таймер
    connect(ui->continueTimerButton, SIGNAL(clicked(bool)), this, SLOT(continueTimer()));
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
    this->timer.setEndTime(menu.getEndTime());

    if (this->timer.getEndTime() != this->timer.getZeroTime())
    {
            timer.createTimer(ui->timerTime);
    }
    else
    {
        QMessageBox::warning(this, "Entered time is incorrect!", "Please, enter valid time for the timer");

    }
}

void MainWindow::pauseTimer()
{
    timer.pause();
}

void MainWindow::continueTimer()
{
    timer.cont();
}
