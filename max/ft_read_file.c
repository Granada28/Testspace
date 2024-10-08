/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: granada <granada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:17:34 by granada           #+#    #+#             */
/*   Updated: 2024/10/06 21:29:24 by granada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int main()
// {
//     int line_count = 0;
//     char** lines = read_lines_from_file("numbers.dict", &line_count);

//     if (lines) {
//         for (int i = 0; i < line_count; i++) {
//             write(1, lines[i], ft_strlen(lines[i]));
//             write(1, "\n", 1);
//         }
//         free_lines(lines, line_count);
//     }
//     return (0);
// }

int process_buffer(char *buffer, char **lines, int *current_line, char **ptr) {
    int line_length = 0;

    while (**ptr) {
        line_length = 0;
        while (**ptr && **ptr != '\n' && line_length < MAX_LINE_LENGTH - 1) {
            line_length++;
            (*ptr)++;
        }
        if (extract_line(lines, *ptr, line_length, *current_line) < 0) {
            return -1; 
        }
        (*current_line)++;
        if (**ptr == '\n') {
            (*ptr)++;
        }
    }
    return 0; 
}

int read_lines_from_buffer(int fd, char **lines, int *current_line) {
    char buffer[MAX_LINE_LENGTH];
    int bytes_read;
    char *ptr;

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    while (bytes_read > 0) {
        buffer[bytes_read] = '\0';
        ptr = buffer;

        if (process_buffer(buffer, lines, current_line, &ptr) < 0) {
            return -1; 
        }

        bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    }
    return 0; 
}

char	**read_lines_from_file(const char *filename, int *line_count)
{
	char	**lines;
	int		fd;
	int		current_line;

	lines = reserve_spaces_lines(filename, line_count);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(lines);
		return (NULL);
	}
	current_line = 0;
	if (read_lines_from_buffer(fd, lines, &current_line) < 0)
	{
		close(fd);
		free_malloc_failure(lines, current_line); 
		return (NULL);                              
	}
	close(fd);
	return (lines);
}

void	free_malloc_failure(char **lines, int current_line)
{
	int	i;

	i = 0;
	while (i < current_line)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
