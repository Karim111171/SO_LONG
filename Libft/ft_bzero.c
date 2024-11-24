/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:21:11 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/06/17 16:44:50 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset((unsigned char *)s, 0, n);
}

/*
#include <stdio.h>

int	main()
{
	char	s[] = "ECOLE 42";
	char	t[] = "ECOLE 42";

	printf("la phrase: %s\n" , s);
	ft_bzero(s, 3);
	printf("la phrase apres ft_bzero: %s\n" , s + 3);
	bzero(t, 3);
	printf("la phrase apres bzero: %s\n" , t + 2);
}
*/
