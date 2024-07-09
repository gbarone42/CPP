CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = build
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXEC = phonebook

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
