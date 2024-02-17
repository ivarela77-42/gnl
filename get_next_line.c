/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:53:27 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/02/17 10:58:09 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char	*line;
	int		chars_readed;

	chars_readed = 1;
	line = ft_strdup(buffer);
	while (!(ft_strchr(line, '\n')) && chars_readed != 0)
	{
		chars_readed = read(fd, buffer, BUFFER_SIZE);
		if (chars_readed == -1)
		{
			free(line);
			buffer[0] = '\0';
			return (NULL);
		}
		buffer[chars_readed] = '\0';
		line = ft_strjoin(line, buffer, ft_strlen(buffer));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_file(fd, buffer);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline)
	{
		ft_strlcpy(buffer, newline + 1, BUFFER_SIZE + 1);
		line[newline - line + 1] = '\0';
	}
	else
		buffer[0] = '\0';
	return (line);
}
