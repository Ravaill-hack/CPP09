NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_FILES = \
	main.cpp \
	PmergeMe.cpp \

OBJS = $(SRCS_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re