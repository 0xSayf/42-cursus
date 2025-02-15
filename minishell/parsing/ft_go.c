/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:59:49 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/10 19:55:04 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_geave_type(t_token *type, char **env)
{
	t_token	*tmp;

	if (!type || !type->string)
		return (0);
	tmp = type;
	while (tmp)
	{
		tmp->typ_e = ft_type(tmp, env);
		if (tmp->typ_e == HERDOC && tmp->next)
		{
			tmp = tmp->next;
			tmp->typ_e = DELIM;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_geavo_type(t_token *type, char **env)
{
	t_token	*tmp;

	if (!type || !type->string)
		return (0);
	tmp = type;
	while (tmp)
	{
		if (tmp->typ_e == CMD)
			free(tmp->path);
		tmp->typ_e = ft_type(tmp, env);
		tmp = tmp->next;
	}
	return (1);
}

char	*file_path(int i)
{
	char	*ptr;
	char	*str;

	ptr = "/tmp/file";
	str = ft_strjoin(ptr, "0");
	while (i)
	{
		str = ft_strcat(str, "0");
		i--;
	}
	return (str);
}

char	*tmp_string(t_token *tmp)
{
	free(tmp->string);
	return (ft_strdup(" "));
}

int	ft_openixoo_c(t_red *cmd, t_env *env)
{
	if (cmd->typix == REDERECTION_OUTPUT)
	{
		open(cmd->red_out, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (access(cmd->red_out, R_OK))
		{
			printf("permisions denied\n");
			ft_ques_dol(env, 1);
			return (-1);
		}
	}
	else if (cmd->typix == APPEND_REDIRECT)
	{
		open(cmd->red_append, O_CREAT | O_RDWR | O_APPEND, 0777);
		if (access(cmd->red_append, R_OK))
		{
			printf("permisions denied\n");
			ft_ques_dol(env, 1);
			return (-1);
		}
	}
	return (1);
}
