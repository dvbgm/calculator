# Используем официальный образ с GCC для сборки
FROM gcc:12.2.0 AS builder

# Устанавливаем зависимости (если нужны)
RUN apt-get update && \
    apt-get install -y \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

# Копируем исходный код в контейнер
WORKDIR /app
COPY . .

# Собираем проект
RUN make

# =============================================
# Второй этап: создаём минимальный образ для запуска
FROM ubuntu:22.04

# Устанавливаем зависимости для runtime (если нужны)
RUN apt-get update && \
    apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

# Копируем бинарники из builder-этапа
WORKDIR /app
COPY --from=builder /app/calculator_server .
COPY --from=builder /app/calculator_tests .

# Опционально: запуск тестов при сборке
RUN ./calculator_tests && echo "✅ Все тесты пройдены!"

# Открываем порт сервера
EXPOSE 8080

# Запускаем сервер
CMD ["./calculator_server"]
