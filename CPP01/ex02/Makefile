CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
EXEC = hi_this_is_brain
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
