FROM ubuntu:22.04 AS builder

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    g++ \
    libboost-all-dev \
    libpthread-stubs0-dev \
    git \
    libasio-dev && \
    rm -rf /var/lib/apt/lists/*
#build-essential cmake g++ libboost-all-dev libpthread-stubs0-dev git
WORKDIR /app
COPY . .

RUN make clean && make

#stage 2
FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y \
    libboost-system1.74 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /app/app .

EXPOSE 8080
CMD ["./app"]
