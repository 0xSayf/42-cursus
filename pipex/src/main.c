/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:29:05 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/18 22:42:47 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	is_the_child(char **av, int fd[2], char **evp)
{
	int	file;

	file = open(av[1], O_RDWR, 0777);
	if (file == -1)
	{
		write(2, "ERROR : Invalid File Descriptor",
			ft_strlen("ERROR : Invalid File Descriptor"));
		exit(0);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(file, 0);
	go_path(av[2], evp);
}

void	is_the_parent(char **av, int fd[2], char **evp)
{
	int	doc;

	doc = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (doc == -1)
	{
		write(2, "ERROR : Invalid File Descriptor",
			ft_strlen("ERROR : Invalid File Descriptor"));
		exit(0);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(doc, 1);
	go_path(av[3], evp);
}

int	main(int ac, char **av, char **evp)
{
	int		fd[2];
	pid_t	check;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			perror("5roj t9awd");
		check = fork();
		if (check == -1)
			perror("5roj t9wd");
		else if (check == 0)
			is_the_child(av, fd, evp);
		is_the_parent(av, fd, evp);
	}
	else
		go_error();
}
