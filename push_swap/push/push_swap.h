/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:24:21 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/11 19:15:06 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../LIBFT/libft.h"
# include <limits.h>

typedef struct push_swap
{
	int	i[1];
	int	k[1];
	int	f[1];
	int	range[1];
	int	j[1];
	int	id_range[1];

}		t_node;

int		go_sort(int *a, int *b, int *size_a, int *size_b);
int		chek_error(char **str, int ac);
void	ft_swap(int *str, int *swp);
void	ft_first_operation(int *b, int *size_b, int e);
void	ft_copy(int *a, int *b, int size);
void	ft_freeing(char **str);
int		ft_range(int size);
int		ft_just_for_norminette(char **maal);
void	ft_norminette_help(int *a, int *b, int *size_a, int *size_b);
int		ft_find(int a, int *str, int size);
void	ft_final_operation(int *a, int *b, int *size_a, int *size_b);
void	ft_pa(int *a, int *b, int *size_a, int *size_b);
void	ft_pb(int *a, int *b, int *size_a, int *size_b);
void	go_5_numbers(int *a, int *b, int *size_a, int *size_b);
void	go_3_numbers(int *a, int *size_a);
void	ft_freee(int *a, int *b);
void	go_4_numbers(int *a, int *b, int *size_a, int *size_b);
void	go_up_to_5(int *a, int *b, int *size_a, int *size_b);
int		the_great(int *a, int size);
void	ft_reverse(int *str, int size);
void	ft_sa(int *a, int size);
void	ft_sb(int *b, int size);
void	ft_ss(int *b, int *a, int size_a, int size_b);
int		ft_chek(char **av);
int		the_small(int *a, int size);
void	ft_help(int *a, int size, int i);
int		ft_chek_double(int *str, int size);
int		*allocation(int ac, char **av);
int		ft_counta(int ac, char **av);
void	ft_rb(int *b, int size);
void	ft_rr(int *a, int *b, int size_a, int size_b);
void	ft_ra(int *a, int size);
void	ft_rra(int *a, int size_a);
void	ft_rrb(int *b, int size);
void	ft_rrr(int *a, int *b, int size_a, int size_b);
int		check_ranking(int *str, int numbers);

#endif