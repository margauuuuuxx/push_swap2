/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:55:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/19 13:02:52 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_hexa(int n, char c);
int	ft_putptr(unsigned long long ptr);
int	ft_printnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_putchar2(char c);
int	ft_putstr2(char *str);

#endif