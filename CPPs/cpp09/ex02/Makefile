# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = main.cpp PmergeMe.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name (as required by the subject)
NAME = PmergeMe

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
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

# Test with small example from PDF
test: $(NAME)
	@echo "$(PURPLE)$(BOLD)Running PmergeMe tests...$(RESET)"
	@echo "$(CYAN)Test from PDF: 3 5 9 7 4$(RESET)"
	@./$(NAME) 3 5 9 7 4
	@echo ""

# Test with medium size
test-medium: $(NAME)
	@echo "$(PURPLE)Testing with 50 random numbers...$(RESET)"
	@./$(NAME) `shuf -i 1-1000 -n 50 | tr '\n' ' '`

# Test with large dataset (3000 numbers)
test-large: $(NAME)
	@echo "$(PURPLE)$(BOLD)Testing with 3000 random numbers...$(RESET)"
	@echo "$(YELLOW)This may take a few seconds...$(RESET)"
	@./$(NAME) `shuf -i 1-100000 -n 3000 | tr '\n' ' '`

# Test edge cases
test-edges: $(NAME)
	@echo "$(PURPLE)Testing edge cases...$(RESET)"
	@echo "$(CYAN)Single number:$(RESET)"
	@./$(NAME) 42
	@echo ""
	@echo "$(CYAN)Two numbers:$(RESET)"
	@./$(NAME) 5 1
	@echo ""
	@echo "$(CYAN)Already sorted:$(RESET)"
	@./$(NAME) 1 2 3 4 5
	@echo ""
	@echo "$(CYAN)Reverse sorted:$(RESET)"
	@./$(NAME) 5 4 3 2 1

# Test error cases
test-errors: $(NAME)
	@echo "$(YELLOW)Testing error cases...$(RESET)"
	@echo "$(CYAN)No arguments:$(RESET)"
	@./$(NAME) || true
	@echo ""
	@echo "$(CYAN)Negative number:$(RESET)"
	@./$(NAME) -1 2 3 || true
	@echo ""
	@echo "$(CYAN)Invalid input:$(RESET)"
	@./$(NAME) 1 abc 3 || true

# Performance comparison test
test-performance: $(NAME)
	@echo "$(PURPLE)$(BOLD)Performance comparison test...$(RESET)"
	@echo "$(CYAN)Small (10 numbers):$(RESET)"
	@./$(NAME) `shuf -i 1-100 -n 10 | tr '\n' ' '`
	@echo ""
	@echo "$(CYAN)Medium (100 numbers):$(RESET)"
	@./$(NAME) `shuf -i 1-1000 -n 100 | tr '\n' ' '`
	@echo ""
	@echo "$(CYAN)Large (1000 numbers):$(RESET)"
	@./$(NAME) `shuf -i 1-10000 -n 1000 | tr '\n' ' '`

# For macOS users (jot instead of shuf)
test-macos: $(NAME)
	@echo "$(PURPLE)Testing with macOS jot command...$(RESET)"
	@./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`

# Run all tests
test-all: test test-edges test-medium test-large test-errors
	@echo "$(GREEN)$(BOLD)All tests completed!$(RESET)"

# Show help
help:
	@echo "$(BLUE)$(BOLD)Available targets:$(RESET)"
	@echo " $(GREEN)all$(RESET)             : Build the executable"
	@echo " $(GREEN)clean$(RESET)           : Remove object files"
	@echo " $(GREEN)fclean$(RESET)          : Remove object files and executable"
	@echo " $(GREEN)re$(RESET)              : Rebuild everything"
	@echo " $(CYAN)test$(RESET)            : Run basic test from PDF"
	@echo " $(CYAN)test-medium$(RESET)     : Test with 50 numbers"
	@echo " $(CYAN)test-large$(RESET)      : Test with 3000 numbers"
	@echo " $(CYAN)test-edges$(RESET)      : Test edge cases"
	@echo " $(CYAN)test-errors$(RESET)     : Test error handling"
	@echo " $(CYAN)test-performance$(RESET): Performance comparison"
	@echo " $(CYAN)test-macos$(RESET)      : Test for macOS users"
	@echo " $(CYAN)test-all$(RESET)        : Run all tests"
	@echo " $(GREEN)help$(RESET)            : Show this help"

# Declare phony targets
.PHONY: all clean fclean re test test-medium test-large test-edges test-errors test-performance test-macos test-all help