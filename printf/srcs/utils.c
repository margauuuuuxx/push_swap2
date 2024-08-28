/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:15:35 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/19 12:54:59 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr2(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr2("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		count += ft_putchar2('-');
		n *= -1;
		ft_printnbr(n);
	}
	else if (n <= 9)
		count += ft_putchar2(n + 48);
	else
	{
		ft_printnbr(n / 10);
		ft_printnbr(n % 10);
	}
	return (count);
}
