/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:35:10 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/06/03 18:43:50 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if (!dst && !src && len > 0)
		return (NULL);
	if (dst <= src || dst >= (src + len))
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst = ptr_dst + len - 1;
		ptr_src = ptr_src + len - 1;
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}
