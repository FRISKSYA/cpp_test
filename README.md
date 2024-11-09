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

