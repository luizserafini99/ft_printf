/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavalc <lucavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:07 by lucavalc          #+#    #+#             */
/*   Updated: 2025/10/08 13:50:33 by lucavalc         ###   ########.fr       */
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
    va_star(type, ptr);

    while(*ptr)
    {
        if(*ptr == '%' && (*ptr + 1))
        {
            ptr++;
            len += ft_checker_type()
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
/