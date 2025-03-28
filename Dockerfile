# === Этап сборки ===
FROM ubuntu:22.04 as builder

RUN apt update && apt install -y \
    build-essential \
    make \
    g++ \
    libboost-dev \
    libboost-system-dev \
    catch2

WORKDIR /app
COPY . .

RUN make build

# === Финальный образ ===
FROM ubuntu:22.04

RUN apt update && apt install -y libboost-system-dev && \
    useradd -m appuser && \
    mkdir -p /app && \
    chown -R appuser:appuser /app

WORKDIR /app
COPY --from=builder /app/bin/server .

USER appuser

EXPOSE 8080
CMD ["./server"]
