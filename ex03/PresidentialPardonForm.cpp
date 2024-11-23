/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:58:33 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 22:04:12 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _name("")
{
	std::cout << "PresidentialPardonForm constructor has been called" << std::endl;
}
	
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , _name(target)
{
	std::cout << "PresidentialPardonForm parametrise constructor has been called" << std::endl;
}
	
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) 
{
	std::cout << "PresidentialPardonForm copy constructor has been called" << std::endl;
	*this = rhs;
}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator has been called" << std::endl;
	_name = rhs._name;
	return (*this);
}

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkGrade(executor);
	std::cout << _name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor has been called" << std::endl;
}
