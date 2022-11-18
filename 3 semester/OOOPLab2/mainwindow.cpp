#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addmenu.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);

    // Колір фону - чорний
    this->setStyleSheet("background-color: black;");

    // Колір кнопок
    this->ui->continueTimerButton->setStyleSheet("color: rgb(69,69,69)");
    this->ui->pauseTimerButton->setStyleSheet("color: rgb(69,69,69)");

    // Поки нульовий таймер
    this->ui->timerTime->setText("00:00:00:000");

    // Для зберігання таймерів
    this->timersLayout = new QVBoxLayout;
    this->alarmsLayout = new QVBoxLayout;

    this->alarmsLayout->setAlignment(Qt::AlignCenter);
    this->timersLayout->setAlignment(Qt::AlignCenter);

    this->timers.start();

    // setTimerButton викликає timersMenu
    connect(this->ui->setTimerButton, SIGNAL(clicked(bool)), this, SLOT(timersMenu()));

    // pauseTimerButton призупиняє таймер
    connect(this->ui->pauseTimerButton, SIGNAL(clicked(bool)), this, SLOT(pauseTimer()));

    // continueTimerButton продовжує таймер
    connect(this->ui->continueTimerButton, SIGNAL(clicked(bool)), this, SLOT(continueTimer()));
}

MainWindow::~MainWindow()
{
    delete this->ui;
    delete this->timersLayout;
    delete this->alarmsLayout;
}

void MainWindow::timersMenu()
{
    // Створюємо меню
    AddMenu menu;
    menu.setModal(true);
    // Назад
    if (!menu.exec())
    {
        return;
    }

    // Створюємо таймер
    Timer* timer = new Timer(menu.getEndTime());
    if (timer->getEndTime() != this->timers.getZeroTime())
    {
            QLabel* name = menu.getTimerName();
            timer->setName(name->text());
            timer->setAlarm(menu.isAlarm());

            this->timers.add(timer);

            if (timer->isAlarm())
            {
//                this->ui->alarmsList->setItemWidget()
//                this->ui->alarmsList->addItem(timer->getName()->text());
//                this->ui->alarmsList->addItem(timer->getTime()->text());
                this->alarmsLayout->addWidget(timer->getName());
                this->alarmsLayout->addWidget(timer->getTime());
                this->ui->alarmsList->setLayout(alarmsLayout);
            }
            else
            {
//                this->ui->timersList->addItem(timer->getName()->text());
//                this->ui->timersList->addItem(timer->getTime()->text());
                this->timersLayout->addWidget(timer->getName());
                this->timersLayout->addWidget(timer->getTime());
                this->ui->timersList->setLayout(timersLayout);
            }
    }
    else
    {
        QMessageBox::warning(this, "Ти шо бем бем?", "Введений час не може бути рівним нулю");

    }
}

void MainWindow::selectTimer()
{
    this->timers.setSelectedTimer(0);
    this->ui->pauseTimerButton->setStyleSheet("color: red");
}

void MainWindow::pauseTimer()
{
    this->timers.pause();
}

void MainWindow::continueTimer()
{
    this->timers.cont();
}
