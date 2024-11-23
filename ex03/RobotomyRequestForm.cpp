/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:00:46 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 22:03:24 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _name("")
{
	std::cout << "RobotomyRequestForm constructor has been called" << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , _name(target)
{
	std::cout << "RobotomyRequestForm parametrise constructor has been called" << std::endl;

}
	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy constructor has been called" << std::endl;
	*this = rhs;
}
	
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator has been called" << std::endl;
	_name = rhs._name;
	return (*this);
}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkGrade(executor);
	if (rand() % 2)
		std::cout << _name << " has been robotomized" << std::endl;
	else
		std::cout << _name << " has not been robotomized" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
}
