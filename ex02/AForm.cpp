/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:27:23 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 17:10:53 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _signedgrade(0), _execgrade(0)
{

}

AForm::GradeTooHighException::GradeTooHighException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise Gradetoohigh constructer has been called" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(const char *excep) : _excep(excep)
{
	std::cout << "Parametrise GradeTooLow constructer has been called" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (_excep);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (_excep);
}

AForm::AForm(std::string name, int signedgrade, int execgrade) : _name(name), _signedgrade(signedgrade), _execgrade(execgrade)
{
	std::cout << "Parametrise constructor has been called" << std::endl;
	_signed = false;
	if (signedgrade < 1 || execgrade < 1)
		throw GradeTooHighException("Grade is too high\n");
	else if (signedgrade > 150 || execgrade > 150)
		throw GradeTooLowException("Grade is too low\n");
}

AForm::AForm(const AForm& rhs) : _signed(rhs._signed), _signedgrade(rhs._signedgrade), _execgrade(rhs._execgrade)
{
	std::cout << "Copy constructor has been called" << std::endl;
	*this = rhs;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	_signed = rhs._signed;
	return (*this);
}

std::ostream& 	operator<<(std::ostream& os, AForm& rhs)
{
	os << rhs.getName() << " has the signed grade : " << rhs.getSignGrade()
	   << " and execution grade : " << rhs.getExecGrade();
	if (rhs.getSign())
		os << " has signed to the form";
	else
		os << " hasn't signed to the form";
	return (os);
}

std::string AForm::getName() const
{
	return (_name);
}

bool 	AForm::getSign() const
{
	return (_signed);
}

int 	AForm::getSignGrade() const
{
	return (_signedgrade);
}

int  	AForm::getExecGrade() const
{
	return (_execgrade);
}

void	AForm::beSigned(const Bureaucrat& brt)
{
	if (brt.getGrade() <= _signedgrade)
		_signed = true;
	else
		throw GradeTooLowException("Grade is too low");
}

void	AForm::checkGrade(Bureaucrat const & executor) const
{
	if (!_signed || executor.getGrade() > _execgrade)
		throw GradeTooLowException("Unfortunally you cannot execute the form");
}	

AForm::~AForm()
{
	std::cout << "desctructor has been called" << std::endl;
}
