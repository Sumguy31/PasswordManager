CXX=g++
CXXFLAGS = -c -Wall


all: prog

.PHONY: clean clean-data test

prog: main.o account.o storage.o io.o
	$(CXX) -o snappass main.o account.o storage.o io.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

account.o: account.cpp
	$(CXX) $(CXXFLAGS) account.cpp

storage.o: storage.cpp
	$(CXX) $(CXXFLAGS) storage.cpp

io.o: io.cpp
	$(CXX) $(CXXFLAGS) io.cpp

clean:
	rm -rf *.o

clean-data:
	rm -rf *.o *.sp 

test:
	$(CXX) -o test-read io.cpp account.cpp storage.cpp test-read.cpp
