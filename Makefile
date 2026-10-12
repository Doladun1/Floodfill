CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

CPPFLAGS := -MMD -MP 

TARGET = app
SOURCE = main.cpp maze.cpp
DEPS = maze.h export.h

all: build run

build: $(TARGET)
$(TARGET): $(SOURCE) $(DEPS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(@)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

