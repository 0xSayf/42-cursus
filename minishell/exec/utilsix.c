/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:39 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:40 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_cpny(long long on, char *ptr, int stop, int len)
{
	int	i;

	i = len - 1;
	while (i >= stop)
	{
		ptr[i] = (on % 10) + 48;
		on = on / 10;
		i--;
	}
	ptr[len] = '\0';
	return (ptr);
}

static int	ft_lenagt(long long oi)
{
	int	count;

	count = 0;
	if (oi < 0)
		count++;
	if (oi < 0)
		oi = -oi;
	if (oi == 0)
		return (1);
	while (oi > 0)
	{
		oi = oi / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long long	on;
	int			stop;

	stop = 0;
	on = (long long)n;
	len = ft_lenagt(on);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (on < 0)
	{
		ptr[0] = '-';
		on *= -1;
		stop = 1;
	}
	ptr = ft_cpny(on, ptr, stop, len);
	return (ptr);
}

void	ft_ques_dol(t_env *tmp, int i)
{
	char	*cc;
	char	*gg;
	t_env	*env;

	env = tmp;
	gg = ft_itoa(i);
	cc = ft_strjoin("?=", gg);
	free(gg);
	ft_exportix(&cc, env);
	free(cc);
}

void	ft_exe0_help(t_cmd *cmd)
{
	if (cmd->path)
		execve(cmd->path, cmd->args, NULL);
}
