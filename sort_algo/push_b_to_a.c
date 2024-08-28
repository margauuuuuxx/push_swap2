/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:20:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 09:32:50 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_elementcost(t_list *element, t_list **lst)
{
	int	cost;

	if (!element)
		return (-1);
	cost = 0;
	if (ft_elementindex(element, lst) < ft_lstsize(*lst))
		cost = ft_elementindex(element, lst);
	else
		cost = ft_lstsize(*lst) - ft_elementindex(element, lst) + 1;
	return (cost);
}

int	ft_findthemaxs(t_list **lst, int max1, int max2)
{
	t_list	*element;
	t_list	*e_max1;
	t_list	*e_max2;

	element = *lst;
	e_max1 = NULL;
	e_max2 = NULL;
	while (element)
	{
		if (element->simplified == max1)
			e_max1 = element;
		else if (element->simplified == max2)
			e_max2 = element;
		element = element->next;
	}
	if (ft_elementcost(e_max1, lst) == -1)
		return (ft_elementindex(e_max2, lst));
	if (ft_elementcost(e_max2, lst) == -1)
		return (ft_elementindex(e_max1, lst));
	if (ft_elementcost(e_max1, lst) > ft_elementcost(e_max2, lst))
		return (ft_elementindex(e_max2, lst));
	else
		return (ft_elementindex(e_max1, lst));
}

int	ft_valueinlst(int value, t_list **lst)
{
	t_list	*element;

	element = *lst;
	while (element)
	{
		if (element->simplified == value)
			return (1);
		element = element->next;
	}
	return (0);
}

void	ft_push_b_to_a(t_list **a, t_list **b, int max_1, int max_2)
{
	int	maxindex;

	if (ft_lstsize(*b) == 1)
		return (ft_instructions("pa", a, b));
	max_1 = ft_lstsize(*b) - 1;
	max_2 = ft_lstsize(*b) - 2;
	while (*b != NULL)
	{
		while (ft_valueinlst(max_1, b) || ft_valueinlst(max_2, b))
		{
			maxindex = ft_findthemaxs(b, max_1, max_2);
			while ((*b)->simplified != max_1 && (*b)->simplified != max_2)
			{
				if (maxindex < ft_lstsize(*b) / 2)
					ft_instructions("rb", a, b);
				else
					ft_instructions("rrb", a, b);
			}
			ft_instructions("pa", a, b);
			if ((*a)->next && (*a)->simplified > ((*a)->next)->simplified)
				ft_instructions("sa", a, b);
		}
		max_1 -= 2;
		max_2 -= 2;
	}
}
