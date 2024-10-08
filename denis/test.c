#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int	i;
	int	j;
	int	len;
	int boxes = 3;
	
	char *str = "1000333"; // <- str to change
	int nbr_put = 0;

	i = 0;
	j = 0;
	len = 7; // if u want to test different str <- change also

	
	char	**box_map;
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

	i = 0;
	j = 0;
	int skip = 0;
	// print boxes
	while (i < boxes)
	{
		if (box_map[i][0] == '0' && box_map[i][1] == '0' && box_map[i][2] == '0')
		{
			skip = 1;
			len = len - 3;
		}
		if (skip == 0 && len >= 20 && len <= 22) // sextillion
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" sextillion ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 17 && len <= 19) // quintillion
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" quintillion ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 14 && len <= 16) // quadrillion
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" quadrillion ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 11 && len <= 13) // trillion
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" trillion ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 8 && len <= 10) // billion
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" billion ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 5 && len <= 7) // million
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" million ");
			len = len - 3;
		}
		else if (skip == 0 && len >= 2 && len <= 4) // thousand
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
			printf(" thousand ");
			len = len - 3;
		}
		else if (skip == 0 && len > 0 && len < 2) // hundred
		{
			while (j < 3)
			{
				if (box_map[i][j] == '-')
					;
				else
					printf("%c", box_map[i][j]);
				j++;
			}
		}
		skip = 0;
		j = 0;
		i++;
	}
	
	// Free allocated memory
    for (i = 0; i < boxes; i++) {
        free(box_map[i]);
    }
    free(box_map);
}