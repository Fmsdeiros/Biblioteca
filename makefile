all:
	@echo make exe para compilar 

exe:
	@g++ -std=c++11 -Wall -pedantic -g -O0 src/*.cpp -o bin/exe


