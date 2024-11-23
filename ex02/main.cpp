/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:08:08 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 17:12:04 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	AForm		*shrubbery = new ShrubberyCreationForm("hello world");
	Bureaucrat 	brt("mtaib", 18);
	
	shrubbery->beSigned(brt);
	brt.executeForm(*shrubbery);
	delete shrubbery;
	return (0);
}
