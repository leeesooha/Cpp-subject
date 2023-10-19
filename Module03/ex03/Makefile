SRCS = main.cpp \
	   ClapTrap.cpp \
	   ScavTrap.cpp	\
	   FragTrap.cpp \
	   DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I ./
NAME = diamondtrap
CXX = c++
MYFLAGS = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS = $(MYFLAGS) $(INCLUDE)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME);

clean :
		rm -f $(OBJS);

fclean : 
		rm -f $(OBJS);
		rm -f $(NAME);

re :
		make fclean;
		make all;
