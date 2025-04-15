/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:13:55 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/15 12:38:27 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	run_check_items(t_game *game)
{
	int	collects;
	int	exit;
	int	player;

	player = count_player(game->map, game->map_height);
	collects = count_collectibles(game->map, game->map_height);
	exit = count_exits(game->map, game->map_height);
	if (collects >= 1 && exit == 1 && player == 1)
		return (1);
	return (0);
}

int	check_items(t_game *game)
{
	int	collects;
	int	exit;

	collects = count_collectibles(game->map, game->map_height);
	exit = count_exits(game->map, game->map_height);
	if (collects == 0 && exit == 0)
		return (1);
	return (0);
}

int	game_conditions(t_game *game)
{
	find_player(game);
	flood_fill(game, game->pos_x, game->pos_y);
	if (!check_items(game))
	{
		write(1, "check error items\n", 19);
		return (0);
	}
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1' || game->map[x][y] == 'V')
		return ;
	game->map[x][y] = 'V';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

int	is_rectangular_map(char **map)
{
	int		i;
	size_t	row_length;

	if (!map || !map[0])
		return (0);
	row_length = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != row_length)
			return (0);
		i++;
	}
	return (1);
}
