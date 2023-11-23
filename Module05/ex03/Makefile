SRCS = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I ./
NAME = a.out
CXX = c++
MYFLAGS = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS = $(MYFLAGS) $(INCLUDE)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME);

clean :
		rm -f $(OBJS);
		rm -f *_shrubbery;

fclean : 
		rm -f $(OBJS);
		rm -f *_shrubbery;
		rm -f $(NAME);

re :
		make fclean;
		make all;
