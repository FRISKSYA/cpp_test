NAME = cpp98-test-framework

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I./include

SRC_DIR = src
EXAMPLES_DIR = examples
TEST_DIRS = basic string_test number_test
TESTS_DIR = tests

# Framework source files
SRCS = $(SRC_DIR)/Test.cpp
OBJS = $(SRCS:.cpp=.o)

# Object file compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Default target
all: framework examples tests

# Framework library
framework: $(OBJS)

# Build all examples
examples: framework
	@for dir in $(TEST_DIRS); do \
		echo "\nBuilding examples/$$dir..."; \
		$(MAKE) -C $(EXAMPLES_DIR)/$$dir; \
	done

# Build and run tests
tests: framework
	@echo "\nBuilding tests..."
	@$(MAKE) -C $(TESTS_DIR)

# Run all tests and examples
run: examples tests
	@echo "\n=== Running Tests ==="
	@./$(TESTS_DIR)/test_framework
	@echo "\n=== Running Examples ==="
	@for dir in $(TEST_DIRS); do \
		echo "\nRunning examples/$$dir/$$dir..."; \
		./$(EXAMPLES_DIR)/$$dir/$$dir; \
	done

# Clean objects
clean:
	$(RM) $(OBJS)
	@for dir in $(TEST_DIRS); do \
		echo "Cleaning examples/$$dir..."; \
		$(MAKE) -C $(EXAMPLES_DIR)/$$dir clean; \
	done
	@echo "Cleaning tests..."
	@$(MAKE) -C $(TESTS_DIR) clean

# Clean everything
fclean: clean
	@for dir in $(TEST_DIRS); do \
		echo "Full cleaning examples/$$dir..."; \
		$(MAKE) -C $(EXAMPLES_DIR)/$$dir fclean; \
	done
	@echo "Full cleaning tests..."
	@$(MAKE) -C $(TESTS_DIR) fclean

re: fclean all

.PHONY: all framework examples tests run clean fclean re