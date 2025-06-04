TARGET = exec

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -O3

SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJECTS) $(TARGET)

run: clean all
	./$(TARGET)