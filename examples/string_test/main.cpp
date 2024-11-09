/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:58:16 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 13:02:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include <string>
#include <iostream>

void test_basic_string_operations() {
    std::string str1 = "Hello";
    std::string str2 = "Hello";
    std::string str3 = "World";

    Test::assert_equal(str1, str2, "Same strings should be equal");
    Test::assert_equal(str1 + " " + str3, "Hello World", "String concatenation test");
}

void test_special_characters() {
    Test::assert_equal("\n", "\n", "Newline comparison");
    Test::assert_equal("\t", "\t", "Tab comparison");
    Test::assert_equal("\r", "\r", "Carriage return comparison");
    Test::assert_equal(" ", " ", "Space comparison");
    Test::assert_equal("\0", "\0", "Null character comparison");
}

void test_edge_cases() {
    Test::assert_equal("", "", "Empty string comparison");
    
    std::string long_str(1000, 'a');  
    Test::assert_equal(long_str, long_str, "Long string comparison");
    
    Test::assert_equal("abc", "def", "Same length, different content");
}

void test_case_sensitivity() {
    Test::assert_equal("Hello", "hello", "Case sensitive comparison - should fail");
    Test::assert_equal("WORLD", "WORLD", "Uppercase comparison");
    Test::assert_equal("world", "world", "Lowercase comparison");
}

void test_whitespace_handling() {
    Test::assert_equal("hello  world", "hello world", "Different space count - should fail");
    Test::assert_equal(" hello", "hello ", "Leading vs trailing space - should fail");
    Test::assert_equal("\thello", "hello", "Tab vs no whitespace - should fail");
}

void test_mixed_string_types() {
    Test::assert_equal("test123", "test123", "Alphanumeric comparison");
    Test::assert_equal("123test", "test123", "Different order - should fail");
    Test::assert_equal("hello@world!", "hello@world!", "String with symbols");
    Test::assert_equal("!@#$%^&*()", "!@#$%^&*()", "Special symbols comparison");
}

void test_boundary_cases() {
    std::string max_str(65535, 'x');
    Test::assert_equal(max_str, max_str, "Maximum length string");
    Test::assert_equal("hello world", "hello worlb", "Single char difference test - should fail");
    Test::assert_equal("test!", "test.", "Different ending character - should fail");
}

int main() {
    std::cout << "\n\033[1m=== Basic String Operations ===\033[0m\n";
    test_basic_string_operations();

    std::cout << "\n\033[1m=== Special Characters Tests ===\033[0m\n";
    test_special_characters();

    std::cout << "\n\033[1m=== Edge Cases ===\033[0m\n";
    test_edge_cases();

    std::cout << "\n\033[1m=== Case Sensitivity Tests ===\033[0m\n";
    test_case_sensitivity();

    std::cout << "\n\033[1m=== Whitespace Handling Tests ===\033[0m\n";
    test_whitespace_handling();

    std::cout << "\n\033[1m=== Mixed String Types Tests ===\033[0m\n";
    test_mixed_string_types();

    std::cout << "\n\033[1m=== Boundary Cases Tests ===\033[0m\n";
    test_boundary_cases();

    std::cout << "\n";
    Test::print_results();
    return 0;
}

