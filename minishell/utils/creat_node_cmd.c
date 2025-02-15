/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:57:46 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/07 20:52:13 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*find_pipe(t_token *find)
{
	t_token	*tmp;

	if (!tmp)
		return (NULL);
	tmp = find;
	while (tmp)
	{
		if (tmp->typ_e == PIPE)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	**ft_the_args(char **ret, t_token *start, int arg)
{
	t_token	*s;
	size_t	i;

	if (!ret || !start || !arg)
		return (NULL);
	s = start;
	i = 0;
	while (s && (i < arg) && (s->typ_e != PIPE) && (s->typ_e != HERDOC)
		&& (s->typ_e != APPEND_REDIRECT) && (s->typ_e != REDERECTION_INPUT)
		&& (s->typ_e != REDERECTION_OUTPUT))
	{
		ret[i] = malloc(ft_strlen(s->string) + 1);
		ret[i][ft_strlen(s->string)] = '\0';
		if (s->typ_e != DELIM && s->string)
		{
			ft_memcpy(ret[i], s->string, ft_strlen(s->string) + 1);
			i++;
		}
		s = s->next;
	}
	ret[i] = NULL;
	return (ret);
}

t_cmd	*creat_cmd_node(t_token *start, t_token *end)
{
	t_cmd	*new;

	if (!start)
		return (NULL);
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (!end)
		new->pipe = false;
	else
		new->pipe = true;
	new->cmd = ft_strdup(start->string);
	new->num_args = ft_count_args(start, end);
	new->args = malloc(sizeof(char *) * (new->num_args + 1));
	new->args = ft_the_args(new->args, start, new->num_args);
	if (start->path)
		new->path = ft_strdup(start->path);
	else
		new->path = NULL;
	new->input = NULL;
	new->file_hd = NULL;
	new->herdoc = NULL;
	new->redirection = NULL;
	new->next = NULL;
	return (new);
}

t_input	*ft_cr_input(t_token *token)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->the_input_file = ft_strdup(token->string);
	input->next = NULL;
	return (input);
}

t_red	*ft_cr_redir_node(t_token *token, enum e_data_type typ_e)
{
	t_red	*red;

	red = malloc(sizeof(t_red));
	if (!red)
		return (NULL);
	red->typix = typ_e;
	if (typ_e == REDERECTION_OUTPUT)
	{
		red->red_out = ft_strdup(token->string);
		red->red_append = NULL;
	}
	else if (typ_e == APPEND_REDIRECT)
	{
		red->red_append = ft_strdup(token->string);
		red->red_out = NULL;
	}
	red->next = NULL;
	return (red);
}
