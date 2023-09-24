NAME = megaphone
SRCS = 	main.cpp \
		$(NAME).cpp
CXX = c++
INCLUDE = -I ./$(NAME).hpp
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror $(INCLUDE)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS);

fclean :
	rm -f $(OBJS);
	rm -f $(NAME);

re :
	make fclean;
	make all;