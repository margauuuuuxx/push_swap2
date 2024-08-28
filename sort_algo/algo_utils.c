/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:27:16 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 09:32:31 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_begin_max(t_list **lst)
{
	int		value;
	t_list	*tmp;

	value = ft_atoi((*lst)->content);
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_begin_oneofmax(t_list **lst)
{
	int		value;
	int		nbr_sup;
	t_list	*tmp;

	value = ft_atoi((*lst)->content);
	nbr_sup = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > value)
			nbr_sup += 1;
		tmp = tmp->next;
	}
	if (nbr_sup > 1)
		return (0);
	else
		return (1);
}

int	ft_find_closerindex(t_list **lst, int chunk, int *array)
{
	int		index;
	t_list	*element;
	int		cost;
	int		new_cost;

	index = -1;
	cost = 100000000;
	element = *lst;
	while (element)
	{
		if (element->simplified < chunk
			&& !ft_intchr(element->simplified, array, 5))
		{
			new_cost = ft_elementcost(element, lst);
			if (new_cost < cost)
			{
				cost = new_cost;
				index = ft_elementindex(element, lst);
			}
		}
		element = element->next;
	}
	return (index);
}
