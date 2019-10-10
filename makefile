all: knn.o test.co
	g++ -o test knn.o test.o
	./test

knn.o: knn.cpp knn.hpp
	g++ -c knn.cpp
test.o: test.cpp
	g++ -c test.cpp

clean:
	rm *.o test
