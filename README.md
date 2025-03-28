# Веб-калькулятор на C++ с REST API

![C++](https://img.shields.io/badge/C++-17-blue)
![Crow](https://img.shields.io/badge/Crow-1.0+-green)
![Docker](https://img.shields.io/badge/Docker-20.10%2B-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)

## Содержание
- [О проекте](#о-проекте)
- [Возможности](#возможности)
- [Требования](#требования)
- [Быстрый старт](#быстрый-старт)
- [Развертывание](#развертывание)
- [API документация](#api-документация)
- [Разработка](#разработка)
- [Тестирование](#тестирование)
- [Лицензия](#лицензия)

## О проекте

Веб-калькулятор с REST API, реализованный на современном C++ (стандарт 17). Проект демонстрирует:
- Создание веб-сервера на C++
- Организацию кода по принципам ООП
- Unit-тестирование
- Контейнеризацию с Docker
- Автоматизацию сборки с Makefile

## Возможности

- Все базовые арифметические операции (+, -, *, /)
- RESTful API с JSON-ответами
- Подробная обработка ошибок
- Unit-тесты с 100% покрытием логики
- Мультистейдж Docker-сборка
- Логирование запросов

## Требования

- Linux (рекомендуется Ubuntu 22.04+)
- Компилятор C++17 (g++ 9+ или clang 10+)
- CMake 3.12+
- Boost 1.71+
- Docker 20.10+ (опционально)

## Быстрый старт

### Локальная установка

1. Установите зависимости:
```bash
sudo apt update && sudo apt install -y build-essential cmake git libboost-dev libboost-system-dev
```

2. Установите Crow:
```bash
git clone https://github.com/CrowCpp/Crow.git
cd Crow
mkdir build && cd build
cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
sudo make install
```

3. Соберите проект:
```bash
git clone https://github.com/ваш-username/calculator-web.git
cd calculator-web
make build
```

4. Запустите сервер:
```bash
./bin/server
```

## Развертывание

### Docker

1. Соберите образ:
```bash
docker build -t calculator-web .
```

2. Запустите контейнер:
```bash
docker run -p 8080:8080 --rm calculator-web
```

## API документация

### Базовый URL
`http://localhost:8080`

### Endpoints

#### Вычисление выражения
```
GET /calculate
```

**Параметры:**
- `a` - первое число (float, обязательный)
- `b` - второе число (float, обязательный)
- `op` - операция (+, -, *, /, обязательный)

**Пример запроса:**
```bash
curl "http://localhost:8080/calculate?a=5&b=3&op=+"
```

**Успешный ответ:**
```json
{
  "result": 8
}
```

**Коды ошибок:**
- 400 - Неверные параметры
- 500 - Внутренняя ошибка сервера

## Разработка

### Структура проекта
```
calculator-web/
├── src/
│   ├── main.cpp          # Веб-сервер
│   ├── calculator.cpp    # Логика калькулятора
│   └── calculator.h      # Интерфейс калькулятора
├── tests/
│   └── test_calculator.cpp # Unit-тесты
├── Makefile              # Управление сборкой
├── Dockerfile            # Конфигурация Docker
└── README.md             # Документация
```

### Команды сборки
```bash
make build    # Сборка проекта
make test     # Запуск тестов
make clean    # Очистка артефактов
make run      # Сборка и запуск
```

## Тестирование

Проект включает полный набор unit-тестов:

```bash
make test
```

Тесты проверяют:
- Все арифметические операции
- Граничные случаи
- Обработку ошибок (деление на ноль)

Пример вывода:
```
===============================================================================
All tests passed (16 assertions in 5 test cases)
```

## Лицензия

Проект распространяется под лицензией MIT. Полный текст лицензии доступен в файле [LICENSE](LICENSE).
