nQueens: Queen.o nQueens.o
	g++ -std=c++11 -g Queen.o nQueens.o -o nQueens
nQueens.o: Queen.h nQueens.cpp
	g++ -std=c++11 -g -c nQueens.cpp
Queen.o: Queen.h Queen.cpp
	g++ -std=c++11 -g -c Queen.cpp
valgrind: nQueens
	valgrind --leak-check=full --log-file="valgrind.txt" ./nQueens
clean:
	rm -f *.o
	rm nQueens
	rm *.txt
run: nQueens
	./nQueens