FROM gcc:latest

WORKDIR /app

# Скопіювати файли
COPY src /app/src
COPY Makefile /app/Makefile

# Зібрати програму
RUN make

# Запустити сервер
CMD ["./app"]
