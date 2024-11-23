# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:16:15 by mtaib             #+#    #+#              #
#    Updated: 2023/10/24 21:44:59 by mtaib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Bureaucrat.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp main.cpp AForm.cpp
OSRC = $(SRC:.cpp=.o)

NAME = ManyForms
CFLAGS = -Wextra -Werror -Wall -std=c++98

%.o:%.cpp  
	c++ -c $(CFLAGS)  $<

all: $(NAME)

$(NAME) :$(OSRC)
		c++ $(CFLAGS) $^ -o $(NAME)

clean :
	@rm -f *.o
fclean :
	@rm -f *.o $(NAME) 
re : fclean all

.PHONY : all clean fclean re
