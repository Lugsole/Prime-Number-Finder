all: prime.exec

prime.exec: main.cpp
	g++ -o prime.exec main.cpp -std=c++11
clean:
	rm hello.o hello.exe