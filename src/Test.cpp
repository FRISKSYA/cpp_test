/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:38:13 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 12:56:16 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Test.hpp"

int Test::_passed = 0;
int Test::_failed = 0;

void	Test::assert_true(bool condition, const std::string& message)
{
	if (condition)
	{
		std::cout << "\033[32m[PASS]\033[0m " << message << std::endl;
		_passed++;
	}
	else
	{
		std::cout << "\033[31m[FAIL]\033[0m " << message << std::endl;
		_failed++;
	}
}

void Test::assert_equal(
			const std::string& expected,
			const std::string& actual,
			const std::string& message)
{
	assert_true(expected == actual, message + "\n  Expected: " + expected + "\n  Actual: " + actual);
}

void Test::print_results() {
    std::cout << "\n\033[1mTest Results:\033[0m" << std::endl;
    std::cout << "\033[32mPassed: " << _passed << "\033[0m" << std::endl;
    std::cout << "\033[31mFailed: " << _failed << "\033[0m" << std::endl;
    std::cout << "Total:  " << _passed + _failed << std::endl;
}
