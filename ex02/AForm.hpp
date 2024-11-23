/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:17:52 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 16:15:32 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include <stdlib.h>

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(std::string name, int signedgrade, int execgrade);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();
		
		std::string 		getName() const;
		bool 				getSign() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void				beSigned(const Bureaucrat& brt);
		virtual void 		execute(Bureaucrat const & executor) const = 0;
		void				checkGrade(Bureaucrat const & executor) const;
	private :

		const std::string _name;
		bool 			  _signed;
		const int		  _signedgrade;
		const int		  _execgrade;
	
	protected :
		class GradeTooHighException : public std::exception
		{
			public :
				GradeTooHighException();
				GradeTooHighException(const char *excep);
				const char	*what() const throw();
			private :
				const char 	*_excep;
		};
		class GradeTooLowException : public std::exception
		{
			public :
				GradeTooLowException();
				GradeTooLowException(const char *excep);
				const char	*what() const throw();
			private :
				const char 	*_excep;
		};
};

std::ostream& 	operator<<(std::ostream& os, AForm& rhs);
#endif
