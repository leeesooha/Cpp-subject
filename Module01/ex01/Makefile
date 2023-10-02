NAME = zombiehorde
SRCS =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I .
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDE)

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