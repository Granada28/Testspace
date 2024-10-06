/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: granada <granada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:56:08 by granada           #+#    #+#             */
/*   Updated: 2024/10/06 21:22:43 by granada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	count_lines_in_file(const char *filename)
{
	int		fd;
	char	buffer[MAX_LINE_LENGTH];
	int		bytes_read;
	int		line_count;
	char	*ptr;

	fd = open(filename, 0);
	if (fd < 0)
		return (-1);
	line_count = 0;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ptr = buffer;
		while (*ptr)
		{
			if (*ptr == '\n')
				line_count++;
			ptr++;
		}
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	return (line_count);
}

char	**reserve_spaces_lines(const char *filename, int *line_count)
{
	char	**lines;

	*line_count = count_lines_in_file(filename);
	if (*line_count < 0)
	{
		return (NULL);
	}
	lines = malloc(*line_count * sizeof(char *));
	if (!lines)
	{
		*line_count = 0;
		return (NULL);
	}
	return (lines);
}

void	free_lines(char **lines, int line_count)
{
	for (int i = 0; i < line_count; i++)
	{
		free(lines[i]);
	}
	free(lines);
}

int	extract_line(char **lines, char *ptr, int line_length, int current_line)
{
	lines[current_line] = malloc(line_length + 1);
	if (lines[current_line] == NULL)
	{
		return (-1); 
	}
	ft_strncpy(lines[current_line], ptr - line_length, line_length);
	lines[current_line][line_length] = '\0'; 
	return (0);                                
}
