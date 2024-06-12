CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = 

SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXEC = phonebook

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean

