# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
EXEC = unnecessary_violence

# Source files
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(EXEC)

# Link the program
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up objects and executable
clean:
	rm -f $(OBJ) $(EXEC)

# Rebuild the project
re: clean all

# Prevent Make from treating these names as files
.PHONY: all clean re
