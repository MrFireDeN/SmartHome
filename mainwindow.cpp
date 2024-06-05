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
    setupSettings();
    setupThings();
    setupScript();
    setupHomePage();
    updateScripts();
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

        updateScripts();
        changeWelcome();
    });

    // Обновление имени пользователя и приветствия при изменении текста в поле ввода имени
    connect(ui->name, &QLineEdit::textChanged, this, [this]() {
        name = ui->name->text(); // Обновление имени пользователя
        qDebug() << "name: " << name; // Логирование нового имени

        changeWelcome(); // Обновление приветствия
    });

    connect(ui->timeEditStartWorking, &QTimeEdit::timeChanged, this, [this]() {
        changeWelcome(); // Обновление приветствия
    });

    connect(ui->timeEditStopWorking, &QTimeEdit::timeChanged, this, [this]() {
        changeWelcome(); // Обновление приветствия
    });

    connect(ui->spinBoxGetReady, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value){
        changeWelcome();
    });
}

// Настройка домашней страницы
void MainWindow::setupHomePage() {
    changeWelcome(); // Инициализация приветствия на домашней странице
}

// Настройка настроек приложения
void MainWindow::setupSettings() {
    globalTime = ui->timeEditGlobalTime->time(); // Инициализация глобального времени

    // Массив указателей на чекбоксы по дням недели
    weekDayCheckBoxes = {
        ui->checkBoxMon,  // Понедельник
        ui->checkBoxTues, // Вторник
        ui->checkBoxWed,  // Среда
        ui->checkBoxThurs,// Четверг
        ui->checkBoxFri,  // Пятница
        ui->checkBoxSat,  // Суббота
        ui->checkBoxSun   // Воскресенье
    };

    // Настройка поведения при включении/выключении чекбокса "Системное время"
    connect(ui->checkBoxSystemTime, &QCheckBox::clicked, this, [this](bool checked) {
        // Включение/выключение элементов управления временем и днями недели
        ui->comboBoxWeekday->setEnabled(!checked);
        ui->timeEditGlobalTime->setEnabled(!checked);

        // Установка времени в зависимости от состояния чекбокса
        if (checked) {
            globalTime = QTime::currentTime(); // Текущее системное время
            weekday = QDate::currentDate().dayOfWeek()-1;
        }
        else {
            globalTime = ui->timeEditGlobalTime->time(); // Время, выбранное пользователем
            weekday = ui->comboBoxWeekday->currentIndex();
        }

        updateScripts();
        changeWelcome(); // Обновление приветствия
    });

    connect(ui->comboBoxWeekday, &QComboBox::currentIndexChanged, this, [this](int index) {
        weekday = ui->comboBoxWeekday->currentIndex();
        updateScripts();
        changeWelcome(); // Обновление приветствия
    });

    // Обновление глобального времени и приветствия при изменении времени
    connect(ui->timeEditGlobalTime, &QTimeEdit::timeChanged, this, [this]() {
        globalTime = ui->timeEditGlobalTime->time(); // Обновление глобального времени

        changeWelcome(); // Обновление приветствия
    });

    //Настройка поведения при изменении времени на дорогу
    connect(ui->travelTime, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value){
        changeWelcome();
    });

    connect(ui->spinBoxTemp, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value){
        changeWelcome(); // Обновление приветствия
    });


    connect(ui->spinBoxComfTemp, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value){
        changeWelcome(); // Обновление приветствия
    });
}
// Настройка вкладки устройства
void MainWindow::setupThings(){
    connect(ui->frige,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Холодильник
        changeScriptsText(scripts.getFrige(), checked, "Холодильник");
    });
    connect(ui->airConditioner,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Кондиционер
        changeScriptsText(scripts.getAirConditioner(), checked, "Кондиционер");
    });
    connect(ui->cameras,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Камеры
        changeScriptsText(scripts.getCameras(), checked, "Камеры");
    });
    connect(ui->coffeMachine,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Кофемашина
        changeScriptsText(scripts.getCoffeMachine(), checked, "Кофемашина");
    });
    connect(ui->door,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Дверь
        changeScriptsText(scripts.getDoor(), checked, "Дверь");
    });
    connect(ui->intercom,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Домофон
        changeScriptsText(scripts.getIntercom(), checked, "Домофон");
    });
    connect(ui->kettle,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Чайник
        changeScriptsText(scripts.getKettle(), checked, "Чайник");
    });
    connect(ui->light,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Свет
        changeScriptsText(scripts.getLight(), checked, "Свет");
    });
    connect(ui->lightSwitch,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Переключатель света
        changeScriptsText(scripts.getLightSwitch(), checked, "Переключатель света");
    });
    connect(ui->locks,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Замок
        changeScriptsText(scripts.getLocks(), checked, "Замок");
    });
    connect(ui->robotCleaner,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Робот пылесос
        changeScriptsText(scripts.getRobotCleaner(), checked, "Робот пылесос");
    });
    connect(ui->securitySystem,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Система безопасности
        changeScriptsText(scripts.getSecuritySystem(), checked, "Система безопасности");
    });
    connect(ui->smartSpeaker,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Умная колонка
        changeScriptsText(scripts.getSmartSpeaker(), checked, "Умная колонка");
    });
    connect(ui->socket,&QCheckBox::stateChanged,this,[this](bool checked){ // Устройство: Розетка
        changeScriptsText(scripts.getSocket(), checked, "Розетка");
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

    for (int i = 0; i < 3; i++) {
        scriptTexts[i][0]->setText("<b>Рабочий</b><br>");
        scriptTexts[i][1]->setText("<b>Выходной</b><br>");
        scriptTexts[i][2]->setText("<b>Домашний</b><br>");
    }

    for (int dayTime = 0; dayTime < scriptTexts.size(); ++dayTime) {
        for (int card = 0; card < scriptTexts[dayTime].size(); ++card) {
            CustomTextBrowser* textBrowser = scriptTexts[dayTime][card];
            connect(textBrowser, &CustomTextBrowser::clicked, this, [this, dayTime, card]() {
                qDebug() << "Кликнуто в scriptTexts[" << dayTime << "][" << card << "]";

                QVector<CustomTextBrowser*> items = scriptTexts[dayTime];
                for (int i = 0; i < items.size(); ++i) {
                    if (i != card) {
                        setCardStyle(items[i], "none");
                        items[i]->setSelected(false);
                    }
                    else {
                        setCardStyle(items[card], "green");
                        items[card]->setSelected(true);
                    }
                    changeWelcome();
                }
            });
        }
    }
}

// Метод для расчёта времени установки будильника
QString MainWindow::calculateClock() {
    // Время чтобы собраться, в минутах
    int gettingReadyMinutes = ui->spinBoxGetReady->value();

    // Получаем время выхода
    QDateTime goOutTime = ui->timeEditStartWorking->dateTime();

    // Конвертируем время выхода в минуты
    int goOutMinutes = goOutTime.time().hour() * 60 + goOutTime.time().minute();

    // Добавляем время на дорогу и на сборы
    int totalTravelMinutes = ui->travelTime->value() + gettingReadyMinutes;

    // Вычисляем время установки будильника в минутах
    int alarmMinutes = goOutMinutes - totalTravelMinutes;
    while (alarmMinutes < 0) {
        alarmMinutes += 24 * 60; // Корректируем для отрицательных значений, добавляя сутки в минутах
    }

    // Преобразуем минуты в часы и минуты
    int alarmHours = alarmMinutes / 60;
    alarmMinutes %= 60;

    // Форматируем время будильника с ведущими нулями
    QString alarmTime = QString("%1:%2")
                            .arg(alarmHours, 2, 10, QChar('0'))
                            .arg(alarmMinutes, 2, 10, QChar('0'));

    return alarmTime;
}


// метод для проверки текущего дня недели(будний или выходной)
bool MainWindow::isWorkDay(){
    return !(isWeekend() || isHomeday());
}

bool MainWindow::isWeekend(){
    return weekDayCheckBoxes[weekday]->isChecked();
}

bool MainWindow::isHomeday(){
    return ui->checkBoxAlwaysHome->isChecked();
}

// Метод для обновления текста приветствия в зависимости от времени суток
void MainWindow::changeWelcome() {
    QString welcome; // Строка для хранения приветствия
    int hour = globalTime.hour(); // Получение текущего часа
    int temp = ui->spinBoxTemp->value(); // Получение текущей температуры
    int comftemp = ui->spinBoxComfTemp->value();

    CustomTextBrowser* item;
    QString maintext;
    QString clockTime = "";

    if(isWorkDay())
        clockTime = "Будильник установлен на: " + calculateClock();

    maintext += clockTime + "\n";
    // Определение приветствия в зависимости от времени суток
    if (hour >= 4 && hour <= 10) {
        welcome = "Доброе утро, " + name;

        for (int card = 0; card < scriptTexts[0].size(); ++card) {
            item = scriptTexts[0][card];
            if (item->isSelected())
                maintext += item->toPlainText();
        }

    } else if (hour > 10 && hour <= 16) {
        welcome = "Добрый день, " + name;

        for (int card = 0; card < scriptTexts[1].size(); ++card) {
            item = scriptTexts[1][card];
            if (item->isSelected())
                maintext += item->toPlainText();
        }

    } else if (hour > 16 && hour <= 22) {
        welcome = "Добрый вечер, " + name;

        for (int card = 0; card < scriptTexts[2].size(); ++card) {
            item = scriptTexts[2][card];
            if (item->isSelected())
                maintext += item->toPlainText();
        }

    } else {
        welcome = "Доброй ночи, " + name;

        maintext += "Дом спит)";
    }

    QString climat = scripts.getClimat(temp, comftemp);
    if (!climat.isEmpty())
        maintext += "\n" + climat;


    // Установка текста приветствия в пользовательский интерфейс
    ui->labelWelcome->setText(welcome);
    ui->textBrowserWelcome->setText(maintext);
}

// Добавление карточки
CustomTextBrowser* MainWindow::addCard(QHBoxLayout* layout, QScrollArea* area) {
    CustomTextBrowser *script = new CustomTextBrowser();

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

void MainWindow::setCardStyle(CustomTextBrowser* card, QString color) {
    card->setStyleSheet(QString("QTextBrowser { background-color: %1; }").arg(color));
}

// Метод изменения скриптов
void MainWindow::changeScriptsText(QVector<QVector<QString>> thingText, bool status, QString thingName) {
    for (int dayTime = 0; dayTime < 3; dayTime++) {
        for (int card = 0; card < 3; card++) {
            CustomTextBrowser* item = scriptTexts[dayTime][card];
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
            changeWelcome();
        }
    }
}

void MainWindow::updateScripts() {
    int scriptType = 0;

    if (isWeekend()) {
        scriptType = 1;
    } else if (isHomeday()) {
        scriptType = 2;
    }

    for (int dayTime = 0; dayTime < scriptTexts.size(); ++dayTime) {
        scriptTexts[dayTime][scriptType]->clicked();
    }
}
