/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:59:26 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/07 14:43:49 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void	addtotable(int **table, int x, int player);
void	removetotable(int **table, int x);
void	showtable(int **table);

/* dir est la direction ou calculer le score
 * dir = 0: x+
 * dir = 1: x+ y+
 * dir = 2: y+
 * dir = 3: x+ y-
*/
int	scoredir(int **table, int player, int x, int y, int dir, int max)
{
	int	count;
	int max_score;
	int	direction[4][2] = {
		{1, 0},
		{1, 1},
		{0, 1},
		{1, -1}
	};

	max_score = 0;
	for (size_t i = 0; i < max - 1; i++)
	{
		max_score += 1;
		max_score *= 2;
	}
	count = 0;
	if (!table[x + direction[dir][0]])
		return (0);
	while (table[x + direction[dir][0]][y + direction[dir][1]] == player)
	{
		if (table[x][y] != player)
		{
			if (count >= max_score - 1)
				return (10000);
			return (count);
		}
		count += 1;
		count *= 2;
		x += direction[dir][0];
		y += direction[dir][1];
	}
	if (count >= max_score - 1)
		return (10000);
	return (count);
}

int	scoreplayer(int **table, int player, int max)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (table[x][0] != -1)
	{
		y = 0;
		while (table[x][y] != -1)
		{
			if (table[x][y] == player)
			{
				for (size_t i = 0; i < 4; i++)
				{
					count += scoredir(table, player, x, y, i, max);
				}
			}
			y++;
		}
		x++;
	}
	return (count);
}

int	algo(int **table, int x, int y, int max)
{
	int	max_i;
	int	temp;
	int	max_temp;

	max_i = -1;
	max_temp = -1;
	for (size_t i = 0; i < x; i++)
	{
		if (!table[i][0])
		{
			addtotable(table, i, 1);
			temp = scoreplayer(table, 1, max);
			removetotable(table, i);
			if (temp > max_temp)
			{
				max_temp = temp;
				max_i = i;
			}
		}
	}
	// TODO dupliquer et tester les nouveau tableau ou cree fonction pour enlever dernier move
	// historique?
	return (max_i);
}
