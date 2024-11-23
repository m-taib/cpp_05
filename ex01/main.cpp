/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:24:08 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/23 17:39:40 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try 
	{
		Bureaucrat b("mtaib", 1);
		Form	c("test", 18, 20);
		c.beSigned(b);
		b.signForm(c);
		std::cout << b << std::endl;
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
	}
	return (0);
}
