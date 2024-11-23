/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:49:28 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 22:03:36 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTAMYREQUESTFORM
#define ROBOTAMYREQUESTFORM

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
		
		void		execute(Bureaucrat const & executor) const;
	private :
		std::string _name;
};

#endif
