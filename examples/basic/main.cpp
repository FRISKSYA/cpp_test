/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:43:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 12:55:42 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include <iostream>

void test_basic_assertions() {
    Test::assert_true(true, "True should be true");
    Test::assert_true(42 == 42, "42 should equal 42");
    
    Test::assert_equal("hello", "hello", "String should match");
    
    Test::assert_true(false, "This test should fail");
    Test::assert_equal("hello", "world", "This string comparison should fail");
}

void test_edge_cases() {
    Test::assert_equal("", "", "Empty strings should be equal");
    Test::assert_equal(" ", "  ", "Different length whitespace should not be equal");
    Test::assert_equal("\n", "\n", "Special characters should be handled");
}

void test_multiple_assertions() {
    int x = 42;
    Test::assert_true(x > 0, "42 should be greater than 0");
    Test::assert_true(x < 100, "42 should be less than 100");
    Test::assert_true(x == 42, "x should equal 42");
}

int main() {
    std::cout << "\n\033[1m=== Basic Assertion Tests ===\033[0m\n";
    test_basic_assertions();
    
    std::cout << "\n\033[1m=== Multiple Assertion Tests ===\033[0m\n";
    test_multiple_assertions();
    
    std::cout << "\n\033[1m=== Edge Case Tests ===\033[0m\n";
    test_edge_cases();
    
    std::cout << "\n";
    Test::print_results();
    return 0;
}
