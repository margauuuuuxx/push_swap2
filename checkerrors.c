/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:43:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 09:32:06 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	ft_check_elementisdigit(char *element)
{
	int	i;

	i = 0;
	while (element[i])
	{
		if (!ft_isdigit(element[i]) && element[i] != '-')
			return (0);
		if (element[i] == '-' && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_elementisint(const char *str)
{
	int			i;
	int			is_neg;
	long int	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if (res > 2147483647 || res < -2147483648)
			return (0);
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_atoi(s1) - ft_atoi(s2) == 0)
		return (0);
	else
		return (1);
}

int	ft_checklstfind(const char *content, t_list **lst)
{
	t_list	*lst_dup;

	lst_dup = *lst;
	while (lst_dup)
	{
		if (!ft_strcmp(content, lst_dup->content))
			return (0);
		lst_dup = lst_dup->next;
	}
	return (1);
}

int	ft_checkerros(char *element, t_list **lst)
{
	if (!ft_check_elementisdigit(element))
		return (0);
	if (!ft_check_elementisint(element))
		return (0);
	if (!ft_checklstfind(element, lst))
		return (0);
	return (1);
}
