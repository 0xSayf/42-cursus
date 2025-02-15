/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilix_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:33 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:34 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_close_env(int fd, t_env *env)
{
	close(fd);
	ft_ques_dol(env, 1);
	perror("No File1");
}

void	ft_close_env_2(t_env *env)
{
	printf("permisions denied\n");
	ft_ques_dol(env, 1);
	exit(1);
}

void	small_func(t_env *env)
{
	printf(" command not found\n");
	ft_ques_dol(env, 127);
}

void	ft_small_x(int syn, t_env *env, t_cmd *cmd)
{
	if (syn != 5 && syn != 2)
		small_func(env);
	else if (syn == 2)
		ft_ques_dol(env, 126);
}

void	ft_fork_helpix(pid_t fok, t_env *env, t_cmd *cmd, char *str)
{
	if (fok == -1)
	{
		perror("ERROR in minishell\n");
		ft_ques_dol(env, 1);
		return ;
	}
	if (fok == 0)
		ft_bull_sht3(env, cmd, str);
	else
		ft_waiit_hh(fok, env);
}
