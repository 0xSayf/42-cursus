/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:29:01 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/05 21:45:32 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find(t_env *env, char *line)
{
	t_env	*tmp;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, line) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char	*ft_go_join(t_token *tmp, char *ttt)
{
	int		i;
	int		flg;
	char	c[1];
	char	*ptr;

	i = 1;
	flg = 0;
	while (ttt[i] && ttt[i] != 32)
	{
		if ((ttt[i] == 34 || ttt[i] == 39) || flg == 1)
		{
			c[0] = ttt[i];
			ptr = tmp->string;
			tmp->string = ft_strjoin(ptr, &c[0]);
			free(ptr);
			flg = 1;
		}
		i++;
	}
	return (tmp->string);
}

int	ft_mojojojo(int c)
{
	return ((c >= 0 && c <= 33) || (c >= 35 && c <= 38) || (c >= 40
			&& c <= 127));
}
