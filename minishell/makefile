CC = cc 
FLAGS  = -Wall -Wextra -Werror
CFILES = main.c utils/ft_utils_check.c parsing/ft_checking.c utils/ft_utiloss.c utils/t_token_utils2.c \
utils/ft_utils.c utils/creat_and_rem_node.c utils/ft_split.c utils/utils2.c parsing/build_env.c \
parsing/build_cmd_node.c utils/creat_node_cmd.c parsing/ft_go.c parsing/handling.c parsing/t_token.c \
parsing/handle_herdoc.c exec/execution0.c utils/freeing_cmd_node.c parsing/dollar.c  utils/token_utils.c \
builtins/cd.c builtins/echo.c builtins/env.c builtins/pwd.c utils/get_next_line.c utils/get_next_line_utils.c \
exec/redir_manager.c builtins/ft_expand.c exec/exec_utils.c exec/hd_manager.c builtins/unset.c utils/utils3.c \
exec/exec_utils2.c exec/exec_utils3.c exec/exec_utils4.c builtins/exit.c exec/utilsix.c exec/utilsix2.c exec/utilsix3.c exec/utilsix4.c exec/utilix_syntax.c
RD_DYNAMIC = -lreadline -lncurses
OFILES = $(CFILES:.c=.o)
NAME = minishell

all : $(NAME)

%.o : %.c minishell.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OFILES) $(LIBRARY)
	$(CC) $(FLAGS) $(OFILES) $(RD_DYNAMIC) -o $(NAME)

clean : 
		rm -rf $(OFILES)

fclean	:
		rm -rf $(OFILES) $(NAME)

re : fclean all

#-I/Users/user/homebrewinclude -L/Users/user/homebrew/lib