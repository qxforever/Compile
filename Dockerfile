FROM gcc:10
WORKDIR /Compile/
COPY ./* ./
RUN g++ -Wall -Wextra -std=c++14 -O2 -fsanitize=address test.cpp -o program
RUN chmod +x program
