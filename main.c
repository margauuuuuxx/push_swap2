/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:43:27 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/28 16:34:41 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_istrim(t_list **a)
{
	t_list	*element;

	if (!a)
		return (0);
	element = *a;
	while (element)
	{
		if (element->next
			&& ft_atoi(element->content) > ft_atoi((element->next)->content))
			return (0);
		element = element->next;
	}
	return (1);
}

void	ft_freecontent(void *content)
{
	free(content);
}

void	ft_free_spl(char **spl)
{
	int	i;

	if (!spl)
		return ;
	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

void	ft_parsing(t_list **a, char **argv, int argc)
{
	char	**spl;
	int		i;
	int		j;

	i = 1;
	spl = NULL;
	while (i < argc)
	{
		spl = ft_split(argv[i], ' ');
		j = 0;
		while (spl[j] != 0)
		{
			if (!ft_checkerros(spl[j], a))
			{
				write(2, "Error\n", 6);
				ft_lstclear(a, ft_freecontent);
				exit(1);
			}
			ft_lstadd_back(a, ft_lstnew(ft_strdup(spl[j])));
			j++;
		}
		ft_free_spl(spl);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_parsing(&a, argv, argc);
	if (ft_istrim(&a))
		return (ft_lstclear(&a, ft_freecontent), 0);
	ft_simplified(&a);
	ft_algorithme_03(&a, &b);
	ft_lstclear(&a, ft_freecontent);
	ft_lstclear(&b, ft_freecontent);
	system("leaks push_swap");
	return (0);
}
