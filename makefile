CXX = g++ -std=c++0x

CXXFLAGS = -Wall -g -O3
PROGS = tsp

tsp:  TSP.o fileFilter.o graph.o point.o
	$(CXX) $(CXXFLAGS) -o tsp TSP.o fileFilter.o graph.o point.o

TSP.o: TSP.cpp fileFilter.h graph.h point.h
	$(CXX) $(CXXFLAGS) -c TSP.cpp

fileFilter.o: fileFilter.h

graph.o: graph.h

point.o: point.h

clean:
	rm -f $(PROGS) *.o *~
