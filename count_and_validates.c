/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_validates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:11:14 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/14 15:40:09 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*Function responsible for finding the exits*/
int	count_exits(char **map, int height)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
/*Function responsible for counting the collectibles*/
int	count_collectibles(char **map, int height)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
/*Function responsible for counting the player*/
int	count_player(char **map, int height)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
/*Check that the rows and columns at the edges of the maps are wallas*/
int	validate_walls(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
