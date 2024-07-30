# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the executable name
NAME = fixed_point

# List of source files
SRC = main.cpp Fixed.cpp

# Object files replace the .cpp extension with .o
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build (removes object files)
clean:
	rm -f $(OBJ)

# Full clean (removes object files and executable)
fclean: clean
	rm -f $(NAME)

# Rebuild the project (full clean followed by all)
re: fclean all

# Run the executable
exec: $(NAME)
	./$(NAME)

# Prevent conflicts with files of the same name and make's special built-in targets
.PHONY: all clean fclean re exec
