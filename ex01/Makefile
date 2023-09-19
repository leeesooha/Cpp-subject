#compile flags
#c++ -std=c++98 -Wall -Wextra -Werror

#namespace, friend keyword 금지

#header file에 function작성시 0점
#header 중복include 주의
#cpp파일 개수는 제한 없다.
NAME = phonebook
SRCS = 	main.cpp \
		$(NAME).cpp \
		contact.cpp
INCLUDE = -I ./$(NAME).hpp -I ./contact.hpp
CXX = c++
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