/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:34:35 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 23:02:32 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_cmd	*check(t_cmd *cmd)
{
	char	*str;

	if (!cmd)
		return (NULL);
	if (cmd->pipe == false)
	{
		str = cmd->cmd;
		if (ft_strncmp(str, "$", 1) == 0)
		{
			if (str[1])
			{
				ft_freeing_cmd_node(&cmd);
				return (NULL);
			}
		}
	}
	return (cmd);
}

void	ft_cmd(t_env *env, t_token *sir)
{
	t_cmd	*cmd;
	t_cmd	*tmp;

	if (!sir)
		return ;
	cmd = ft_build_nodes(sir);
	cmd = check(cmd);
	cmd = ft_handle_p_h_a_re(cmd, sir);
	cmd = ft_handle_input(cmd, sir);
	cmd = ft_handle_herdoc(cmd, sir);
	cmd = ft_file_hd(cmd);
	tmp = cmd;
	ft_go_execute(tmp, env);
	ft_freeing_cmd_node(&cmd);
}

t_token	*ft_main(t_env *env)
{
	t_token	*sir;
	char	*line;

	line = readline("minishell % ->|<- ");
	if (!line)
	{
		ft_lst_clr(&env);
		exit(0);
	}
	add_history(line);
	if (ft_qt(line) == 0)
	{
		printf("syntax error\n");
		free(line);
		return (NULL);
	}
	sir = ft_token_init(line);
	free(line);
	if (!sir)
		return (NULL);
	return (sir);
}

void	signal_handler(int k)
{
	(void)k;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
	t_token	*sir;
	t_env	*evv;
	int		c;

	evv = ft_initial_env(evv, env);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		signal(SIGINT, signal_handler);
		sir = ft_main(evv);
		ft_geave_type(sir, env);
		sir = ft_expand_dollar(sir, evv);
		ft_geavo_type(sir, env);
		c = ft_syntax(sir);
		if (c == 1)
			ft_cmd(evv, sir);
		else
			ft_ques_dol(evv, 258);
		ft_lstclear(&sir);
	}
	ft_lst_clr(&evv);
}
