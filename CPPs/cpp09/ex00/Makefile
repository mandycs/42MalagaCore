# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = main.cpp BitcoinExchange.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name (as required by the subject)
NAME = btc

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

# Test target with example input
test: $(NAME)
	@echo "$(PURPLE)Running Bitcoin Exchange tests...$(RESET)"
	@echo "$(CYAN)Testing with input.txt:$(RESET)"
	@./$(NAME) input.txt

# Test with no arguments (should show error)
test-error: $(NAME)
	@echo "$(YELLOW)Testing error case (no arguments):$(RESET)"
	@./$(NAME) || true

# Create sample input file
sample-input:
	@echo "$(CYAN)Creating sample input.txt file...$(RESET)"
	@echo "date | value" > input.txt
	@echo "2011-01-03 | 3" >> input.txt
	@echo "2011-01-03 | 2" >> input.txt
	@echo "2011-01-03 | 1" >> input.txt
	@echo "2011-01-03 | 1.2" >> input.txt
	@echo "2011-01-09 | 1" >> input.txt
	@echo "2012-01-11 | -1" >> input.txt
	@echo "2001-42-42" >> input.txt
	@echo "2012-01-11 | 1" >> input.txt
	@echo "2012-01-11 | 2147483648" >> input.txt
	@echo "$(GREEN)✓ Sample input.txt created!$(RESET)"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo " all          : Build the executable"
	@echo " clean        : Remove object files"
	@echo " fclean       : Remove object files and executable"
	@echo " re           : Rebuild everything"
	@echo " test         : Build and run tests with input.txt"
	@echo " test-error   : Test error handling"
	@echo " sample-input : Create sample input.txt file"
	@echo " help         : Show this help"

# Declare phony targets
.PHONY: all clean fclean re test test-error sample-input help