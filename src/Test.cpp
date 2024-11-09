/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:38:13 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 13:13:38 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Test.hpp"

int Test::_passed = 0;
int Test::_failed = 0;

void Test::assert_true(bool condition, const std::string& message) {
    if (condition) {
        std::cout << "\033[32m[PASS]\033[0m " << message << std::endl;
        _passed++;
    } else {
        std::cout << "\033[31m[FAIL]\033[0m " << message << std::endl;
        _failed++;
    }
}

void Test::assert_false(bool condition, const std::string& message) {
    assert_true(!condition, message);
}

void Test::assert_equal(const std::string& expected, const std::string& actual, const std::string& message) {
    bool result = (expected == actual);
    if (result) {
        std::cout << "\033[32m[PASS]\033[0m " << message;
        _passed++;
    } else {
        std::cout << "\033[31m[FAIL]\033[0m " << message;
        _failed++;
    }
    
    if (!result || expected.length() < 50) {
        std::cout << "\n  Expected: '" << expected << "'"
                  << "\n  Actual:   '" << actual << "'";
    } else if (result && expected.length() >= 50) {
        std::cout << "\n  (Long string match, " << expected.length() 
                  << " characters)";
    }
    std::cout << std::endl;
}

void Test::assert_not_equal(const std::string& expected, const std::string& actual, const std::string& message) {
    bool result = (expected != actual);
    if (result) {
        std::cout << "\033[32m[PASS]\033[0m " << message << std::endl;
        _passed++;
    } else {
        std::cout << "\033[31m[FAIL]\033[0m " << message
                  << "\n  Values should be different but both are: '"
                  << expected << "'" << std::endl;
        _failed++;
    }
}

void Test::assert_equal(int expected, int actual, const std::string& message) {
    bool result = (expected == actual);
    if (result) {
        std::cout << "\033[32m[PASS]\033[0m " << message;
        _passed++;
    } else {
        std::cout << "\033[31m[FAIL]\033[0m " << message
                  << "\n  Expected: " << expected
                  << "\n  Actual:   " << actual;
        _failed++;
    }
    std::cout << std::endl;
}

void Test::assert_equal(double expected, double actual, const std::string& message, double epsilon) {
    bool result = std::fabs(expected - actual) < epsilon;
    if (result) {
        std::cout << "\033[32m[PASS]\033[0m " << message;
        _passed++;
    } else {
        std::cout << "\033[31m[FAIL]\033[0m " << message
                  << "\n  Expected: " << expected
                  << "\n  Actual:   " << actual
                  << "\n  Epsilon:  " << epsilon;
        _failed++;
    }
    std::cout << std::endl;
}

void Test::print_results() {
    std::cout << "\nTest Results:" << std::endl;
    std::cout << "\033[32mPassed: " << _passed << "\033[0m" << std::endl;
    std::cout << "\033[31mFailed: " << _failed << "\033[0m" << std::endl;
    std::cout << "Total:  " << _passed + _failed << std::endl;
}