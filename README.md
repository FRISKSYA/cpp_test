# Simple C++ Test Framework

A minimalist C++98 testing framework designed for educational projects. Features include basic assertions, colored terminal output, and test result tracking - all without external dependencies.

## Features
- Simple assertion methods
- Colored test output in terminal
- No external dependencies
- C++98 compatible
- Test result statistics

## Project Structure
```
cpp98-test-framework/
├── src/
│   └── Test.cpp
├── include/
│   └── Test.hpp
├── examples/
│   ├── basic/         # Basic usage examples
│   └── string_test/   # String comparison tests
└── tests/             # Framework tests
```

## Basic Usage

1. Include the header
```cpp
#include "Test.hpp"
```

2. Write your tests
```cpp
void test_example() {
    Test::assert_true(1 == 1, "Basic equality test");
    Test::assert_equal("hello", "hello", "String equality test");
}

int main() {
    test_example();
    Test::print_results();
    return 0;
}
```

## Available Assertions
- `assert_true(condition, message)`: Tests if a condition is true
- `assert_equal(expected, actual, message)`: Tests if two values are equal

## Output Format
```
[PASS] Basic equality test
[FAIL] Failed test description
  Expected: 'expected value'
  Actual:   'actual value'

Test Results:
Passed: 1
Failed: 1
Total:  2
```

## Build and Run
```bash
# Build the framework and examples
make

# Run basic tests example
cd examples/basic && ./basic_test

# Run string tests example
cd examples/string_test && ./string_test
```

## Requirements
- C++ compiler with C++98 support
- Make

## Compilation Flags
- -Wall -Wextra -Werror
- -std=c++98

## Future Improvements
- Additional assertion types
- Customizable output formats
- Numerical comparison support
- Test suite organization

## License
This project is open source.
