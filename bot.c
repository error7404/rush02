#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

FILE	*g_out;

int	algo(int **table, int x);

unsigned int	readstdin(void)
{
	char	test[16];

	fgets(test, 16, stdin);
	fprintf(g_out, "%d\n", atoi(test));
	return ((unsigned int) atoi(test));
}

int	**createtable(int x, int y)
{
	int	**tabl;
	int	i;

	tabl = calloc(x + 1, sizeof(int *));
	if (!tabl)
		return (0);
	i = 0;
	while (i < x)
	{
		tabl[i] = calloc(y + 5, sizeof(int));
		if (!tabl[i])
			return (0);
		tabl[i][y] = -1;
		tabl[i][y + 1] = -1;
		tabl[i][y + 2] = -1;
		tabl[i][y + 3] = -1;
		tabl[i][y + 4] = -1;
		i++;
	}
	tabl[i + 1] = 0;
	return (tabl);
}

void	showtable(int **table)
{
	int	x;
	int	y;

	y = 0;
	fprintf(g_out, "_______________\n");
	while (table[0][y] != -1)
	{
		x = 0;
		fprintf(g_out, "|");
		while (table[x])
		{
			if (table[x][y] == 0)
				fprintf(g_out, " |");
			else if (table[x][y] == 1)
				fprintf(g_out, "o|");
			else if (table[x][y] == 2)
				fprintf(g_out, "x|");
			else
				fprintf(g_out, "?|");
			x++;
		}
		fprintf(g_out, "\n");
		y++;
	}
	fprintf(g_out, "###############\n");
	fclose(g_out);
	g_out = fopen("log.txt", "wr");
}

// 	int	table[][] = {
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0},
//     {0, 0, 2, 1, 0}
// }
int	main(void)
{
	g_out = fopen("log.txt", "w");
	fprintf(g_out, "=========================================================\n");
	int	x = readstdin();
	int y = readstdin();
	int	**tabl = createtable(x, y);
	int	max = readstdin();
	int	start = readstdin();
	readstdin();
	readstdin();
	while (1)
		printf("%d\n", algo(tabl, x));
}
