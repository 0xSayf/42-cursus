/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:01:04 by sahamzao          #+#    #+#             */
/*   Updated: 2025/01/06 16:51:41 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is__space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	add_token_to_list(t_token **tokens, t_token *new_token)
{
	t_token	*last;

	if (!*tokens)
		*tokens = new_token;
	else
	{
		last = *tokens;
		while (last->next)
			last = last->next;
		last->next = new_token;
	}
}

char	ft_v(char *line, int *i, int *s, size_t *count)
{
	char	v;

	v = line[*i - *s];
	(*s)--;
	(*count)++;
	return (v);
}

void	ft_str(char *str, char *line, int *s, int *j)
{
	str[*j] = *line;
	(*j)++;
	(*s)--;
}

void	ft_init(int *s, size_t *count, int *j, int *i)
{
	*s = *i;
	*count = 0;
	*j = 0;
}
