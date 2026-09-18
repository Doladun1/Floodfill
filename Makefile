CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = app
SOURCE = main.cpp

all: build run

build: $(TARGET) 
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

