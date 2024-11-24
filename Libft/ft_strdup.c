/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:43:28 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 16:42:46 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		j;

	i = ft_strlen(src);
	dup = malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	j = 0;
	while (src[j])
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
/*
#include <stdio.h>
int	main()
{
	char	*src;
	char	*str;

	src = "ecole 42";
	str = ft_strdup(src);
	printf("%s", str);
	free(str);
	return 0;
}
*/
