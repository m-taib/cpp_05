/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:07:05 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/23 19:43:15 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise Gradetoohigh constructer has been called" << std::endl;	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_excep);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise GradeTooLow constructer has been called" << std::endl;	
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_excep);
}

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
	std::cout << "A bureaucrat has been constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Grade is too high");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low");
	std::cout << "A bureaucrat has been constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
{
	std::cout << "Copy constructed has been called" << std::endl;
	*this = rhs;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	_grade = rhs._grade;
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException("Grade is too high");
}

void	Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw GradeTooLowException("Grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << " bureaucrat grade "<< rhs.getGrade();
	return (os);
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getSign())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " 
				  << form.getName() 
				  << " because the sign is low than the required one" << std::endl;	
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat has been destructed" << std::endl;
}
