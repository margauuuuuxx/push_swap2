/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:09:34 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/08 12:51:59 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this function prints a number in hexadecimal format

#include "../includes/ft_printf.h"

static void	ft_conversion(char *result)
{
	int	i;

	i = 0;
	while (result[i] && ft_isalpha(result[i]))
	{
		result[i] = ft_tolower(result[i]);
		i++;
	}
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_hexa(int n, char c)
{
	char		*result;
	int			len;

	len = ft_len(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	result[len] = '\0';
	while (n != 0)
	{
		if ((n % 16) < 10)
			result[len - 1] = (n % 16) + 48;
		else
			result[len - 1] = (n % 16) + 55;
		n /= 16;
		len--;
	}
	if (c == 'x')
		ft_conversion(result);
	ft_putstr2(result);
	return (len - 1);
}
