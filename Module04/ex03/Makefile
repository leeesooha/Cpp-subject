SRCS = main.cpp \
	   AMateria.cpp \
	   Ice.cpp \
	   Character.cpp \
	   MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I ./
NAME = interface
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
