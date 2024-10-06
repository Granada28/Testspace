/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demelche <demelche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:47:38 by granada           #+#    #+#             */
/*   Updated: 2024/10/06 20:53:45 by demelche         ###   ########.fr       */
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

#endif