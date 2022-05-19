Main: main.o BinaryTree.o BuildTree.o ReadFile.o

BinaryTree.o: BinaryTree.h
	g++ -std=c++11 BinaryTree.h

BuildTree.o: BuildTree.h
	g++ -std=c++11 BuildTree.h

ReadFile.o: ReadFile.h
	g++ -std=c++11 ReadFile.h

main.o: main.cpp
	g++ -std=c++11 main.cpp -o Main.out


clean:
	rm *.o -o Main.out
