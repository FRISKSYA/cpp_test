/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:36:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 18:07:33 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <string>

/**
* @brief A minimal testing framework for C++98
* @details Provides basic assertion and test reporting functionality
*/
class Test
{
   private:
   	static int	_passed; ///< Counter for passed tests
   	static int	_failed; ///< Counter for failed tests

   public:
   	/**
   	 * @brief Asserts that a condition is true
   	 * @param condition The boolean condition to test
   	 * @param message Description of the test
   	 */
   	static void	assert_true(bool condition, const std::string& message);

   	/**
   	 * @brief Asserts that a condition is false
   	 * @param condition The boolean condition to test
   	 * @param message Description of the test
   	 */
   	static void	assert_false(bool condition, const std::string& message);

   	/**
   	 * @brief Asserts that two strings are equal
   	 * @param expected The expected string value
   	 * @param actual The actual string value
   	 * @param message Description of the test
   	 */
   	static void	assert_equal(const std::string& expected, const std::string& actual, const std::string& message);

   	/**
   	 * @brief Asserts that two strings are not equal
   	 * @param expected The string that actual should not equal
   	 * @param actual The string to test
   	 * @param message Description of the test
   	 */
   	static void	assert_not_equal(const std::string& expected, const std::string& actual, const std::string& message);

   	/**
   	 * @brief Asserts that two integers are equal
   	 * @param expected The expected integer value
   	 * @param actual The actual integer value
   	 * @param message Description of the test
   	 */
   	static void	assert_equal(int expected, int actual, const std::string& message);

   	/**
   	 * @brief Asserts that two floating point numbers are equal within epsilon
   	 * @param expected The expected floating point value
   	 * @param actual The actual floating point value
   	 * @param message Description of the test
   	 * @param epsilon Maximum allowed difference between expected and actual
   	 */
   	static void	assert_equal(double expected, double actual, const std::string& message, double epsilon);

   	/**
   	 * @brief Prints the final test results
   	 * @details Shows the total number of passed and failed tests
   	 */
   	static void	print_results();
};

#endif
