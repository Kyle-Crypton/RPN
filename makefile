RPN: main.o function.o
	g++ main.o function.o -o RPN

main.o: main.cpp
	g++ -c main.cpp

function.o: function.cpp
	g++ -c function.cpp

