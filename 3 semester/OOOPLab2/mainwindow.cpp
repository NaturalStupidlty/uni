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

    // Сховати скрол бари
    this->ui->verticalScrollBar->setHidden(true);
    this->ui->verticalScrollBar_2->setHidden(true);

    // поки нульовий таймер
    this->ui->timerTime->setText("00:00:00:000");

    // Бокси для зберігання таймерів
    this->timersBox = new QGroupBox(tr("Regular timers list"));
    this->alarmsBox = new QGroupBox(tr("Alarms list"));

    this->timersBox->setMaximumHeight(ui->verticalScrollBar_2->maximumHeight());

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
    delete timersBox;
    delete alarmsBox;
    for (size_t i = 0; i < timers.size(); i++)
    {
        delete timers[i];
    }
}

void MainWindow::timersMenu()
{
    // Створюємо меню
    addTimersMenu menu;
    menu.setModal(true);
    menu.exec();

    int n = menu.getNumberOfTimers();
    QLabel* name = menu.getTimerName();

    for (int i = 0; i < n; i++)
    {
        // Встановлюємо час завершення таймера
        Timer* timer = new Timer(menu.getEndTime());
        if (timer->getEndTime() != timer->getZeroTime())
        {
                timer->start();
                timer->info->setName(name->text());
                timer->info->setAlarm(menu.isAlarm());

                QGroupBox* newBox = new QGroupBox();
                QVBoxLayout* newBoxLayout = new QVBoxLayout;

                //newBox->setStyleSheet("background-color: black;");

                newBoxLayout->addWidget(timer->info->getName());
                newBoxLayout->addWidget(timer->info->getTime());
                newBox->setLayout(newBoxLayout);

                if (timer->info->isAlarm())
                {
                    this->ui->verticalScrollBar->show();
                    ui->alarmsList->addWidget(newBox);
                    newBox->setMaximumWidth(this->ui->timers->width());
                }
                else
                {
                    this->ui->verticalScrollBar_2->show();
                    ui->regularTimersList->addWidget(newBox);
                    newBox->setMaximumWidth(this->ui->alarms->width());
                }
                this->timers.emplace_back(timer);
        }
        else
        {
            QMessageBox::warning(this, "Ти шо бем бем?", "Введений час не може бути рівним нулю");

        }
    }
}

void MainWindow::pauseTimer()
{
    timers[0]->pause();
}

void MainWindow::continueTimer()
{
    timers[0]->cont();
}



