# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = main.cpp RPN.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name (as required by the subject)
NAME = RPN

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

# Test target with examples from PDF
test: $(NAME)
	@echo "$(PURPLE)Running RPN Calculator tests...$(RESET)"
	@echo "$(CYAN)Test 1: '8 9 * 9 - 9 - 9 - 4 - 1 +' (should be 42)$(RESET)"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" || true
	@echo ""
	@echo "$(CYAN)Test 2: '7 7 * 7 -' (should be 42)$(RESET)"
	@./$(NAME) "7 7 * 7 -" || true
	@echo ""
	@echo "$(CYAN)Test 3: '1 2 * 2 / 2 * 2 4 - +' (should be 0)$(RESET)"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +" || true
	@echo ""
	@echo "$(CYAN)Test 4: '(1 + 1)' (should show Error - brackets not allowed)$(RESET)"
	@./$(NAME) "(1 + 1)" || true

# Test additional cases
test-more: $(NAME)
	@echo "$(PURPLE)Running additional RPN tests...$(RESET)"
	@echo "$(CYAN)Simple addition: '3 4 +'$(RESET)"
	@./$(NAME) "3 4 +" || true
	@echo ""
	@echo "$(CYAN)Simple subtraction: '5 2 -'$(RESET)"
	@./$(NAME) "5 2 -" || true
	@echo ""
	@echo "$(CYAN)Simple multiplication: '6 7 *'$(RESET)"
	@./$(NAME) "6 7 *" || true
	@echo ""
	@echo "$(CYAN)Simple division: '8 2 /'$(RESET)"
	@./$(NAME) "8 2 /" || true
	@echo ""
	@echo "$(CYAN)Division by zero: '5 0 /' (should show Error)$(RESET)"
	@./$(NAME) "5 0 /" || true
	@echo ""
	@echo "$(CYAN)Invalid input: 'abc' (should show Error)$(RESET)"
	@./$(NAME) "abc" || true

# Test error cases
test-errors: $(NAME)
	@echo "$(YELLOW)Testing error cases...$(RESET)"
	@echo "$(CYAN)No arguments (should show Error)$(RESET)"
	@./$(NAME) || true
	@echo ""
	@echo "$(CYAN)Too many arguments (should show Error)$(RESET)"
	@./$(NAME) "1 2 +" "extra" || true
	@echo ""
	@echo "$(CYAN)Empty expression (should show Error)$(RESET)"
	@./$(NAME) "" || true

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo " all        : Build the executable"
	@echo " clean      : Remove object files"
	@echo " fclean     : Remove object files and executable"
	@echo " re         : Rebuild everything"
	@echo " test       : Run tests from PDF examples"
	@echo " test-more  : Run additional basic tests"
	@echo " test-errors: Test error handling"
	@echo " help       : Show this help"

# Declare phony targets
.PHONY: all clean fclean re test test-more test-errors help