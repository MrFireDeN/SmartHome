# Умный Дом - Приложение на Qt

## Оглавление
- [Описание](#описание)
- [Структура проекта](#структура-проекта)
- [Основные функции](#основные-функции)
  - [Настройка профиля пользователя](#настройка-профиля-пользователя)
  - [Настройка времени](#настройка-времени)
  - [Управление устройствами и сценариями](#управление-устройствами-и-сценариями)
- [Как начать](#как-начать)
- [Зависимости](#зависимости)
- [Лицензия](#лицензия)
- [Титры](#титры)

## Описание
Приложение "Умный Дом" разработано с использованием фреймворка Qt. Оно предоставляет пользовательский интерфейс для управления различными аспектами "умного" дома, включая профили пользователей, настройки времени и управление устройствами.

## Структура проекта
Проект состоит из трех основных файлов:

- `mainwindow.ui`: XML-файл, описывающий пользовательский интерфейс приложения. Включает в себя элементы управления, такие как вкладки, кнопки, текстовые поля и другие виджеты.
- `mainwindow.cpp`: Исходный файл C++, содержащий логику работы главного окна приложения. Включает в себя инициализацию интерфейса, обработку событий и другую логику приложения.
- `mainwindow.h`: Заголовочный файл C++, содержащий объявление класса `MainWindow`, наследующего `QMainWindow`. Определяет структуру класса, включая его методы и свойства.

## Основные функции

### Настройка профиля пользователя
Позволяет пользователю ввести свое имя и выбрать свою принадлежность (студент, рабочий, пенсионер). Также предоставляет возможность настройки графика работы и выходных дней.

### Настройка времени
Пользователь может выбрать использование системного времени или установить время вручную. Время используется для определения приветствия в зависимости от времени суток.

### Управление устройствами и сценариями
Хотя в текущей версии проекта эта функциональность не реализована полностью, предусмотрены вкладки для управления устройствами и сценариями работы "умного" дома.

## Как начать
Для работы с проектом вам понадобится Qt Creator и компилятор, поддерживающий C++.

1. Откройте Qt Creator и импортируйте проект.
2. Скомпилируйте и запустите приложение.

## Зависимости
- Qt 5 или выше.

## Лицензия
Проект распространяется под лицензией MIT. Вы свободны использовать, изменять и распространять его на условиях этой лицензии.

## Титры

- **Денис Свиридов** - Разработчик кода | [GitHub](https://github.com/MrFireDeN)
- **Илья Подмосковнов** - Разработчик кода | [GitHub](https://github.com/rokosvlg)
- **Петр Березовский** - Специалист по документации | [GitHub](https://github.com/8RODOGAST8)
