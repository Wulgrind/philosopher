#Compilation

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INC = -I.

#VALUES

NAME	= philo

#SOURCES

FILES	=	ft_createphilo.c		\
			ft_parsing.c		\
			ft_death.c		\
			ft_time.c		\
			ft_atoi.c		\
			ft_newphilo.c		\
			main.c		\

OBJS	= ${FILES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
		@cc $(OBJS) -I./includes -I./usr/include -Wall -Wextra -Werror -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
				rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
