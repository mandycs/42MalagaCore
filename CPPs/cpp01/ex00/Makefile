# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable
EXEC = zombie

# Source files
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Full clean (includes executable)
fclean: clean
	rm -f $(EXEC)

# Full rebuild
re: fclean all

.PHONY: all clean fclean re
