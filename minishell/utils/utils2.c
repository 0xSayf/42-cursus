/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:59:39 by sahamzao          #+#    #+#             */
/*   Updated: 2025/01/26 20:28:51 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n || !s1 || !s2)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*chch(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	str = malloc(i + 1);
	j = 0;
	while (j < i && line[j] && line[j] != '=')
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	finder(t_env *env, char *line)
{
	t_env	*tmp;
	char	*ptr;
	char	*str;

	if (!env)
		return (0);
	tmp = env;
	while (tmp)
	{
		str = chch(tmp->var);
		ptr = chch(line);
		if (str && ptr && !ft_strcmp(str, ptr))
		{
			free(str);
			free(ptr);
			return (1);
		}
		free(str);
		free(ptr);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_go_del(t_env **env, char *line)
{
	t_env	*tmp;
	t_env	*last;

	if (!env || !*env)
		return ;
	tmp = *env;
	if (ft_strncmp(tmp->var, line, 2) == 0)
	{
		*env = tmp->next;
		free(tmp->var);
		free(tmp);
		return ;
	}
	while (tmp && tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
		if (ft_strncmp(tmp->var, line, 2) == 0)
		{
			last->next = tmp->next;
			free(tmp->var);
			free(tmp);
			return ;
		}
	}
}

char	*ft_check_builtins(char *str)
{
	char	*ptr[8];
	int		i;

	if (!str)
		return (NULL);
	ptr[0] = "exit";
	ptr[1] = "export";
	ptr[2] = "unset";
	ptr[3] = "cd";
	ptr[4] = "env";
	ptr[5] = "echo";
	ptr[6] = "pwd";
	ptr[7] = NULL;
	i = 0;
	while (ptr[i])
	{
		if (ft_strcmp(ptr[i], str) == 0)
			return (ptr[i]);
		i++;
	}
	return (NULL);
}
