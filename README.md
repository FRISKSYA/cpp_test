# Simple C++ Test Framework

A minimalist C++98 testing framework designed for educational projects. Features include basic assertions, colored terminal output, and test result tracking - all without external dependencies.

## Features
- Simple assertion methods (true/false, equality, non-equality)
- String comparison support
- Numeric comparison support (integers and floating-point numbers)
- Colored test output in terminal
- Detailed error reporting
- No external dependencies
- C++98 compatible


## Project Structure
```
cpp98-test-framework/
├── src/             # Framework source code
├── include/         # Framework headers
├── examples/        # Usage examples
│   ├── basic/      # Basic usage
│   ├── string_test/# String comparison tests
│   └── number_test/# Numeric comparison tests
└── tests/          # Framework tests
```

## Available Assertions
```cpp
// Boolean assertions
Test::assert_true(condition, message);
Test::assert_false(condition, message);

// String comparisons
Test::assert_equal(expected_str, actual_str, message);
Test::assert_not_equal(expected_str, actual_str, message);

// Numeric comparisons
Test::assert_equal(expected_int, actual_int, message);
Test::assert_equal(expected_double, actual_double, message, epsilon);
```

## Basic Usage
```cpp
#include "Test.hpp"

void test_example() {
    // Boolean test
    Test::assert_true(1 == 1, "One equals one");
    
    // String test
    Test::assert_equal("hello", "hello", "String equality");
    
    // Numeric test
    Test::assert_equal(42, 42, "Integer equality");
    Test::assert_equal(3.14, 3.14159, "Double equality", 0.01);
}

int main() {
    test_example();
    Test::print_results();
    return 0;
}
```
## Using as a Git Submodule

1. Add the framework as a submodule in your project:
```bash
# In your project root directory
git submodule add https://github.com/FRISKSYA/cpp98-test-framework.git test/framework
git submodule init
git submodule update
```

2. Project structure after adding the submodule:
```
your-project/
├── test/
│   ├── framework/          # Cloned test framework
│   ├── test.cpp           # Your test code
│   └── Makefile
└── ... (your project files)
```

3. Example test/Makefile:
```makefile
NAME = test_program
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I./framework/include

SRCS = framework/src/Test.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

4. Example test code (test.cpp):
```cpp
#include "Test.hpp"

void test_your_function() {
    // Your test cases here
    Test::assert_true(/* condition */, "Test description");
    Test::assert_equal(/* expected */, /* actual */, "Test description");
}

int main() {
    test_your_function();
    Test::print_results();
    return 0;
}
```

5. To update the framework in your project:
```bash
git submodule update --remote
```

## Output Format
```
[PASS] Test description
[FAIL] Test description

  Expected: 'expected value'
  Actual:   'actual value'

Test Results:
Passed: X
Failed: Y
Total:  Z
```

## Build and Run

1. Build the framework and all examples:
```bash
make
```

2. Run specific tests:
```bash
# Run basic tests
./examples/basic/basic_test

# Run string tests
./examples/string_test/string_test

# Run numeric tests
./examples/number_test/number_test

# Run framework tests
./tests/test_framework
```

3. Run all tests:
```bash
make run
```

## Requirements
- C++ compiler with C++98 support
- Make

## Compilation Flags
- -Wall -Wextra -Werror
- -std=c++98

## Development
- Clean build files: `make clean`
- Clean all generated files: `make fclean`
- Rebuild everything: `make re`

## Examples
Check the `examples/` directory for detailed usage examples:
- `basic/`: Basic assertion usage
- `string_test/`: String comparison examples
- `number_test/`: Numeric comparison examples

## License
This project is open source and available under the MIT License. See the LICENSE file for more info.
