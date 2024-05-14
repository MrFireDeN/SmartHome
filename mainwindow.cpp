#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

// Конструктор главного окна
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Инициализация пользовательского интерфейса

    // Настройка различных частей интерфейса
    setupProfile();
    setupHomePage();
    setupSettings();
    setupThings();

    setupScript();

    //ui->dayScript_1->setStyleSheet("QTextBrowser { background-color: purple; }");
    //ui->dayScript_2->setStyleSheet("QTextBrowser { background-color: red; }");
    //ui->dayScript_3->setStyleSheet("QTextBrowser { background-color: green; }");
    //ui->dayScript_4->setStyleSheet("QTextBrowser { background-color: blue; }");
}

// Деструктор главного окна
MainWindow::~MainWindow()
{
    delete ui; // Освобождение ресурсов пользовательского интерфейса
}

// Настройка профиля пользователя
void MainWindow::setupProfile() {
    name = ui->name->text(); // Получение имени пользователя из текстового поля

    // Настройка поведения при включении/выключении чекбокса "Всегда дома"
    connect(ui->checkBoxAlwaysHome, &QCheckBox::clicked, this, [this](bool checked) {
        qDebug() << "Always Home: " << checked; // Логирование состояния чекбокса
        // Включение/выключение элементов управления временем работы в зависимости от состояния чекбокса
        ui->timeEditStartWorking->setEnabled(!checked);
        ui->timeEditStopWorking->setEnabled(!checked);
    });

    // Обновление имени пользователя и приветствия при изменении текста в поле ввода имени
    connect(ui->name, &QLineEdit::textChanged, this, [this]() {
        name = ui->name->text(); // Обновление имени пользователя
        qDebug() << "name: " << name; // Логирование нового имени

        changeWelcome(); // Обновление приветствия
    });
}

// Настройка домашней страницы
void MainWindow::setupHomePage() {
    changeWelcome(); // Инициализация приветствия на домашней странице
}

// Настройка настроек приложения
void MainWindow::setupSettings() {
    globalTime = ui->timeEditGlobalTime->time(); // Инициализация глобального времени

    // Настройка поведения при включении/выключении чекбокса "Системное время"
    connect(ui->checkBoxSystemTime, &QCheckBox::clicked, this, [this](bool checked) {
        // Включение/выключение элементов управления временем и днями недели
        ui->comboBoxWeekday->setEnabled(!checked);
        ui->timeEditGlobalTime->setEnabled(!checked);

        // Установка времени в зависимости от состояния чекбокса
        if (checked) {
            globalTime = QTime::currentTime(); // Текущее системное время
        }
        else {
            globalTime = ui->timeEditGlobalTime->time(); // Время, выбранное пользователем
        }

        changeWelcome(); // Обновление приветствия
    });

    // Обновление глобального времени и приветствия при изменении времени
    connect(ui->timeEditGlobalTime, &QTimeEdit::timeChanged, this, [this]() {
        globalTime = ui->timeEditGlobalTime->time(); // Обновление глобального времени

        changeWelcome(); // Обновление приветствия
    });

    //Настройка поведения при изменении времени на дорогу
    connect(ui->travelTime, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](){

    });
}
// Настройка вкладки устройства
void MainWindow::setupThings(){
    connect(ui->frige,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Холодильник
        changeScripts(scripts.getFrige(), checked, "Холодильник");
    });
    connect(ui->airConditioner,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Кондиционер
        changeScripts(scripts.getAirConditioner(), checked, "Кондиционер");
    });
    connect(ui->cameras,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Камеры
        changeScripts(scripts.getCameras(), checked, "Камеры");
    });
    connect(ui->coffeMachine,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Кофемашина
        changeScripts(scripts.getCoffeMachine(), checked, "Кофемашина");
    });
    connect(ui->door,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Дверь
        changeScripts(scripts.getDoor(), checked, "Дверь");
    });
    connect(ui->intercom,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Домофон
        changeScripts(scripts.getIntercom(), checked, "Домофон");
    });
    connect(ui->kettle,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Чайник
        changeScripts(scripts.getKettle(), checked, "Чайник");
    });
    connect(ui->light,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Свет
        changeScripts(scripts.getLight(), checked, "Свет");
    });
    connect(ui->lightSwitch,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Переключатель света
        changeScripts(scripts.getLightSwitch(), checked, "Переключатель света");
    });
    connect(ui->locks,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Замок
        changeScripts(scripts.getLocks(), checked, "Замок");
    });
    connect(ui->robotCleaner,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Робот пылесос
        changeScripts(scripts.getRobotCleaner(), checked, "Робот пылесос");
    });
    connect(ui->securitySystem,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Система безопасности
        changeScripts(scripts.getSecuritySystem(), checked, "Система безопасности");
    });
    connect(ui->smartSpeaker,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Умная колонка
        changeScripts(scripts.getSmartSpeaker(), checked, "Умная колонка");
    });
    connect(ui->socket,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Розетка
        changeScripts(scripts.getSocket(), checked, "Розетка");
    });

}
// Метод для настройки сценариев приложения
void MainWindow::setupScript() {
    areaMorning    = ui->scrollAreaMorningScript;
    areaDay        = ui->scrollAreaDayScript;
    areaEvening    = ui->scrollAreaEveningScript;

    for (int i = 0; i < 3; i++) {
        scriptTexts[0].append(addCard(layoutMorning, areaMorning));
        scriptTexts[1].append(addCard(layoutDay, areaDay));
        scriptTexts[2].append(addCard(layoutEvening, areaEvening));
    }
}

// Метод для обновления текста приветствия в зависимости от времени суток
void MainWindow::changeWelcome() {
    QString welcome; // Строка для хранения приветствия
    int hour = globalTime.hour(); // Получение текущего часа

    // Определение приветствия в зависимости от времени суток
    if (hour >= 4 && hour <= 10) {
        welcome = "Доброе утро, " + name;
    } else if (hour > 10 && hour <= 16) {
        welcome = "Добрый день, " + name;
    } else if (hour > 16 && hour <= 22) {
        welcome = "Добрый вечер, " + name;
    } else {
        welcome = "Доброй ночи, " + name;
    }

    // Установка текста приветствия в пользовательский интерфейс
    ui->labelWelcome->setText(welcome);
}

// Добавление карточки
QTextBrowser* MainWindow::addCard(QHBoxLayout* layout, QScrollArea* area) {
    QTextBrowser *script = new QTextBrowser();

    script->setText("");

    script->setMinimumWidth(area->minimumWidth()/3);
    script->setMaximumWidth(area->maximumWidth()/3);

    layout->addWidget(script);

    QWidget *areaWidget = new QWidget();
    areaWidget->setLayout(layout);

    area->setWidget(areaWidget);

    return script;
}

// Удаление карточки
void MainWindow::deleteCard(QHBoxLayout* layout, QScrollArea* area) {
    if (layout->count() > 0) {
        QLayoutItem* item = layout->takeAt(layout->count() - 1);
        if (item->widget()) {
            delete item->widget();
        }
        delete item;

        QWidget *areaWidget = new QWidget();
        areaWidget->setLayout(layout);

        area->setWidget(areaWidget);
    }
}

void MainWindow::setCardStyle(QTextBrowser* card, QString color) {
    card->setStyleSheet(QString("QTextBrowser { background-color: %1; }").arg(color));
}

// Метод изменения скриптов
void MainWindow::changeScripts(QVector<QVector<QString>> thingText, bool status, QString thingName) {
    for (int dayTime = 0; dayTime < 3; dayTime++) {
        for (int card = 0; card < 3; card++) {
            QTextBrowser* item = scriptTexts[dayTime][card];
            QString currentText = item->toPlainText();
            QString newText = thingName + ": " + thingText[dayTime][card];

            if (status) {
                currentText += newText + '\n';
                item->setText(currentText);
            }
            else {
                currentText.remove(newText + '\n');
                item->setText(currentText);
            }
        }
    }
}
