# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the executable file
EXEC = harl

# List of source files
SRC = main.cpp Harl.cpp

# Object files replace the .cpp extension with .o
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(EXEC)

# Rule to link the program
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build (removes object files)
clean:
	rm -f $(OBJ)

# Full clean (removes object files and executable)
fclean: clean
	rm -f $(EXEC)

# Rebuild the project (full clean followed by all)
re: fclean all

# Prevent conflicts with files of the same name and make's special built-in targets
.PHONY: all clean fclean re
