# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# File names
SRC = main.cpp math.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program

# Default target to compile and link
all: $(EXEC)

# Rule to link object files into the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Rule to compile .cpp to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(EXEC)

# Rebuild everything
rebuild: clean all
