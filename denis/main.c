/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demelche <demelche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:52:32 by demelche          #+#    #+#             */
/*   Updated: 2024/10/06 16:00:59 by demelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		length(char *str);
int		boxes_calc(int leng);

int		logic(char *str)
{
	int	len;
	int	i;
	int boxes;

	i = 0;
	len = 0;
	len = length(str);
	if (len < 0)
		return (-1);
	if (len == 0)
	{
		write(1, "one", 3);
		return (0);
	}
	boxes = boxes_calc(len);
	if (len - (boxes * 3) != 0)
		boxes++;
	
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

int		**boxes_array(int boxes, char *str)
{
	int	i;
	int	j;
	int	len;
	int	**box_map;

	i = 0;
	j = 0;
	len = 0;
	box_map[]
	len = length(str);
	while (i < boxes)
	{
		while (j < 3)
		{
			
		}
	}
}

int		boxes_calc(int leng)
{
	int	i;
	
	i = 0;
	i = leng / 3;
	return (i);
}

int		length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main(void)
{
	char *str = "2147483648";
	logic(str);
}

// i could use static global variable g_len;