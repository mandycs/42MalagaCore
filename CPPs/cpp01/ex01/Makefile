# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
EXEC = zombieHorde

# Source files
SRC = main.cpp Zombie.cpp zombieHorde.cpp

# Object files (automatically generated from .cpp files)
OBJ = $(SRC:.cpp=.o)

# Default rule to compile the project
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the object files
clean:
	rm -f $(OBJ)

# Clean up the object files and the executable
fclean: clean
	rm -f $(EXEC)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
