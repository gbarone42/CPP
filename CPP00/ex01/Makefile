CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = build

SRC_FILE = main.cpp
OBJ_FILE = $(OBJ_DIR)/main.o

EXEC = phonebook

all: $(EXEC)

$(EXEC): $(OBJ_FILE)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
