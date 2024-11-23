/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:50:08 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 16:57:45 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor has been called" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "Intern copy constructor has been called" << std::endl;
	(void)rhs;
}

const char* Intern::UnkownForm::what() const throw()
{
	return (_excep);
}
Intern::UnkownForm::UnkownForm()
{
	
}

Intern::UnkownForm::UnkownForm(const char *excep) : _excep(excep)
{

}

Intern& 	Intern::operator=(const Intern& rhs)
{
	std::cout << "Intern copy assignment operator has been called" << std::endl;
	(void)rhs;
	return (*this);
}

AForm*	Intern::PresidentialPardonFormInstance(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::RobotomyRequestFormInstance(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::ShrubberyCreationFormInstance(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* 	Intern::makeForm(std::string formname, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	int		i;
	ptrForm form[3];	
	form[0] = &Intern::ShrubberyCreationFormInstance;
	form[1] = &Intern::PresidentialPardonFormInstance;
	form[2] = &Intern::RobotomyRequestFormInstance;
	
	i = -1;
	while (++i < 3)
	{
		if (!formname.compare(forms[i]))
			return (this->*form[i])(target);
	}
	throw UnkownForm("UNKOWN FORM");
	return (NULL);
}

Intern::~Intern()
{
	std::cout << "Intern destrcutor has been called" << std::endl;

}
