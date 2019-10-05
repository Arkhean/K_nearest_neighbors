all:
	g++ -c knn.cpp
	g++ -c test.cpp
	g++ -o test knn.o test.o
	./test
