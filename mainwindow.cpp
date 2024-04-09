
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupProfile();
    setupHomePage();
    setupSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupProfile() {
    name = ui->name->text();

    // Конекты на кнопки
    connect(ui->checkBoxAlwaysHome, &QCheckBox::clicked, this, [this](bool checked) {
        qDebug() << "Always Home: " << checked;
        ui->timeEditStartWorking->setEnabled(!checked);
        ui->timeEditStopWorking->setEnabled(!checked);
    });

    connect(ui->name, &QLineEdit::textChanged, this, [this]() {
        name = ui->name->text();
        qDebug() << "name: " << name;

        changeWelcome();
    });
}

void MainWindow::setupHomePage() {
    changeWelcome();
}



void MainWindow::setupSettings() {
    globalTime = ui->timeEditGlobalTime->time();

    connect(ui->checkBoxSystemTime, &QCheckBox::clicked, this, [this](bool checked) {
        ui->comboBoxWeekday->setEnabled(!checked);
        ui->timeEditGlobalTime->setEnabled(!checked);

        if (checked) {
            globalTime = QTime::currentTime();
        }
        else {
            globalTime = ui->timeEditGlobalTime->time();
        }

        changeWelcome();
    });

    connect(ui->timeEditGlobalTime, &QTimeEdit::timeChanged, this, [this]() {
        globalTime = ui->timeEditGlobalTime->time();

        changeWelcome();
    });
}

void MainWindow::changeWelcome() {
    QString welcome;
    int hour = globalTime.hour();

    if (hour >= 4 && hour <= 10) {
        welcome = "Доброе утро, " + name;
    } else if (hour > 10 && hour <= 16) {
        welcome = "Добрый день, " + name;
    } else if (hour > 16 && hour <= 22) {
        welcome = "Добрый вечер, " + name;
    } else {
        welcome = "Доброй ночи, " + name;
    }

    ui->labelWelcome->setText(welcome);
}

