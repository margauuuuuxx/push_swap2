/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:20:14 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 09:32:46 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_chunk(t_list **lst)
{
	if (ft_lstsize(*lst) > 200)
		return (8);
	else
		return (4);
}

void	ft_verif_topvalue_median(t_list **a, t_list **b, int median, int chunk)
{
	if (*b == NULL)
		return ;
	if ((*b)->simplified < median)
	{
		if (!ft_frst_lower(a, chunk))
			ft_instructions("rr", a, b);
		else
			ft_instructions("rb", a, b);
	}
}

int	ft_element_lower(t_list **list, int max)
{
	t_list	*element;

	element = *list;
	while (element)
	{
		if (element->simplified < max)
			return (1);
		element = element->next;
	}
	return (0);
}

int	ft_frst_lower(t_list **lst, int chunk)
{
	if (*lst == NULL)
		return (0);
	if ((*lst)->simplified < chunk)
		return (1);
	else
		return (0);
}

void	ft_push_a_to_b(t_list **a, t_list **b, int *array)
{
	int	chunk_i;
	int	chunk;
	int	median;

	chunk = 0;
	chunk_i = ft_lstsize(*a) / ft_chunk(a);
	while (ft_lstsize(*a) > 5)
	{
		median = (chunk + (chunk + chunk_i)) / 2;
		chunk += chunk_i;
		while (ft_element_lower(a, chunk) && ft_lstsize(*a) > 5)
		{
			while (!ft_frst_lower(a, chunk)
				|| ft_intchr((*a)->simplified, array, 5))
			{
				if (ft_find_closerindex(a, chunk, array) < ft_lstsize(*a) / 2)
					ft_instructions("ra", a, b);
				else
					ft_instructions("rra", a, b);
			}
			ft_instructions("pb", a, b);
			ft_verif_topvalue_median(a, b, median, chunk);
		}
	}
}
