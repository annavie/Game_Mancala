# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Source files
SOURCES = Observer.cpp main.cpp gameController.cpp player.cpp gameState.cpp Board.cpp view.cpp 

# Object files (replace .cpp with .o for each file)
OBJECTS = $(SOURCES:.cpp=.o)

# Output program name
TARGET = programName

# Default rule to compile and link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile each .cpp file into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)
