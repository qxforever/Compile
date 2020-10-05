FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN g++ -Wall -Wextra -std=c++14 -O2 -fsanitize=address test.c -o program
RUN chmod +x program
