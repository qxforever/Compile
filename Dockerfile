FROM gcc:10
WORKDIR /Compile/
COPY ./* ./
RUN g++ -std=c++14 -O2 test.cpp -o test
RUN chmod +x test
