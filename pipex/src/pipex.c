/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:29:13 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/18 22:41:55 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	go_error(void)
{
	write(2, "ERROR : Syntax error \n", ft_strlen("ERROR : Syntax error \n"));
	write(2, "./pipex file1 cmd1 cmd2 file2\n",
		ft_strlen("./pipex file1 cmd1 cmd2 file2\n"));
}

char	*find_path(char *av, char *evp)
{
	char	**paths;
	char	*ret;
	int		i;
	char	**av_cmd;

	i = 0;
	av_cmd = ft_split(av, ' ');
	paths = ft_split(evp + 5, ':');
	while (paths[i])
	{
		ret = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(ret, av_cmd[0]);
		if (access(ret, F_OK && X_OK) == 0)
			return (ret);
		else
			i++;
	}
	free(ret);
	freeing(paths);
	return (NULL);
}

void	go_path(char *cmd, char **evp)
{
	char	*path;
	char	**cmds;
	int		i;

	i = 0;
	while (ft_strnstr(evp[i], "PATH", 4) == NULL)
		i++;
	path = find_path(cmd, evp[i]);
	cmds = ft_split(cmd, 32);
	if (execve(path, cmds, NULL) == -1)
	{
		go_error();
		exit(0);
	}
}
