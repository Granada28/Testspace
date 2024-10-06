/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: granada <granada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:47:38 by granada           #+#    #+#             */
/*   Updated: 2024/10/06 21:21:34 by granada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define MAX_LINE_LENGTH 800

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
int		count_lines_in_file(const char *filename);
void	free_lines(char **lines, int line_count);
void	free_malloc_failure(char **lines, int current_line);
int		extract_line(char **lines, char *ptr, int line_length,
			int current_line);
char	**reserve_spaces_lines(const char *filename, int *line_count);
char	**read_lines_from_file(const char *filename, int *line_count);
int		read_lines_from_buffer(int fd, char **lines, int *current_line);
int 	process_buffer(char *buffer, char **lines, int *current_line, char **ptr);

#endif