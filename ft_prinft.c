/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavalc <lucavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:54:57 by lucavalc          #+#    #+#             */
/*   Updated: 2025/10/16 17:43:21 by lucavalc         ###   ########.fr       */
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
		len += ft_print_u(va_arg(*type, unsigned int));
	else if (c == 'x')
		len += ft_print_x(va_arg(*type, unsigned int), 1);
	else if (c == 'X')
		len += ft_print_x(va_arg(*type, unsigned int), 2);
	else if (c == 'p')
		len += ft_print_ptr(type);
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
		i += ft_print_d(n / 10);
	}
	i += ft_print_c((n % 10) + '0');
	return (i);
}
int	ft_print_x(unsigned int nb, int s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_print_x(nb / 16, s);
	if ((nb % 16) < 10)
		i += ft_print_char((nb % 16) + 48);
	else
	{
		if (s == 1)
			i += ft_print_char((nb % 16) + 87);
		else
			i += ft_print_char((nb % 16) + 55);
	}
	return (i);
}
int	ft_print_ptr(va_list *ptr)
{
	unsigned long int	address;
	int					len;

	address = va_arg(*ptr, unsigned long int);
	if (address == 0)
		len = write(1, "(nil)", 5);
	else
	{
		len = write(1, "0x", 2);
		len += ft_print_adr(address);
	}
	return (len);
}
int	ft_print_u(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_print_u(nb / 10);
	i += ft_print_c((nb % 10) + '0');
	return (i);
}
int	ft_print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_print_adr(nb / 16);
	}
	if ((nb % 16) < 10)
		len += ft_print_char((nb % 16) + 48);
	else
		len += ft_print_char((nb % 16) + 87);
	return (len);
}
