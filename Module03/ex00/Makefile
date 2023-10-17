SRCS = main.cpp \
	   ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = ./
NAME = Clap
CXX = c++
MYFLAGS = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS = $(MYFLAGS) $(INCLUDE)


all : $(NAME)
	$(CXX) $(CXXFLAGE) $(OBJS) -o $(NAME);

clean :
		rm -f $(OBJS);

fclean : 
		rm -f $(OBJS);
		rm -f $(NAME);

re :
		make fclean;
		make all;
