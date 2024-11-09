/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:36:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 13:21:30 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <string>

class Test
{
	private:
		static int	_passed;
		static int	_failed;

	public:
		static void	assert_true(bool condition, const std::string& message);
		static void	assert_false(bool condition, const std::string& message);
		static void	assert_equal(const std::string& expected, const std::string& actual, const std::string& message);
		static void	assert_not_equal(const std::string& expected, const std::string& actual, const std::string& message);
		static void	assert_equal(int expected, int actual, const std::string& message);
		static void	assert_equal(double expected, double actual, const std::string& message, double epsilon);
		static void	print_results();
};

#endif
