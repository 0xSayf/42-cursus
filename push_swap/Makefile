CC = cc 
FLAGS = -Wall -Wextra -Werror
CFILES = push/utils.c push/main.c push/push_swap.c push/utils2.c push/push.c push/reverse.c push/rotate.c push/swaping.c push/sorting_up_to_5_numbers.c push/sorting_5_numbers.c
NAME = push_swap
OFILES = $(CFILES:.c=.o)
LIBRARY = libft/libft.a

all : $(NAME)

$(LIBRARY) :
	cd libft && (MAKE)

%.o : %.c push/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES) $(LIBRARY)
	$(CC) $(FLAGS) $(OFILES) $(LIBRARY) -o $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OFILES)

fclean :
	$(MAKE) fclean -C ./libft
	rm -rf $(OFILES) $(NAME)

re : fclean all
