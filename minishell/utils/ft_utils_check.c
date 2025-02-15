/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:57:52 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 22:58:08 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_syntax_cmd(t_cmd *com)
{
	t_cmd	*tmp;
	char	*str;

	if (!com)
		return (0);
	tmp = com;
	str = ft_check_builtins(tmp->cmd);
	if (!strcmp(tmp->cmd, ">") || !strcmp(tmp->cmd, ">>") || !strcmp(tmp->cmd,
			"<") || !strcmp(tmp->cmd, "<<"))
		return (5);
	if (!tmp->path && !str)
	{
		if (opendir(tmp->cmd))
		{
			printf("is a directory\n");
			return (2);
		}
		if (!access(tmp->cmd, X_OK))
			return (1);
		else
			return (0);
	}
	else if ((access(tmp->path, X_OK | F_OK)) && !str)
		return (0);
	return (1);
}

enum e_data_type	ft_type_helper(t_token *type, char **env)
{
	int		i;
	char	*path;
	int		fd;

	i = 0;
	if (!env || !*env)
		return (-1);
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	path = find_path(type->string, env[i]);
	if (path)
	{
		type->path = ft_strdup(path);
		free(path);
		return (CMD);
	}
	fd = open(type->string, O_RDONLY, 0777);
	if (fd != -1)
	{
		close(fd);
		return (FILESS);
	}
	close(fd);
	return (-1);
}

int	ft_syntax_helper(t_token *tmp)
{
	if (!tmp)
		return (0);
	if (tmp->typ_e == PIPE && !tmp->next)
	{
		printf("syntax errors\n");
		return (0);
	}
	else if (tmp->string && *(tmp->string) == '|' && (tmp->string[1]) == '|')
	{
		printf("syntax errors\n");
		return (0);
	}
	else if ((tmp->typ_e >= REDERECTION_INPUT && tmp->typ_e <= HERDOC)
		&& tmp->next && (tmp->next->typ_e >= REDERECTION_INPUT
			&& tmp->next->typ_e <= HERDOC))
	{
		printf("syntax errors\n");
		return (0);
	}
	if (!ft_void_hh_wa_o(tmp))
		return (0);
	return (1);
}
