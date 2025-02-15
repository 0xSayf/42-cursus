/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:51:05 by sahamzao          #+#    #+#             */
/*   Updated: 2025/02/07 22:08:37 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_token_init_help(char *line, t_token **tokens, int *i)
{
	int		z;
	int		f;
	t_token	*tmp;
	char	*ptr;
	char	*str;

	z = 0;
	ptr = line + *i;
	z = *i;
	f = 0;
	while (line[z] && !ft_mojojojo(line[z]))
	{
		if (line[z] == 39)
			f++;
		z++;
	}
	z = 0;
	str = ft_go_handle_quotes(ptr, &z, str);
	*i = *i + z;
	add_token_to_list(tokens, ft_creat_node(str, f));
	free(str);
}

void	handle_special_char(char *line, int *i, t_token **tokens)
{
	if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
		{
			add_token_to_list(tokens, ft_creat_node(">>", 0));
			(*i)++;
		}
		else
			add_token_to_list(tokens, ft_creat_node(">", 0));
	}
	else if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
		{
			add_token_to_list(tokens, ft_creat_node("<<", 0));
			(*i)++;
		}
		else
			add_token_to_list(tokens, ft_creat_node("<", 0));
	}
	else if (line[*i] == '|')
		add_token_to_list(tokens, ft_creat_node("|", 0));
	(*i)++;
}

char	*ft_simple(char *line, int *s, char *str)
{
	int	len;
	int	j;

	j = 0;
	len = 0;
	while (line[*s] && !ft_strchr("\"' |><", line[*s]))
	{
		len++;
		(*s)++;
	}
	str = malloc(len + 1);
	str[len] = '\0';
	j = 0;
	while (len)
	{
		str[j] = line[*s - len];
		j++;
		len--;
	}
	return (str);
}

char	*ft_help_me(char *line, int *i, char *str, int s)
{
	char	*tt;
	char	*ggg;
	int		z;
	char	*ptr;

	if (line + s)
		ggg = line + s;
	z = 0;
	tt = ft_go_handle_quotes(ggg, &z, tt);
	*i = z + s;
	ptr = ft_strjoin(str, tt);
	free(str);
	return (ptr);
}

char	*ft_simple_word(char *line, int *i)
{
	char	*str;
	char	*ptr;
	int		s;

	str = ft_simple(line, i, str);
	s = *i;
	if (line[s] == 34 || line[s] == 39)
	{
		ptr = ft_help_me(line, i, str, s);
		return (ptr);
	}
	return (str);
}
