# Simple C++ Test Framework

A minimalist C++98 testing framework designed for educational projects. Features include basic assertions, colored terminal output, and test result tracking - all without external dependencies.

## Features
- Simple assertion methods
- Colored test output
- No external dependencies
- C++98 compatible
- Test result statistics

## Usage

1. Include the header
```cpp
#include "test.hpp"
```

2. Write your tests
```cpp
void test_example() {
    // Test something
    Test::assert_true(1 == 1, "Basic equality test");
    Test::assert_equal("hello", "hello", "String equality test");
}

int main() {
    test_example();
    Test::print_results();
    return 0;
}
```

3. Run and check results
```bash
$ ./test
[PASS] Basic equality test
[PASS] String equality test

Test Results:
Passed: 2
Failed: 0
Total:  2
```

## Build
```bash
$ make
```

## License
This project is open source.
