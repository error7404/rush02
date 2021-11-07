#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int	algo(int **table, int x, int y, int max);

unsigned int	readstdin(void)
{
	char	test[16];

	fgets(test, 16, stdin);
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
	while (i < x + 1)
	{
		tabl[i] = calloc(y + 1, sizeof(int));
		if (!tabl[i])
			return (0);
		tabl[i][y] = -1;
		i++;
	}
	i = 0;
	while (i < y + 1)
	{
		tabl[x][i] = -1;
		i++;
	}
	return (tabl);
}

// void	showtable(int **table)
// {
// 	int	x;
// 	int	y;

// 	fclose(g_out);
// 	usleep(5000);
// 	g_out = fopen("log.txt", "wr");
// 	y = 0;
// 	fprintf(g_out, "_______________\n");
// 	while (table[0][y] != -1)
// 	{
// 		x = 0;
// 		fprintf(g_out, "|");
// 		while (table[x][0] != -1)
// 		{
// 			if (table[x][y] == 0)
// 				fprintf(g_out, " |");
// 			else if (table[x][y] == 1)
// 				fprintf(g_out, "o|");
// 			else if (table[x][y] == 2)
// 				fprintf(g_out, "x|");
// 			else
// 				fprintf(g_out, "?|");
// 			x++;
// 		}
// 		fprintf(g_out, "\n");
// 		y++;
// 	}
// 	fprintf(g_out, "###############\n");
// 	fclose(g_out);
// 	usleep(100);
// 	g_out = fopen("log.txt", "wr");
// }

void	addtotable(int **table, int x, int player)
{
	unsigned int	i;

	i = 0;
	while (table[x][i] != -1)
	{
		if (table[x][i])
		{
			table[x][i - 1] = player;
			return ;
		}
		i++;
	}
	table[x][i - 1] = player;
}

void	removetotable(int **table, int x)
{
	unsigned int	i;

	i = 0;
	while (table[x][i] != -1)
	{
		if (table[x][i])
		{
			table[x][i] = 0;
			return ;
		}
		i++;
	}
	table[x][i] = 0;
}

int	main(void)
{
	int	move;
	int	x = readstdin();
	int y = readstdin();
	int	**tabl = createtable(x, y);
	int	max = readstdin();
	int	start = readstdin();
	readstdin();
	readstdin();
	setbuf(stdout, NULL);
	if (start == 2)
		addtotable(tabl, readstdin(), 2);
	fprintf(stdout, "%d\n", x / 2);
	addtotable(tabl, x / 2, 1);
	addtotable(tabl, readstdin(), 2);
	while (1)
	{
		move = algo(tabl, x, y, max);
		fprintf(stdout, "%d\n", move);
		addtotable(tabl, move, 1);
		addtotable(tabl, readstdin(), 2);
	}
}
