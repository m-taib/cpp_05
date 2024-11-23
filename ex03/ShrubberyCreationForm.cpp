/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:48:19 by mtaib             #+#    #+#             */
/*   Updated: 2023/10/24 22:35:18 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _name("")
{
	std::cout << "ShrubberyCreationForm constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137) , _name(target)
{
	std::cout << "ShrubberyCreationForm parametrise constructor has been called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
{
	std::cout << "ShrubberyCreationForm copy constructor has been called" << std::endl;
	*this = rhs;	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator has been called" << std::endl;
	_name = rhs._name;
	return (*this);
}

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkGrade(executor);
	try
	{
		std::fstream 	outFile;

		outFile.open(_name + "_shrubbery", std::ios::out);

		if (!outFile.is_open())
			throw "An error happend with file";

		outFile << "       ###              ###                 ###        " << std::endl;
		outFile << "      #o###            #o###               #o###       " << std::endl;   
		outFile << "    #####o###        #####o###           #####o###     " << std::endl;         
		outFile << "   #o#\\#|#/###      #o#\\#|#/###         #o#\\#|#/###    " << std::endl;                
		outFile << "    ###\\|/#o#        ###\\|/#o#           ###\\|/#o#     " << std::endl;         
		outFile << "     # }|{  #         # }|{  #            # }|{  #     " << std::endl;         
		outFile << "       }|{              }|{                 }|{        " << std::endl;

		outFile.close();
	}
	catch (const char* exp)
	{
		std::cout << exp << std::endl;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor has been called" << std::endl;
}
