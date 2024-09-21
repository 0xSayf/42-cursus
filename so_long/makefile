NAME	:=	so_long
CFLAGS	:=	-Wextra -Wall -Werror
LIBMLX	:=	../mlx
HEADERS	:=	-I ./include -I $(LIBMLX)/include
LIBS	:=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=	src/assets.c src/ft_split.c src/ft_strdup.c src/get_next_line.c src/get_next_line_utils.c src/map_checking.c src/main.c src/hooks.c src/so_long.c src/utils.c src/utils2.c
OBJS	:=	${SRCS:.c=.o}


all : libmlx $(NAME)

libmlx :
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c	so_long.h
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(HEADERS)  -o $(NAME) 

clean :
		rm -rf $(OBJS)
		rm -rf $(LIBMLX)/build

fclean : clean
		rm -rf $(NAME)

re : clean all