# Веб-калькулятор на C++ с Docker

## О проекте
Это веб-приложение калькулятора, реализованное на C++ с использованием микрофреймворка Crow. Проект включает:
- HTTP API для выполнения арифметических операций
- Автоматизированную сборку через Makefile
- Docker-образ с мультистейдж сборкой
- Юнит-тесты для проверки корректности вычислений

## Требования
- Linux (рекомендуется Ubuntu 22.04)
- Docker (версия 20.10+)
- Git (для клонирования репозитория)
- libboost-dev и libboost-system-dev

## Установка

### 1. Клонирование репозитория
```bash
git clone https://github.com/dvbgm/calculator.git
cd calculator-web
```

### 2. Установка зависимостей
```bash
sudo apt update
sudo apt install -y build-essential make g++ git docker.io libboost-dev libboost-system-dev
```

## Сборка и запуск

### Локальная сборка
```bash
make build      # Сборка проекта
./bin/server   # Запуск сервера
```

### Сборка и запуск в Docker
```bash
docker build -t calculator-web .
docker run -p 8080:8080 --rm calculator-web
```

## Использование API

Сервер предоставляет единственный endpoint:

```
GET /calculate?a={number}&b={number}&op={operation}
```

### Параметры:
- `a` - первое число (float)
- `b` - второе число (float)
- `op` - операция (поддерживаются +, -, *, /)

### Примеры запросов:

1. Через браузер:
```
http://localhost:8080/calculate?a=5&b=3&op=+
```

2. Через curl:
```bash
curl "http://localhost:8080/calculate?a=10&b=2&op=/"
```

3. Через Postman:
- Метод: GET
- URL: `http://localhost:8080/calculate?a=8&b=4&op=*`

### Пример ответа:
```json
{"result": 12}
```

## Тестирование

Для запуска юнит-тестов:
```bash
make test
```

Тесты проверяют:
- Все базовые арифметические операции
- Обработку деления на ноль
- Корректность возвращаемых значений

## Структура проекта
```
calculator-web/
├── src/
│   ├── main.cpp          # Веб-сервер (Crow)
│   ├── calculator.cpp    # Логика калькулятора
│   └── calculator.h      # Заголовочный файл
├── tests/
│   └── test_calculator.cpp # Юнит-тесты
├── Makefile              # Автоматизация сборки
├── Dockerfile            # Конфигурация Docker
└── README.md             # Инструкции
```

## Особенности реализации
1. **Безопасность**:
   - Контейнер запускается от непривилегированного пользователя
   - Обработка ошибок ввода
   - Защита от переполнения буфера

2. **Оптимизация**:
   - Мультистейдж сборка в Docker
   - Минимальный образ (~80MB)

3. **Тестирование**:
   - Юнит-тесты для всех операций
   - Проверка граничных случаев

## Возможные ошибки и решения
| Ошибка | Причина | Решение |
|--------|---------|---------|
| 400 Bad Request | Неверные параметры | Проверить формат запроса |
| 400 Calculation Error | Деление на ноль | Проверить значение b |
| 404 Not Found | Неправильный URL | Использовать /calculate |

## Лицензия
Проект распространяется под лицензией MIT.
