#include "script.h"

/**
 * Логика функции для холодильника
 */
QVector<QVector<QString>> script::getFrige() {
    morning = {
        "Напоминание через приложение о продуктах с истекающим сроком годности.",
        "Автоматическое включение режима \"Быстрое охлаждение\" к утру для свежих напитков.",
        "Подсказки по здоровому питанию, исходя из содержимого холодильника."
    };
    day = {
        "Удаленный просмотр внутренних камер через приложение для проверки наличия продуктов.",
        "Уведомления на смартфон, если холодильник был оставлен открытым.",
        "Автоматическое переключение в энергосберегающий режим, если никого нет дома.",
    };
    evening = {
        "Предложения по рецептам на основе имеющихся ингредиентов.",
        "Включение режима \"Суперзаморозка\" для быстрой заморозки свежих продуктов.",
        "Интеграция с системами \"Умный дом\" для автоматической регулировки освещения при открытии дверей."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для кондиционера
 */
QVector<QVector<QString>> script::getAirConditioner() {
    // Implement the function logic here
    morning = {
        "Автоматическое включение кондиционера к назначенному времени пробуждения для создания комфортной температуры. ",
        "Регулировка температуры и режима работы по голосовой команде после пробуждения.",
        "Поддержание прохладной температуры в спальне утром, если ночью была жара."
    };
    day = {
        "Автоматическое поддержание заданной температуры и режима в дневное время в зависимости от времени суток и температуры снаружи.",
        "Удаленное управление кондиционером через приложение для создания комфортных условий к приходу домой.",
        "Режим энергосбережения/пониженной мощности в вашем отсутствии. ",
    };
    evening = {
        "Поддержание оптимальной температуры для комфортного отдыха и сна по расписанию или голосовой команде.",
        "Регулировка температуры для разных зон квартиры/дома.",
        "Ночной режим для снижения шума от внешнего блока кондиционера."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для камер
 */
QVector<QVector<QString>> script::getCameras() {
    // Implement the function logic here
    morning = {
        "Просмотр потокового видео с камер перед выходом из дома для проверки обстановки.",
        "Оповещения на смартфон при регистрации движения во дворе или у входа в дом.",
        "Автоматическое включение режима патрулирования по расписанию."
    };
    day = {
        "Дистанционный доступ к видео с камер через приложение для наблюдения за происходящим дома.",
        "Детекция событий - уведомления о срабатывании датчиков движения или открытии дверей/окон.",
        "Возможность управлять камерами удаленно - поворачивать, включать запись и т.д.",
    };
    evening = {
        "Переход камер в ночной режим по расписанию или команде.",
        "Включение режима охраны с полным циклическим обзором территории.",
        "Интеграция с системой \"Умный дом\" - запись видео при срабатывании тревоги, автовключение освещения."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для кофемашины
 */
QVector<QVector<QString>> script::getCoffeMachine() {
    // Implement the function logic here
    morning = {
        "Автоматический запуск приготовления кофе к заданному времени пробуждения.",
        "Приготовление кофе по голосовой команде после включения будильника или распознавания, что вы проснулись.",
        "Оповещение на смартфон о готовности утренней порции кофе."
    };
    day = {
        "Дистанционный запуск приготовления кофе через приложение перед возвращением домой.",
        "Голосовое управление для приготовления кофе без помощи рук.",
        "Предложение приготовить кофе при распознавании гостей камерами видеонаблюдения.",
    };
    evening = {
        "Автоматическое отключение кофемашины по расписанию или при распознавании ночного режима системой \"Умного дома\".",
        "Напоминание голосовым сообщением о необходимости выключить кофемашину, если она осталась включенной.",
        "Возможность приготовить декофеинизированный кофе вечером по команде."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для двери
 */
QVector<QVector<QString>> script::getDoor() {
    // Implement the function logic here
    morning = {
        "Автоматическое отпирание входной двери к назначенному времени подъема.",
        "Получение уведомления на смартфон, если дверь осталась незапертой при выходе из дома.",
        "Интеграция с охранной системой для разблокировки при отключении сигнализации."
    };
    day = {
        "Возможность удаленно открыть дверь курьеру или гостям через приложение.",
        "Автоматическое запирание двери через определенное время после открывания.",
        "Использование временных цифровых кодов для ограниченного доступа посторонних лиц.",
    };
    evening = {
        "Автоматическая блокировка всех дверей после определенного времени или с помощью геолокации.",
        "Ночной режим безопасности с усиленной блокировкой и оповещениями о попытках взлома.",
        "Интеграция с освещением для автоматического включения света при открывании двери."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для домофона
 */
QVector<QVector<QString>> script::getIntercom() {
    // Implement the function logic here
    morning = {
        "Автоматическое включение режима \"Уехал\" по расписанию или с помощью геолокации.",
        "Уведомления на смартфон о посетителях у входа с возможностью видео/аудио связи.",
        "Удаленное открытие калитки/двери для доставки утренней прессы/почты."
    };
    day = {
        "Запись событий - открытия калитки, нажатия кнопок вызова и т.д.",
        "Реагирование на уведомления о посетителях и разговор с ними через домофон.",
        "Удаленное управление механизмами разблокировки для впуска гостей или курьеров.",
    };
    evening = {
        "Переход в ночной режим по расписанию с усиленной детекцией движения.",
        "Автоматическое включение дополнительного освещения при появлении посетителей.",
        "Интеграция с системой \"Умного дома\" и охранной сигнализацией для защиты периметра."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для чайника
 */
QVector<QVector<QString>> script::getKettle() {
    // Implement the function logic here
    morning = {
        "Автоматическое кипячение воды к назначенному времени пробуждения.",
        "Интеграция с будильником - чайник начнет греть воду за несколько минут до сигнала.",
        "Голосовая команда для включения чайника перед выходом из спальни."
    };
    day = {
        "Дистанционное включение чайника через приложение, когда вы в пути домой.",
        "Кипячение воды по расписанию, например, для обеденного чая.",
        "Автоматическое отключение питания по достижении заданной температуры.",
    };
    evening = {
        "Функция отложенного старта для подогрева воды к определенному времени.",
        "Поддержание воды горячей перед сном при помощи режима ожидания.",
        "Интеграция с другими устройствами \"Умного дома\" для согласованных сценариев отдыха."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для света
 */
QVector<QVector<QString>> script::getLight() {
    // Implement the function logic here
    morning = {
        "Освещение включается постепенно и нарастает в течение 30 минут до времени пробуждения ",
        "Освещение за 15 минут до времени пробуждения включается приглушенный свет в ванной, на кухне и в коридоре",
        "Освещение в каждой комнате включается, когда активируется датчик движение"
    };
    day = {
        "Освещение регулируется в зависимости от освещения снаружи. чем ярче свет за окном, тем приглушеннее свет в квартире/доме.",
        "Свет движется за вами. датчики движения включают свет в той комнате где вы находитесь. Через какое то время свет в комнате, из которой вы вышли, выключается.",
        "Освещение зависит от штор/жалюзей. При закрытие штор/жалюзей свет включается или наоборот.",
    };
    evening = {
        "При наступлении сумерек освещение переключается на более мягкий режим, создавая более уютную атмосферу.",
        "Освещение имитирует нахождение других людей в комнатах, в которых нет человека. там будет иногда мигать приглушенный свет.",
        "В ночное время основной свет в спальне выключается и включаются ночники."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для выключателя
 */
QVector<QVector<QString>> script::getLightSwitch() {
    // Implement the function logic here
    morning = {
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет."
    };
    day = {
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет.",
    };
    evening = {
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет.",
        "Выключатель подсвечивается, когда на него не падает свет."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для замков
 */
QVector<QVector<QString>> script::getLocks() {
    // Implement the function logic here
    morning = {
        "Автоматическое отпирание входной двери по расписанию к определенному времени утром.",
        "Получение напоминания на смартфон, если дверь осталась незапертой при выходе из дома.",
        "Удаленная разблокировка замка, чтобы впустить домработницу или курьера с доставкой."
    };
    day = {
        "Отслеживание действий по запиранию/отпиранию в реальном времени через приложение.",
        "Использование цифровых временных кодов для предоставления гостям ограниченного доступа.",
        "Интеграция с охранной системой для автоматической разблокировки при срабатывании сигнализации.",
    };
    evening = {
        "Автоматическое запирание всех дверей после определенного времени или с помощью геолокации.",
        "Ночной режим безопасности с автоблокировкой замков после последнего запирания.",
        "Включение тревоги при попытке силового взлома замка."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для робота-пылесоса
 */
QVector<QVector<QString>> script::getRobotCleaner() {
    // Implement the function logic here
    morning = {
        "Запуск уборки по расписанию или голосовой команде перед выходом из дома, чтобы вернуться в чистое помещение.",
        "Сухая уборка только в коридоре, на кухне и в прихожей по утрам, чтобы не беспокоить спящих.",
        "Автоматический запуск при распознавании, что жильцы покинули дом."
    };
    day = {
        "Дистанционный запуск уборки через приложение, чтобы к приходу дома было чисто.",
        "Уборка только в гостиной, если зафиксировано присутствие людей в других комнатах.",
        "Функция автоматической уборки по расписанию во время вашего отсутствия.",
    };
    evening = {
        "Полная влажная уборка квартиры/дома после ужина.",
        "Напоминание голосовым сообщением о необходимости запустить уборку.",
        "Ночной режим для тихой уборки без нарушения сна."
    };
    return {morning, day, evening};
}

/**
 * Логика функции для системы охраны
 */
QVector<QVector<QString>> script::getSecuritySystem() {
    // Implement the function logic here
    morning = {
        "",
        "",
        ""
    };
    day = {
        "",
        "",
        "",
    };
    evening = {
        "",
        "",
        ""
    };
    return {morning, day, evening};
}

/**
 * Логика функции для умной колонки
 */
QVector<QVector<QString>> script::getSmartSpeaker() {
    // Implement the function logic here
    morning = {
        "",
        "",
        ""
    };
    day = {
        "",
        "",
        "",
    };
    evening = {
        "",
        "",
        ""
    };
    return {morning, day, evening};
}

/**
 * Логика функции для розетки
 */
QVector<QVector<QString>> script::getSocket() {
    // Implement the function logic here
    morning = {
        "",
        "",
        ""
    };
    day = {
        "",
        "",
        "",
    };
    evening = {
        "",
        "",
        ""
    };
    return {morning, day, evening};
}
