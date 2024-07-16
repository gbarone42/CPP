CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

EXEC = harl
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean