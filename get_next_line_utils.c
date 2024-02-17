/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanrodr <ivanrodr@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:53:08 by ivanrodr          #+#    #+#             */
/*   Updated: 2024/02/15 10:11:18 by ivanrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	index;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] == (char) c)
			return ((char *) &str[index]);
		index++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	index;

	length = ft_strlen(src);
	if (size > 0)
	{
		index = 0;
		while (src[index] && index < size - 1)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (length);
}

char	*ft_strdup(const char *str)
{
	char	*clone;

	clone = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!clone)
		return (NULL);
	ft_strlcpy(clone, str, ft_strlen(str) + 1);
	return (clone);
}

char	*ft_strjoin(char *s1, char const *s2, size_t length)
{
	size_t	length_s1;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	length_s1 = ft_strlen(s1);
	result = (char *)malloc((length_s1 + length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, length_s1 + 1);
	ft_strlcpy((result + length_s1), s2, length + 1);
	free(s1);
	return (result);
}
