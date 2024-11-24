/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:14:17 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 18:09:34 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}
