/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorto_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:35:08 by qalpesse          #+#    #+#             */
/*   Updated: 2024/08/28 10:24:06 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_s(t_list **a, char pile)
{
	ft_swap(a);
	ft_printf("s%c", pile);
	write(1, "\n", 1);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss");
	write(1, "\n", 1);
}

void	ft_p(t_list **a, t_list **b, char pile)
{
	ft_push(a, b);
	ft_printf("p%c", pile);
	write(1, "\n", 1);
}

void	ft_r(t_list **a, char pile)
{
	ft_rotate(a);
	ft_printf("r%c", pile);
	write(1, "\n", 1);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr");
	write(1, "\n", 1);
}
