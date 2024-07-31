# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the final executable
TARGET = scavtrap

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): main.o ClapTrap.o ScavTrap.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o ClapTrap.o ScavTrap.o

# Rule to compile main.o
main.o: main.cpp ClapTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile ClapTrap.o
ClapTrap.o: ClapTrap.cpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c ClapTrap.cpp

# Rule to compile ScavTrap.o
ScavTrap.o: ScavTrap.cpp ScavTrap.hpp ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -c ScavTrap.cpp

# Clean the build (removes object files and executable)
clean:
	rm -f *.o $(TARGET)

# Full rebuild (clean and then build)
re: clean all

# Run the executable
exec: $(TARGET)
	./$(TARGET)

# Declare phony targets to avoid conflicts with file names
.PHONY: all clean re exec
