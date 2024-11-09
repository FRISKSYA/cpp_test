/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_framework.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:50:59 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 17:00:12 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"
#include <string>
#include <sstream>
#include <iostream>

//NOTE: you have to start the function.
void test_initial_state() {
    std::cout << "\033[1m=== Initial State Tests ===\033[0m\n";

    Test::print_results();
}

void test_assert_true() {
    std::cout << "\n\033[1m=== Assert True Tests ===\033[0m\n";

    Test::assert_true(true, "True assertion should pass");
    Test::assert_true(1 == 1, "Equal numbers assertion should pass");
    Test::assert_true(false, "False assertion should fail");
}

void test_assert_false() {
    std::cout << "\n\033[1m=== Assert False Tests ===\033[0m\n";

    Test::assert_false(false, "False assertion should pass");
    Test::assert_false(1 == 2, "Not equal numbers assertion should pass");
    Test::assert_false(true, "True assertion should fail");
}

void test_string_equality() {
    std::cout << "\n\033[1m=== String Equality Tests ===\033[0m\n";

    Test::assert_equal("", "", "Empty string comparison should pass");
    Test::assert_equal("test", "test", "Same string comparison should pass");
    Test::assert_equal("test", "different", "Different string comparison should fail");
}

void test_string_inequality() {
    std::cout << "\n\033[1m=== String Inequality Tests ===\033[0m\n";

    Test::assert_not_equal("test", "different", "Different strings should pass");
    Test::assert_not_equal("", "non-empty", "Empty and non-empty strings should pass");
    Test::assert_not_equal("same", "same", "Same strings should fail");
}

void test_integer_equality() {
    std::cout << "\n\033[1m=== Integer Equality Tests ===\033[0m\n";

    Test::assert_equal(0, 0, "Zero comparison should pass");
    Test::assert_equal(-42, -42, "Negative number comparison should pass");
    Test::assert_equal(42, -42, "Different numbers should fail");
}

void test_double_equality() {
    std::cout << "\n\033[1m=== Double Equality Tests ===\033[0m\n";

    Test::assert_equal(0.0, 0.0, "Zero double comparison should pass", 1e-4);
    Test::assert_equal(3.14159, 3.14158, "Close doubles should pass with epsilon", 1e-4);
    Test::assert_equal(1.0, 2.0, "Different doubles should fail", 1e-4);
}

void test_edge_cases() {
    std::cout << "\n\033[1m=== Edge Cases Tests ===\033[0m\n";

    // 空文字列のテスト
    Test::assert_equal("", "", "Empty string comparison");
    Test::assert_not_equal("", "non-empty", "Empty and non-empty string comparison");

    // 特殊文字のテスト
    Test::assert_equal("\n\t\r", "\n\t\r", "Special characters comparison");
    
    // 極端な数値のテスト
    Test::assert_equal(2147483647, 2147483647, "MAX_INT comparison");
    Test::assert_equal(-2147483648, -2147483648, "MIN_INT comparison");
}

int main() {
    test_initial_state();
    test_assert_true();
    test_assert_false();
    test_string_equality();
    test_string_inequality();
    test_integer_equality();
    test_double_equality();
    test_edge_cases();

    std::cout << "\n";
    Test::print_results();
    return 0;
}
