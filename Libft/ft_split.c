/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:14:45 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/06/01 14:08:31 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char action, const char *s, char c)
{
	size_t	count;
	int		word;

	count = 0;
	if (action == 'A')
	{
		word = 0;
		while (*s)
		{
			if (*s == c)
				word = 0;
			else if (word == 0)
			{
				word = 1;
				count++;
			}
			s++;
		}
		return (count);
	}
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

const char	*skip_delimiters(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_words;
	size_t	i;
	size_t	word_len;

	i = 0;
	if (!s)
		return (NULL);
	n_words = counter('A', s, c);
	split = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!split)
		return (NULL);
	while (i < n_words)
	{
		s = skip_delimiters(s, c);
		word_len = counter('B', s, c);
		split[i] = ft_strndup(s, word_len);
		if (!split[i])
			return (free_split(split, i));
		s = s + word_len;
		i++;
	}
	split[n_words] = NULL;
	return (split);
}

/*
int	main()
{
	char **result = ft_split("Ecole 42 est une ecole d'informatique", ' ');
	size_t i = 0;

	printf("Ecole 42 est une ecole d'informatique, devient:\n");
    while (result[i])
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return 0;
}
*/
