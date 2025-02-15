/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:36:00 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:36:01 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	in_redir(t_cmd *cmd, t_env *env, char *str)
{
	int	fd;

	if (access(cmd->input->the_input_file, F_OK))
	{
		printf("NO    FILE\n");
		ft_ques_dol(env, 1);
		exit(1);
	}
	if (access(cmd->input->the_input_file, R_OK))
	{
		printf("permisions denied\n");
		ft_ques_dol(env, 1);
		exit(1);
	}
	fd = open(cmd->input->the_input_file, O_RDONLY, 0777);
	if (fd < 0)
	{
		printf("No file\n");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void	out_redir(t_cmd *cmd, t_env *env, char *str)
{
	int	fd;

	fd = open(cmd->redirection->red_out, O_CREAT | O_WRONLY, 0777);
	if (access(cmd->redirection->red_out, W_OK | R_OK))
	{
		printf("permisions denied\n");
		ft_ques_dol(env, 1);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	app_redir(t_cmd *cmd, t_env *env, char *str)
{
	int	fd;

	fd = open(cmd->redirection->red_append, O_CREAT | O_WRONLY | O_APPEND,
			0777);
	if (access(cmd->redirection->red_append, W_OK | R_OK))
	{
		printf("permisions denied\n");
		ft_ques_dol(env, 1);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

t_input	*ft_input(char *str)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->the_input_file = ft_strdup(str);
	input->next = NULL;
	return (input);
}

int	ft_qqtt(char *line)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (line[i])
	{
		if (line[i] == 39)
			return (1);
		i++;
	}
	return (0);
}
