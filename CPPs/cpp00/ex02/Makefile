# Variables
CXX = c++                   # Compiler to use
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  # Compilation flags

# Executable
EXEC = bank

# Source files
SRC = tests.cpp Account.cpp

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

# Complete clean (includes executable)
fclean: clean
	rm -f $(EXEC)

# Complete rebuild
re: fclean all

.PHONY: all clean fclean re
