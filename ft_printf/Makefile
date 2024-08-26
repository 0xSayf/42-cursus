CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putaddr.c ft_putnbr.c ft_putnbr_u.c
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

all: ${NAME}

$(NAME): $(OFILES)
	ar -rc ${NAME} ${OFILES}
	
clean : 
	rm -rf	${OFILES}

fclean :
	rm -rf ${NAME} ${OFILES}

re: fclean all
