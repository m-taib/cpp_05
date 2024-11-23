/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:17:52 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 16:12:03 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		Form(std::string name, int signedgrade, int execgrade);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();
		
		std::string 		getName() const;
		bool 				getSign() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void				beSigned(const Bureaucrat& brt);

	private :
		Form();
		const std::string _name;
		bool 			  _signed;
		const int		  _signedgrade;
		const int		  _execgrade;
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

std::ostream& 	operator<<(std::ostream& os, Form& rhs);
#endif
