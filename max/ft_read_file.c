/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: granada <granada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:17:34 by granada           #+#    #+#             */
/*   Updated: 2024/10/06 17:41:01 by granada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
//#include <string.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 800

void	ft_putstr(char *str);

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

void	ft_copystr(char *str_src, char* str_dest)
{
	int	i;

	i = 0;
	while (str_src[i])
	{
		str_dest[i] = str_src[i];
		i++;
	}
	str_dest[i] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int count_lines_in_file(const char* filename) {
    int fd = open(filename, 0); // 0 for read only
    if (fd < 0) 
    {
        return -1;
    }

    char buffer[MAX_LINE_LENGTH];
    int bytes_read;
    int line_count = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; 
        // Zeilen zählen
        char* ptr = buffer;
        while (*ptr) {
            if (*ptr == '\n') {
                line_count++;
            }
            ptr++;
        }
    }
    // line_count++;

    close(fd);
    return line_count;
}

// Funktion, um die Zeilen aus der Datei zu lesen
char** read_lines_from_file(const char* filename, int* line_count) {
    *line_count = count_lines_in_file(filename);
    if (*line_count < 0) {
        return NULL; // Fehler beim Zählen
    }

    // Speicher für die Zeilen allokieren
    char** lines = malloc(*line_count * sizeof(char*));
    if (!lines) {
        *line_count = 0;
        return NULL;
    }

    // Datei erneut öffnen, um die Zeilen zu lesen
    int fd = open(filename, 0);
    if (fd < 0) {
        free(lines);
        return NULL;
    }

    char buffer[MAX_LINE_LENGTH];
    int bytes_read;
    int current_line = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; 

        char* ptr = buffer;
        while (*ptr) {
            // Zeilenlängen zählen
            int line_length = 0;
            while (*ptr && *ptr != '\n' && line_length < MAX_LINE_LENGTH - 1) {
                line_length++;
                ptr++;
            }

            // Zeile speichern, falls vorhanden
            if (line_length > 0) {
                lines[current_line] = malloc(line_length + 1);
                if (lines[current_line] == NULL) 
                {
                    close(fd);
                    // Speicherfreigabe für bereits allokierte Zeilen
                    for (int i = 0; i < current_line; i++) {
                        free(lines[i]);
                    }
                    free(lines);
                    return NULL; 
                }
                ft_strncpy(lines[current_line], ptr - line_length, line_length);
                lines[current_line][line_length] = '\0'; 
                current_line++;
            }

            // Zeilenumbruch überspringen
            if (*ptr == '\n') 
                ptr++;
        }
    }

    close(fd);
    return lines;
}

void free_lines(char** lines, int line_count) {
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
}

// int main() {
//     int line_count = 0;
//     char** lines = read_lines_from_file("numbers.dict", &line_count);

//     if (lines) {
//         for (int i = 0; i < line_count; i++) {
//             write(1, lines[i], ft_strlen(lines[i]));
//             write(1, "\n", 1);
//         }
//         free_lines(lines, line_count);
//     }

//     return 0;
// }
