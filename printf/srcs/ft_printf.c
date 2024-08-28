/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:09:31 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/07 15:24:19 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'x' || c == 'X')
		count += ft_hexa(va_arg(args, int), c);
	else if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'c')
		count += ft_putchar2(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr2(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	else
		count += ft_putchar2(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(args, str[i]);
		}
		else if (ft_isprint(str[i]))
			count += ft_putchar2(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
