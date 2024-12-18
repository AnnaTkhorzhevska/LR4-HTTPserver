# Dockerfile
FROM gcc:latest

# Створення робочої директорії
WORKDIR /app

# Копіювання вихідних файлів і Makefile.am
COPY src /app/src
COPY Makefile.am /app/Makefile.am
COPY configure.ac /app/configure.ac

# Генерація Makefile.in та Makefile
RUN aclocal && automake --add-missing && autoconf

# Збірка програми
RUN make

# Запуск сервера
CMD ["./app"]
