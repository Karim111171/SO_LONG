/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:40:18 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/05/21 15:02:49 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*joined;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		joined[i] = s2[i - len1];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}
