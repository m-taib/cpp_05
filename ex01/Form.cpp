/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:27:23 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 16:09:11 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _signedgrade(0), _execgrade(0)
{

}

Form::GradeTooHighException::GradeTooHighException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise Gradetoohigh constructer has been called" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise GradeTooLow constructer has been called" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (_excep);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (_excep);
}

Form::Form(std::string name, int signedgrade, int execgrade) : _name(name), _signedgrade(signedgrade), _execgrade(execgrade)
{
	std::cout << "Parametrise constructor has been called" << std::endl;
	_signed = false;
	if (signedgrade < 1 || execgrade < 1)
		throw GradeTooHighException("Grade is too high");
	else if (signedgrade > 150 || execgrade > 150)
		throw GradeTooLowException("Grade is too low");
}

Form::Form(const Form& rhs) : _signed(rhs._signed), _signedgrade(rhs._signedgrade), _execgrade(rhs._execgrade)
{
	std::cout << "Copy constructor has been called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	_signed = rhs._signed;
	return (*this);
}

std::ostream& 	operator<<(std::ostream& os, Form& rhs)
{
	os << rhs.getName() << "has the signed grade : " << rhs.getSignGrade()
	   << " and execution grade : " << rhs.getExecGrade() << std::endl;
	if (rhs.getSign())
		os << "has signed to the form" << std::endl;
	else
		os << "hasn't signed to the form" << std::endl;
	return (os);
}

std::string Form::getName() const
{
	return (_name);
}

bool 	Form::getSign() const
{
	return (_signed);
}

int 	Form::getSignGrade() const
{
	return (_signedgrade);
}

int  	Form::getExecGrade() const
{
	return (_execgrade);
}

void	Form::beSigned(const Bureaucrat& brt)
{
	if (brt.getGrade() <= _signedgrade)
		_signed = true;
	else
		throw GradeTooLowException("Grade is too low");
}

Form::~Form()
{
	std::cout << "desctructor has been called" << std::endl;
}
