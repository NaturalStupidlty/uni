#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPushButton* setTimerButton;
//    connect(setTimerButton, &QPushButton::clicked, this, &MainWindow::on_setTimerButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setTimerButton_clicked()
{
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot(42000)));
     timer->start(1);
}

void MainWindow::timerSlot(int endTime)
{
    for (QTime startTime = QTime(0, 0, 0, 0); startTime.msec() != endTime; startTime = startTime.addMSecs(1))
    {
        QString timerString = startTime.toString("hh : mm : ss : zzz");
        ui->timerTime->setText(timerString);
    }
}

