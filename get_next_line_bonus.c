/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:47:26 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/02/15 11:49:58 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = read_file(fd, buffer[fd]);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline)
	{
		ft_strlcpy(buffer[fd], newline + 1, BUFFER_SIZE + 1);
		line[newline - line + 1] = '\0';
	}
	else
		buffer[fd][0] = '\0';
	return (line);
}
