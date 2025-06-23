# **************************************************************************** #
# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files (adding concrete form classes)
SRC = main.cpp \
      Bureaucrat.cpp \
      AForm.cpp \
      ShrubberyCreationForm.cpp \
      RobotomyRequestForm.cpp \
      PresidentialPardonForm.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
NAME = concrete_forms

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
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
	@echo "$(RED)Cleaning executable and generated files...$(RESET)"
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(GREEN)✓ Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Test target (optional)
test: $(NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@./$(NAME)
	@echo "$(YELLOW)Checking for generated files...$(RESET)"
	@ls -la *_shrubbery 2>/dev/null || echo "No shrubbery files found"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  all     : Build the executable"
	@echo "  clean   : Remove object files"
	@echo "  fclean  : Remove object files, executable and generated files"
	@echo "  re      : Rebuild everything"
	@echo "  test    : Build and run the program"
	@echo "  help    : Show this help"

# Declare phony targets
.PHONY: all clean fclean re test help