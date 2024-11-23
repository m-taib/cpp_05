/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:47:06 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 23:35:16 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		
		Intern();
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern();
		
		AForm* 	makeForm(std::string formname, std::string target);
		AForm*	PresidentialPardonFormInstance(std::string target);
		AForm*	RobotomyRequestFormInstance(std::string target);
		AForm*	ShrubberyCreationFormInstance(std::string target);
		
	private :	
		typedef AForm* (Intern::*ptrForm)(std::string target);
		class UnkownForm : public std::exception
		{	
			public :
				UnkownForm();
				UnkownForm(const char *excep);
				const char 	*what() const throw();
			private :
				const char *_excep;
		};
};
