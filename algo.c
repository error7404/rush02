/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:59:26 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/06 19:17:43 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int	ispossible()
{
	return (0);
}

/* dir est la direction ou calculer le score
 * dir = 0: x+
 * dir = 1: x+ y+
 * dir = 2: y+
 * dir = 3: x+ y-
*/
int	scoredir(int **table, int player, int x, int y, int dir)
{
	int	count;
	int	direction[4][2] = {
		{1, 0},
		{1, 1},
		{0, 1},
		{1, -1}
	};

	count = 0;
	while (table[x + direction[dir][0]][y + direction[dir][1]] == player)
	{
		if (table[x][y] != player)
			return (count);
		count += 1;
		x += direction[dir][0];
		y += direction[dir][1];
	}
	return (count);
}

int	scoreplayer(int **table, int player)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (table[x])
	{
		y = 0;
		while (table[x][y] != -1)
		{
			if (table[x][y] == player)
			{
				for (size_t i = 0; i < 4; i++)
				{
					count += scoredir(table, player, x, y, i);
				}
			}
			y++;
		}
		x++;
	}
	return (count);
}

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

int	algo(int **table, int x)
{
	int	max_i;
	int	temp;

	max_i = -1;
	for (size_t i = 0; i < x; i++)
	{
		temp = scoreplayer(table, 1);
		if (temp > max_i)
			max_i = temp;
	}
	return (max_i);
}
