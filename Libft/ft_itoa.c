/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:53:18 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/25 19:47:15 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	num;

	num = (long)n;
	len = ft_count_digits(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num)
	{
		str[len--] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
/*
int	main()
{
	int	i;
	int	j;
	int	lens1;
	int	lens2;	
	
	i = -983;
	j = 983;

	lens1 = ft_count_digits(i);
	lens2 = ft_count_digits(j);

	printf("pour %d, voici: %s\n", i, ft_itoa(i));
	printf("pour %d, voici: %s\n", j, ft_itoa(j));
}
*/	
