# Variables
CXX = c++                   # Compiler to use
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  # Compilation flags

# Executable
EXEC = megaphone

# Source file
SRC = megaphone.cpp

# Object file
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile the source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

# Complete rebuild
re: fclean all

.PHONY: all clean fclean re
