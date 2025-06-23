# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
NAME = mutantstack

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

# Default target
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJ)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compile source files to object files
%.o: %.cpp
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Clean object files and executable
fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Test target
test: $(NAME)
	@echo "$(PURPLE)Running MutantStack tests...$(RESET)"
	@./$(NAME)

# Compare with list behavior
compare: $(NAME)
	@echo "$(CYAN)Running comparison tests...$(RESET)"
	@echo "$(YELLOW)This will show that MutantStack behaves like std::list$(RESET)"
	@./$(NAME) | grep -A 10 -B 2 "std::list\|MutantStack"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo " all     : Build the executable"
	@echo " clean   : Remove object files"
	@echo " fclean  : Remove object files and executable"
	@echo " re      : Rebuild everything"
	@echo " test    : Build and run tests"
	@echo " compare : Show comparison between MutantStack and std::list"
	@echo " help    : Show this help"

# Declare phony targets
.PHONY: all clean fclean re test compare help