# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the executable file 
EXEC = zombies

# List of source files
SOURCES = main.cpp Zombie.cpp zombieHorde.cpp

# Object files replace the .cpp extension with .o
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

# Rule to link the program
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJECTS) $(EXEC)

# Rebuild the project
re: clean all

# Prevent conflicts with files of the same name and make's special built-in targets
.PHONY: all clean re
