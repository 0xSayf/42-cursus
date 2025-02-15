/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:49 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 22:01:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

enum					e_data_type
{
	DELIM,
	STRING,
	CMD,
	PIPE,
	FILESS,
	REDERECTION_INPUT,
	REDERECTION_OUTPUT,
	APPEND_REDIRECT,
	HERDOC,
};

typedef struct env
{
	struct env			*next;
	char				*var;
}						t_env;

typedef struct t_minishell
{
	char				*string;
	enum e_data_type	typ_e;
	bool				qt;
	bool				dou_qt;
	char				*path;
	struct t_minishell	*next;
}						t_token;

typedef struct t_herdoc
{
	char				*delimiter;
	bool				last;
	bool				qt;
	struct t_herdoc		*next;
}						t_herdoc;

typedef struct h_red
{
	char				*the_input_file;
	struct h_red		*next;
}						t_input;

typedef struct s_red
{
	char				*red_out;
	char				*red_append;
	enum e_data_type	typix;
	struct s_red		*next;
}						t_red;

typedef struct t_cmd
{
	char				*cmd;
	char				*path;
	int					num_args;
	char				**args;
	char				*file_hd;
	bool				pipe;
	t_input				*input;
	t_red				*redirection;
	t_herdoc			*herdoc;
	struct t_cmd		*next;
}						t_cmd;

typedef struct h_norm
{
	char				*gg;
	char				*ptr;
	int					k;
	int					i;
}						t_norm;

typedef struct h_vorm
{
	char				*save;
	char				*ret;
}						t_vrom;

void					rl_replace_line(const char *nnhh, int k);
char					**ft_split(char const *s, char c);
int						ft_qt(char *line);
char					*ft_expand_herdoc(char *str, t_env *env);
int						ft_check_dllar(char *str);
int						ft_find(t_env *env, char *line);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
int						ft_syntax(t_token *syntax);
char					*ft_check_builtins(char *str);
char					*ft_strnstr(const char *hay, const char *need,
							size_t len);
char					*find_path(char *av, char *evp);
char					*ft_strjoin(char *s1, char const *s2);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					freeing(char **str);
void					*ft_handle_p_h_a_re(t_cmd *cmd, t_token *tmp);
int						ft_strcmp(char *s1, char *s2);
void					ft_lstclear(t_token **lst);
int						ft_geave_type(t_token *type, char **env);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_lst_clr(t_env **env);
void					ft_go_del(t_env **env, char *line);
int						finder(t_env *env, char *line);
char					**ft_the_args(char **ret, t_token *start, int arg);
int						find(t_env *env, char *line);
int						ft_count_args(t_token *start, t_token *end);
int						count_command_arguments(t_token *current);
t_red					*ft_help_mal(t_red *red);
enum e_data_type		ft_type(t_token *type, char **env);
enum e_data_type		ft_type_helper(t_token *type, char **env);
t_env					*ft_creat_env(char *content);
t_env					*ft_initial_env(t_env *env, char **environment);
t_token					*ft_creat_node(char *content, int f);
t_token					*ft_init_token_node(char **token);
t_input					*ft_cr_input(t_token *token);
t_red					*ft_cr_redir_node(t_token *token,
							enum e_data_type typ_e);
void					*ft_handle_input(t_cmd *cmd, t_token *tmp);
t_cmd					*ft_build_nodes(t_token *token);
t_token					*find_pipe(t_token *find);
t_cmd					*creat_cmd_node(t_token *start, t_token *end);
t_cmd					*ft_handle_herdoc(t_cmd *cmd, t_token *token);
t_cmd					*ft_handle_herdoc(t_cmd *cmd, t_token *token);
void					ft_go_execute(t_cmd *cmd, t_env *env);
void					ft_freeing_cmd_node(t_cmd **cmd);
int						ft_syntax_cmd(t_cmd *cmd);
void					ft_ret_help(char *line, char **retu, int *i,
							int *index);
int						ft_qqtt(char *line);
void					ft_help(char *line, char **retu, int *i, int index);
int						ft_syntax_helper(t_token *tmp);
int						ft_mojojojo(int c);
t_token					*ft_expand_dollar(t_token *token, t_env *env);
char					*ft_strchr(const char *s, int c);
t_token					*ft_token_init(char *line);
void					add_token_to_list(t_token **tokens, t_token *new_token);
void					ft_token_init_help(char *line, t_token **tokens,
							int *i);
char					*ft_go_handle_quotes(char *line, int *i, char *str);
void					handle_special_char(char *line, int *i,
							t_token **tokens);
char					*ft_simple(char *line, int *s, char *str);
int						is__space(char c);
char					*ft_simple_word(char *line, int *i);
void					atek_2(int *len, int *s);
char					atek(char *line, int *s, int *count);
char					ft_v(char *line, int *i, int *s, size_t *count);
void					ft_str(char *str, char *line, int *s, int *j);
void					ft_init(int *s, size_t *count, int *j, int *i);
void					ft_putstr_fd(char *s, int fd);
int						ft_atoi(const char *str);
int						ft_echo(char **arg);
int						ft_env(t_env *env);
int						ft_pwd(void);
int						ft_export(char **arg, t_env *env);
int						ft_cd(t_env *env, char **str);
char					*get_next_line(int fd);
void					*ft_cpy(char *string, char *string1, int n);
int						ft_newline_check(char *string);
int						ft_sstrlen(char *string);
void					allocation_manager(int fd, char **save);
char					*ft_strcat(char *string1, char *string2);
int						handling_redir(t_cmd *cmd, t_env *env, char *str);
void					built_in_cmd(t_cmd *cmd, t_env *env, char *str);
void					bin_exec(t_cmd *cmd, t_env *env, char *str);
t_cmd					*hd_handler(t_cmd *cmd, t_env *env);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_geavo_type(t_token *type, char **env);
char					*file_path(int i);
int						ft_unset(char **args, t_env *env);
t_cmd					*ft_file_hd(t_cmd *cmd);
char					*chch(char *line);
int						ft_hrhr(char *line);
int						ft_check_exp(char *line);
char					*ft_go_join(t_token *tmp, char *ttt);
t_input					*ft_input(char *str);
void					app_redir(t_cmd *cmd, t_env *env, char *str);
void					out_redir(t_cmd *cmd, t_env *env, char *str);
int						in_redir(t_cmd *cmd, t_env *env, char *str);
int						ft_qqtt(char *line);
char					*ft_extract_var(char *line, int *i);
char					*ft_find_var(char *str);
void					ft_exec_0_pipe(t_cmd *cmd, t_env *env);
int						execute_0_pipe(t_cmd *cmd, t_env *env, char *str);
void					ft_exit(char **args);
void					is_the_child(t_cmd *cmd, int *pipeline, int fd[2],
							t_env *env);
void					ft_handle_multp_pipes(t_cmd *tmp, t_env *env);
int						ft_check_dllar(char *str);
int						ft_input_red_help(t_cmd *cmd, t_env *env);
void					ft_openix(t_red *cmd, t_env *env);
int						handling_redir(t_cmd *cmd, t_env *env, char *str);
void					ft_file_herd_unl(t_cmd *cmd);
int						get_exit_status(int e_status);
int						ft_pipe_syscall(int fd[2], t_env *env);
pid_t					ft_fork_syscall(t_env *env);
int						ft_pipline(int fd[2], int pipeline);
char					*ft_itoa(int n);
void					ft_export_primez(char **arg, t_env *env, t_env *tmp,
							int i);
int						ft_exportix(char **arg, t_env *env);
void					ft_ques_dol(t_env *tmp, int i);
void					ft_exe0_help(t_cmd *cmd);
void					ft_bull_sh(t_env *env, t_cmd *cmd, char *str);
void					ft_bull_sht2(t_env *env, t_cmd *cmd);
int						ft_hhh(t_env *env);
void					ft_bull_sht3(t_env *env, t_cmd *cmd, char *str);
void					ft_norm_rvr(t_norm *norm, t_vrom *vrom);
void					ft_rvrvr(t_norm *norm, t_vrom *vrom, t_env *tmp);
char					*hisoka(char *save);
void					ft_waiit_hh(pid_t fok, t_env *env);
char					*tmp_string(t_token *tmp);
int						ft_void_hh_wa_o(t_token *tmp);
int						ft_envsize(t_env *env);
char					**env_to_tab(t_env *env);
void					signalv_handler(int k);
void					ft_0_pipex(t_cmd *cmd, t_env *env, char *str);
void					signal_handlver(int k);
void					ft_check_helper_2(t_cmd *cmd, t_env *env, char *str);
void					ft_close_env(int fd, t_env *env);
void					ft_close_env_2(t_env *env);
void					small_func(t_env *env);
void					ft_small_x(int syn, t_env *env, t_cmd *cmd);
void					ft_fork_helpix(pid_t fok, t_env *env, t_cmd *cmd,
							char *str);
int						ft_openixoo_c(t_red *cmd, t_env *env);
#endif