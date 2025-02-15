/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsix2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:45 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:46 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_bull_sh(t_env *env, t_cmd *cmd, char *str)
{
	bin_exec(cmd, env, str);
	exit(ft_hhh(env));
}

void	ft_bull_sht2(t_env *env, t_cmd *cmd)
{
	char	*str;

	str = ft_check_builtins(cmd->args[0]);
	execute_0_pipe(cmd, env, str);
	exit(0);
}

void	ft_bull_sht3(t_env *env, t_cmd *cmd, char *str)
{
	if (execute_0_pipe(cmd, env, str) == -1)
		exit(1);
}

void	ft_waiit_hh(pid_t fok, t_env *env)
{
	int	i;

	waitpid(fok, &i, 0);
	i = get_exit_status(i);
	ft_ques_dol(env, i);
}

char	*hisoka(char *save)
{
	char	*ret;

	save = ft_strcat(save, "$");
	ret = ft_strcat(ret, save);
	free(save);
	return (ret);
}
