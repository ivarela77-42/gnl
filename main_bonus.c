/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:57:26 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/02/17 12:46:19 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h> // For printf

void	ft_check_files(char **files, int total_files, int *fd)
{
	int		index_files;

	index_files = 0;
	printf("files to read: %i\n", total_files);
	while (index_files < total_files)
	{
		fd[index_files] = open(files[index_files], O_RDONLY);
		if (fd[index_files] > -1)
			printf("Abriendo archivo: %s\n", files[index_files]);
		else
			printf("Error abriendo el archivo: %s\n", files[index_files]);
		index_files++;
	}
}

int	main(void)
{
	int		fd[2];
	char	*files[2];
	char	*line;
	int		index;

	files[0] = "blake-en-bucle.txt";
	files[1] = "ed-sheran-shape-of-you.txt";
	ft_check_files(files, sizeof(files) / sizeof(files[0]), fd);
	index = 0;
	while (index < sizeof(files) / sizeof(files[0]))
	{
		printf("\n\nLeyendo archivo: %s\n--------------------\n", files[index]);
		while (1)
		{
			line = get_next_line(fd[index]);
			if (!line)
				break ;
			printf("%s", line);
			free(line);
		}
		close(fd[index]);
		index++;
	}
	printf("\n");
	return (0);
}
