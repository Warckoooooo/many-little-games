# Compiler and compilation flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directory containing the source files
SRC_DIR = src

# List of source files in the SRC_DIR
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/guessthenumber.cpp $(SRC_DIR)/crontab.cpp $(SRC_DIR)/tictactoe.cpp

# List of object files corresponding to the source files
OBJ = $(SRC:.cpp=.o)

# The name of the final executable
TARGET = games

# The default target that builds the executable
all: $(TARGET)

# Rule to create the executable from the object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Rule to clean up the build: remove object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)
