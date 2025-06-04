TARGET = exec
TEST_TARGET = test_runner

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -O3

SRC_DIR = src
TEST_DIR = tests

SOURCES = $(wildcard *.cpp $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): main.o src/solomon_scanner.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp src/solomon_scanner.h
	$(CXX) $(CXXFLAGS) -c main.cpp

src/solomon_scanner.o: src/solomon_scanner.cpp src/solomon_scanner.h
	$(CXX) $(CXXFLAGS) -c src/solomon_scanner.cpp -o src/solomon_scanner.o

test: $(TEST_DIR)/solomon_scanner_test.o src/solomon_scanner.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $^

$(TEST_DIR)/solomon_scanner_test.o: $(TEST_DIR)/solomon_scanner_test.cpp src/solomon_scanner.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/solomon_scanner_test.cpp -o $(TEST_DIR)/solomon_scanner_test.o

clean:
	rm -f *.o src/*.o tests/*.o $(TARGET) $(TEST_TARGET)

run: clean all
	./$(TARGET)

run_test: test
	./$(TEST_TARGET)
