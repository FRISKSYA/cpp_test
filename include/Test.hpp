/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:36:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/11/09 12:37:48 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <string>

class Test
{
	private:
		static int _passed;
		static int _failed;

	public:
		static void	assert_true(bool condition, const std::string& message);
		static void	assert_equal(
			const std::string& expected,
			const std::string& actual,
			const std::string& message
			);
		static void	print_results();
};

#endif
