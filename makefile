all: imgProcess.o 
		g++ imgProcess.cpp 

process: main.o

main.o: imgProcess.cpp
		g++ -c imgProcess.cpp

clean:
		rm -rf *o process