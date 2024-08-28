/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:43:49 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 13:57:24 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/includes/ft_printf.h"
# include <stdlib.h>

typedef struct s_data
{
	int	lstsize;
	int	closerindex;
	int	cost;
	int	element_cost;
}		t_data;

// printf lst
void	ft_printlst(t_list **a);

// sort algo
// algo utils
int		ft_find_closerindex(t_list **lst, int chunk, int *array);
// algo00
t_list	*ft_findmin(t_list **lst);
int		ft_check_begin_min(t_list **lst);
int		ft_elementindex(t_list *element, t_list **lst);
void	ft_algorithme_00(t_list **a, t_list **b);
// algo01
void	ft_last3(t_list **a, t_list **b);
int		ft_intchr(int i, int *array, int size);
void	ft_algorithme_01(t_list **a, t_list **b);
void	ft_algorithme_03(t_list **a, t_list **b);
// simplified
void	ft_simplified(t_list **a);
// push a to b
void	ft_push_a_to_b(t_list **a, t_list **b, int *array);
int		ft_element_lower(t_list **list, int max);
int		ft_frst_lower(t_list **lst, int chunk);
// push b to a
void	ft_push_b_to_a(t_list **a, t_list **b, int max_1, int max_2);
int		ft_elementcost(t_list *element, t_list **lst);

// sort operations
// sorto print
void	ft_s(t_list **a, char pile);
void	ft_ss(t_list **a, t_list **b);
void	ft_p(t_list **a, t_list **b, char pile);
void	ft_r(t_list **a, char pile);
void	ft_rr(t_list **a, t_list **b);
// sorto utils
void	ft_rev_r(t_list **a, char pile);
void	ft_instructions(char *str, t_list **a, t_list **b);
// sorto
void	ft_swap(t_list **a);
void	ft_push(t_list **a, t_list **b);
void	ft_rotate(t_list **a);
void	ft_reverse_rotate(t_list **lst);
t_list	*ft_last_element(t_list *lst);

//checkerrors
int		ft_checkerros(char *element, t_list **lst);

// main
int		ft_istrim(t_list **a);

#endif