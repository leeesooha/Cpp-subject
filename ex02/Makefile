NAME = Account
SRCS = 	tests.cpp \
		$(NAME).cpp
INCLUDE = -I ./$(NAME).hpp -I ./Account.hpp
CXX = c++
# CXXFLAGS = -std=c++98 $(INCLUDE)
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