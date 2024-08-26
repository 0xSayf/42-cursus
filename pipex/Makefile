CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = src/pipex.c src/main.c
OBJ = $(SRCS:.c=.o)
NAME = pipex
LIBRARY = libft/libft.a

all : $(NAME)

$(LIBRARY) :
	cd libft && $(MAKE)

%.o : %.c src/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY)  -o $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean : 
	$(MAKE) fclean -C ./libft
	rm -rf $(OBJ) $(NAME)

re : fclean all
