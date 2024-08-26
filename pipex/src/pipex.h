/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:29:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/18 22:35:28 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	is_the_child(char **av, int fd[2], char **evp);
void	is_the_parent(char **av, int fd[2], char **evp);
void	freeing(char **str);
char	*find_path(char *av, char *evp);
void	go_path(char *cmd, char **evp);
void	go_error(void);

#endif
