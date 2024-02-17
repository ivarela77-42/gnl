/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:57:26 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/02/17 11:53:15 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // For printf

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("blake-en-bucle.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error abriendo el archivo\n");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("\n");
	close(fd);
	return (0);
}
