#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	i;
	int	j;
	int	len;
	int boxes = 3;
	char	**box_map;
	char *str = "1222333"; // <- str to change
	int nbr_put = 0;

	i = 0;
	j = 0;
	len = 7; // if u want to test different str <- change also

	// Allocate memory for 'boxes' rows
    box_map = (char **)malloc(boxes * sizeof(char *));
    if (box_map == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for 3 columns in each row
    for (i = 0; i < boxes; i++) {
        box_map[i] = (char *)malloc(3 * sizeof(char));
        if (box_map[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

	i = 0;

	while (i < boxes)
	{
		if (i == 0 && (len % 3) != 0)
		{
			if (len % 3 == 2)
			{
				box_map[i][0] = '-';
				box_map[i][1] = str[nbr_put];
				nbr_put++;
				box_map[i][2] = str[nbr_put];
				nbr_put++;
			}
			else
			{
				box_map[i][0] = '-';
				box_map[i][1] = '-';
				box_map[i][2] = str[nbr_put];
				nbr_put++;
			}
		}
		else
		{
			box_map[i][0] = str[nbr_put];
			nbr_put++;
			box_map[i][1] = str[nbr_put];
			nbr_put++;
			box_map[i][2] = str[nbr_put];
			nbr_put++;
		}
		i++;
	}

	i = 0;
	while (i < boxes)
	{	
		while (j < 3)
		{
			printf("%c", box_map[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}

	// Free allocated memory
    for (i = 0; i < boxes; i++) {
        free(box_map[i]);
    }
    free(box_map);
}