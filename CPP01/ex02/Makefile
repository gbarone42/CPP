# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
EXEC = hi_this_is_brain
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Full clean (includes the executable)
fclean: clean
	rm -f $(EXEC)

# Rule to re-make everything
re: fclean all

# Run the executable
exec: $(EXEC)
	./$(EXEC)

# Avoid filename conflicts
.PHONY: all clean fclean re exec
