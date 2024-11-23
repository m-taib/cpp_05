/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:24:08 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 17:22:29 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try 
	{
		Bureaucrat b("mtaib",21);
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
	}
	return (0);
}
