/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:02 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 18:12:38 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line_from_buffer(char **buffer);
static int	read_to_buffer(int fd, char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	ret = read_to_buffer(fd, &buffer);
	if (ret == -1 || (ret == 0 && (!buffer || !*buffer)))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line_from_buffer(&buffer);
	return (line);
}

static char	*get_line_from_buffer(char **buffer)
{
	size_t	i;
	size_t	j;
	char	*line;
	char	*new_buffer;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = (*buffer)[j];
	line[i] = '\0';
	if ((*buffer)[i - 1] == '\n')
		new_buffer = ft_strdup(*buffer + i);
	else
		new_buffer = NULL;
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

static int	read_to_buffer(int fd, char **buffer)
{
	char	*temp_buffer;
	int		bytes_read;
	char	*new_buffer;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr(*buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buffer);
			return (-1);
		}
		temp_buffer[bytes_read] = '\0';
		new_buffer = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		*buffer = new_buffer;
	}
	free(temp_buffer);
	return (bytes_read);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("../mapk.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
