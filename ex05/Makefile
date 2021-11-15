CXX			:=	clang++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 --pedantic
# CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 --pedantic -D COLORLESS=1
NAME		:=	exe
SRCS		:=	main.cpp \
				Bureaucrat.cpp BureaucratExceptions.cpp \
				Form.cpp FormExceptions.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp \
				OfficeBlock.cpp \
				StringList.cpp \
				CentralBureaucracy.cpp

OBJS		:=	$(SRCS:.cpp=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)
$(NAME)		:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean		:
	$(RM) -rf $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all
