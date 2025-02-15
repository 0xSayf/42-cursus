/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:39 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:40 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_pwd(void)
{
	char	*str_pwd;

	str_pwd = getcwd(NULL, 0);
	if (str_pwd)
	{
		ft_putstr_fd(str_pwd, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(str_pwd);
		return (0);
	}
	return (1);
}
