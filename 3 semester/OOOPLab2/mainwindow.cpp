#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtimersmenu.h"
#include "timerinfo.h"

#include <QMessageBox>
#include <QGroupBox>
#include <QTimer>
#include <QTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Колір фону - чорний
    this->setStyleSheet("background-color: black;");

    this->ui->continueTimerButton->setStyleSheet("color: rgb(69,69,69)");
    this->ui->pauseTimerButton->setStyleSheet("color: rgb(69,69,69)");

    // поки нульовий таймер
    this->ui->timerTime->setText("00:00:00:000");

    // Для зберігання таймерів
    this->timersBox = new QGroupBox(tr("Regular timers list"));
    this->alarmsBox = new QGroupBox(tr("Alarms list"));

    this->scrollAlarms = new QScrollArea;
    this->scrollTimers = new QScrollArea;

    this->scrollAlarmsLayout = new QVBoxLayout;
    this->scrollTimersLayout = new QVBoxLayout;

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
    delete this->timersBox;
    delete this->alarmsBox;
    delete this->scrollAlarms;
    delete this->scrollTimers;
    delete this->scrollAlarmsLayout;
    delete this->scrollTimersLayout;
    for (size_t i = 0; i < timers.size(); i++)
    {
        delete this->timers[i];
    }
}

void MainWindow::timersMenu()
{
    // Створюємо меню
    addTimersMenu menu;
    menu.setModal(true);

    // Назад
    if (!menu.exec())
    {
        return;
    }

    // Встановлюємо інформацію про таймер
    QLabel* name = menu.getTimerName();
    Timer* timer = new Timer(menu.getEndTime());

    if (timer->getEndTime() != timer->getZeroTime())
    {
            timer->start();
            timer->info->setName(name->text());
            timer->info->setAlarm(menu.isAlarm());

            if (timer->info->isAlarm())
            {
                ui->alarmsList->addWidget(scrollAlarms);
                scrollAlarmsLayout->addWidget(timer->info->getName());
                scrollAlarmsLayout->addWidget(timer->info->getTime());

                scrollAlarmsLayout->setAlignment(Qt::AlignCenter);
                scrollAlarms->setMinimumWidth(ui->alarms->width());
                scrollAlarms->setMaximumWidth(ui->alarms->width());

                scrollAlarms->setLayout(scrollAlarmsLayout);
            }
            else
            {
                ui->regularTimersList->addWidget(scrollTimers);
                scrollTimersLayout->addWidget(timer->info->getName());
                scrollTimersLayout->addWidget(timer->info->getTime());

                scrollTimersLayout->setAlignment(Qt::AlignCenter);
                scrollTimers->setMinimumWidth(ui->timers->width());
                scrollTimers->setMaximumWidth(ui->timers->width());

                scrollTimers->setLayout(scrollTimersLayout);
            }
            this->timers.emplace_back(timer);
    }
    else
    {
        QMessageBox::warning(this, "Ти шо бем бем?", "Введений час не може бути рівним нулю");

    }
}

void MainWindow::selectTimer()
{
    this->ui->pauseTimerButton->setStyleSheet("color: red");
}

void MainWindow::pauseTimer()
{
    timers[0]->pause();
}

void MainWindow::continueTimer()
{
    timers[0]->cont();
}



