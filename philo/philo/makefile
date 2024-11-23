CC = cc 
CFILES = main.c philos.c utils.c utils2.c
NAME = philo
FLAGS = -Wall -Wextra -Werror
OFILES = $(CFILES:.c=.o)

all : $(NAME)

%.o : %.c philosophers.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean :
	rm -rf $(OFILES)

fclean :
	rm -rf $(OFILES) $(NAME)

re : fclean all