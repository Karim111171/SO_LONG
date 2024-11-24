/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:55:51 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 18:12:17 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_format(char specifier, va_list args)
{
	int				count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}
