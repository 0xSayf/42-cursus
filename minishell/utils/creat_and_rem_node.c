/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_and_rem_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:38:37 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/07 21:52:34 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_creat_node(char *content, int f)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->string = ft_strdup(content);
	new->path = NULL;
	new->dou_qt = false;
	new->next = NULL;
	if (f % 2 == 0)
		new->qt = false;
	else
		new->qt = true;
	return (new);
}

t_env	*ft_creat_env(char *content)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->var = ft_strdup(content);
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_token **lst)
{
	t_token	*curr;
	t_token	*ne;

	if (!lst || !*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		ne = curr->next;
		free(curr->string);
		if (curr->path)
			free(curr->path);
		free(curr);
		curr = ne;
	}
	*lst = NULL;
}

void	ft_lst_clr(t_env **env)
{
	t_env	*curr;
	t_env	*ne;

	if (!env)
		return ;
	curr = *env;
	while (curr)
	{
		ne = curr->next;
		free(curr->var);
		free(curr);
		curr = ne;
	}
	*env = NULL;
}
