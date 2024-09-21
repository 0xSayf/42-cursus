/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:01:09 by sahamzao          #+#    #+#             */
/*   Updated: 2024/09/11 15:01:03 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		size;
	char	*ptr;

	if (s1 == NULL)
	{
		return (NULL);
	}
	i = 0;
	size = ft_sstrlen(s1) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

void	ft_inv(void)
{
	write(2, "invalid file !! \n", ft_sstrlen("invalid file !! \n"));
	exit(0);
}

int	ft_dotber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			return (i);
		i++;
	}
	write(2, "invalid file !!\n", ft_sstrlen("ivalid file !!\n"));
	exit(0);
}
