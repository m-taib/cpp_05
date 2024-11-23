/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:16:36 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 23:49:56 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	try
	{
		Intern a;
		AForm *ptr;

		ptr = a.makeForm("RobotomyRequestForm", "mtaib");
		delete ptr;
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
	}
	return (0);
}
