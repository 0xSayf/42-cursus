/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:51:19 by sahamzao          #+#    #+#             */
/*   Updated: 2025/01/27 18:45:47 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*qut(char *line, int *s, int *len)
{
	char	*str;
	char	v;
	int		count_q;

	*len = 0;
	count_q = 0;
	while (line[*s])
	{
		if (!count_q && line[*s] && (line[*s] == 34 || line[*s] == 39))
			v = atek(line, s, &count_q);
		while (line[*s] && count_q != 2 && line[*s] != v)
			atek_2(len, s);
		count_q++;
		if (count_q == 2)
			count_q = 0;
		(*s)++;
		if (line[*s] == 32 || line[*s] == '|')
			break ;
	}
	str = malloc(*len + 1);
	str[*len] = '\0';
	return (str);
}

char	*ft_go_handle_quotes(char *line, int *i, char *str)
{
	char	v;
	size_t	count_q;
	int		s;
	int		len;
	int		j;

	str = qut(line, i, &len);
	ft_init(&s, &count_q, &j, i);
	while (len)
	{
		if (!count_q && (line[*i - s] == 34 || line[*i - s] == 39))
			v = ft_v(line, i, &s, &count_q);
		while (len && line[*i - s] != v && count_q != 2)
		{
			ft_str(str, &line[*i - s], &s, &j);
			len--;
		}
		count_q++;
		if (count_q == 2)
			count_q = 0;
		s--;
		if (line[*i - s] == 32 || line[*i - s] == '|')
			break ;
	}
	return (str);
}

int	ft_ff(char *line, int i)
{
	int	z;
	int	f;

	z = i;
	f = 0;
	while (line[z] && line[z] != 39)
		z++;
	while (line[z] && !ft_mojojojo(line[z]))
	{
		if (line[z] == 39)
			f++;
		z++;
	}
	return (f);
}

t_token	*ft_token_init(char *line)
{
	t_token	*tokens;
	char	*str;
	int		i;
	int		f;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		while (is__space(line[i]))
			i++;
		if (ft_strchr("><|", line[i]))
			handle_special_char(line, &i, &tokens);
		else if (line[i] == 34 || line[i] == 39)
			ft_token_init_help(line, &tokens, &i);
		else
		{
			f = ft_ff(line, i);
			str = ft_simple_word(line, &i);
			add_token_to_list(&tokens, ft_creat_node(str, f));
			free(str);
		}
	}
	return (tokens);
}
