all: prime.exec

prime.exec: main.cpp
	g++ -o prime.exec main.cpp -std=c++11 -O3
clean:
	rm prime.exec example.bin example.txt 

