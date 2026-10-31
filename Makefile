CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

CPPFLAGS := -MMD -MP 

TARGET = app
SOURCE = main.cpp maze.cpp
DEPS = maze.h export.h print.h

all: build run gui

build: $(TARGET)
$(TARGET): $(SOURCE) $(DEPS)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(@)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

gui:	
	python3 main.py

