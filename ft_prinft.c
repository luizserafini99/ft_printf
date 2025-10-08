/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavalc <lucavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:54:57 by lucavalc          #+#    #+#             */
/*   Updated: 2025/10/08 15:56:02 by lucavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *ptr, ...)
{
	int i;
    int len;
    va_list type;

    i = 0;
    len = 0;
    va_start(type, ptr);

    while(*ptr)
    {
        if(*ptr == '%' && (*ptr + 1))
        {
            ptr++;
            len += ft_checker_type(*ptr, &type);
        }
        else
        {
            len += write(1, ptr, 1);
            ptr++;
        }
    }
    va_end(type);
    return(len);
}
int	ft_checker_type(char c, va_list *type)
{
	int len;

	len = 0;
	if (c == 'c')
		len += ft_print_c(va_arg(*type, int));
	else if (c == 's')
		len += ft_print_s(va_arg(*type, char *));
	else if (c == 'd' || c == 'i')
		len += ft_print_d(va_arg(*type, int));
	else if (c == 'u')
		len += ft_print_x(va_arg(*type, unsigned int));
	else if (c == 'x')
		len += ft_(va_arg(*type, unsigned int), 1);
	else if (c == 'X')
		len += ft_(va_arg(*type, unsigned int), 2);
	else if (c == 'p')
		len += ft_(type);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}
int ft_print_c(char c)
{
    int i;

    i = write(1, &c, 1);
    return (i);
}
int ft_print_s(char *str)
{
    int i;

    while(*str)
    {
        if(!str)
        {
            *str = "Null";
        }
        else
        {
            i += write(1, str++, 1);
        }
    }
    return (i);
}

int	ft_print_d(int nb)
{
	long long	n;
	int			i;

	n = nb;
	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_print_number(n / 10);
	}
	i += ft_print_char((n % 10) + '0');
	return (i);
}
