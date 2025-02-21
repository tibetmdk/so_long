/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:03:55 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/20 17:43:15 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/so_long.h"

static int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

static int	ft_print_s(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s == NULL)
		return (ft_print_s("(null)"));
	while (s[i] != '\0')
	{
		count += ft_print_c(s[i]);
		i++;
	}
	return (count);
}

static int	ft_print_i_d(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_print_s("-2147483648"));
	if (n < 0)
	{
		count += ft_print_c('-');
		n *= -1;
	}
	if (n < 10)
		count += ft_print_c(n + '0');
	else
	{
		count += ft_print_i_d(n / 10);
		count += ft_print_c(n % 10 + '0');
	}
	return (count);
}

static int	ft_check_parameter(const char c, va_list *args)
{
	if (c == 'i' || c == 'd')
		return (ft_print_i_d(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_s(va_arg(*args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += ft_check_parameter(*++str, &args);
		else
			count += ft_print_c(*str);
		str++;
	}
	va_end(args);
	return (count);
}
