/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:40:42 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 18:11:30 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned long n, int uppercase)
{
	int		count;
	int		index;
	char	hex_digit;

	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, uppercase);
	index = n % 16;
	if (index < 10)
		hex_digit = '0' + index;
	else
	{
		if (uppercase)
			hex_digit = 'A' + index - 10;
		else
			hex_digit = 'a' + index - 10;
	}
	count += ft_putchar(hex_digit);
	return (count);
}
