/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:06:36 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/25 17:29:18 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public :

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string  getName() const;
		int				   getGrade() const;
		void			   incrementGrade();	
		void			   decrementGrade();
		void			   signForm(AForm& form);	
		void			   executeForm(AForm const & form);
	private :

		Bureaucrat();
		const std::string _name;
		int				  _grade;
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

std::ostream& 	operator<<(std::ostream& os, const Bureaucrat& rhs);
#endif
