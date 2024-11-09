/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:15:56 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 13:22:20 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include <iostream>

void test_bool_assertions() {
    Test::assert_false(false, "False should be false");
    Test::assert_false(1 == 2, "1 should not equal 2");
    Test::assert_false(true, "True should fail - false test");
}

void test_integer_comparisons() {
    Test::assert_equal(42, 42, "Integer equality");
    Test::assert_equal(0, 0, "Zero equality");
    Test::assert_equal(-42, -42, "Negative integer equality");
    Test::assert_equal(2147483647, 2147483647, "Maximum integer equality");
    Test::assert_equal(-2147483648, -2147483648, "Minimum integer equality");
    Test::assert_equal(42, 43, "Different integers - should fail");
}

void test_double_comparisons() {
    Test::assert_equal(3.14159, 3.14159, "Double equality exact", 1e-4);
    Test::assert_equal(3.14159, 3.14158, "Double equality within epsilon", 1e-4);
    Test::assert_equal(0.1 + 0.2, 0.3, "Double arithmetic test", 1e-4);
    Test::assert_equal(-3.14159, -3.14159, "Negative double equality", 1e-4);
    Test::assert_equal(1.0, 2.0, "Different doubles - should fail", 1e-4);
}

void test_not_equal_strings() {
    Test::assert_not_equal("hello", "world", "Different strings");
    Test::assert_not_equal("", "not empty", "Empty and non-empty strings");
    Test::assert_not_equal("HELLO", "hello", "Case sensitive strings");
    Test::assert_not_equal("hello", "hello", "Same strings - should fail");
}

int main() {
    std::cout << "\n\033[1m=== Boolean Assertion Tests ===\033[0m\n";
    test_bool_assertions();

    std::cout << "\n\033[1m=== Integer Comparison Tests ===\033[0m\n";
    test_integer_comparisons();

    std::cout << "\n\033[1m=== Double Comparison Tests ===\033[0m\n";
    test_double_comparisons();

    std::cout << "\n\033[1m=== String Not Equal Tests ===\033[0m\n";
    test_not_equal_strings();

    std::cout << "\n";
    Test::print_results();
    return 0;
}
