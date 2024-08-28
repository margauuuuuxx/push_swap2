/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplified.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:20:25 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 09:32:55 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_list_tab(t_list *lst)
{
	int	*numbers;
	int	lstsize;
	int	i;

	lstsize = ft_lstsize(lst);
	numbers = malloc(lstsize * sizeof(int));
	i = 0;
	while (lst)
	{
		numbers[i] = ft_atoi(lst->content);
		lst = lst->next;
		i++;
	}
	return (numbers);
}

void	ft_trimtab(int *numbers, int tabsize)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < tabsize)
	{
		j = 0;
		while (i + j < tabsize)
		{
			if (numbers[i + j] < numbers[i])
			{
				k = numbers[i + j];
				numbers[i + j] = numbers[i];
				numbers[i] = k;
			}
			j++;
		}
		i++;
	}
}

int	ft_findelementinarray(void *element, int *numbers)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_atoi(element) == numbers[i])
			break ;
		i++;
	}
	return (i);
}

void	ft_lst_spfelement(t_list **a, int *numbers)
{
	t_list	*element;

	element = *a;
	while (element)
	{
		element->simplified = ft_findelementinarray(element->content, numbers);
		element = element->next;
	}
}

void	ft_simplified(t_list **a)
{
	int	*numbers;

	numbers = ft_list_tab(*a);
	ft_trimtab(numbers, ft_lstsize(*a));
	ft_lst_spfelement(a, numbers);
	free(numbers);
}
