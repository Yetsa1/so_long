/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:43:47 by yeparra-          #+#    #+#             */
/*   Updated: 2025/04/14 15:47:41 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	if (!game || !game->map)
		return ;
	i = 1;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_x = i;
				game->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_arrays(char **map1, char **map2)
{
	int	i;

	i = 0;
	if (map1)
	{
		while (map1[i])
		{
			free(map1[i]);
			i++;
		}
		free(map1);
	}
	i = 0;
	if (map2)
	{
		while (map2[i])
		{
			free(map2[i]);
			i++;
		}
		free(map2);
	}
}

void	put_image(t_game *game, char tile, int x, int y)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = game->wall_img;
	else if (tile == '0')
		img = game->floor_img;
	else if (tile == 'C')
		img = game->collectible_img;
	else if (tile == 'P')
		img = game->player_img;
	else if (tile == 'E')
		img = game->exit_img;
	if (img)
	{
		x = x * TILE_SIZE;
		y = y * TILE_SIZE;
		mlx_put_image_to_window(game->win.mlx, game->win.win, img, x, y);
	}
	else
	{
		write(1, "ERROR! La imagen no ha podido ser colocada!\n", 45);
		close_game(game);
	}
}

void	handle_tile_interaction(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'C')
	{
		game->map[x][y] = 'P';
		game->map[game->pos_x][game->pos_y] = '0';
	}
	else if (game->map[x][y] == 'E')
	{
		if (count_collectibles(game->map, game->map_height) == 0)
		{
			game->move_count++;
			game->map[x][y] = 'P';
			game->move_str = ft_itoa(game->move_count);
			free(game->move_str);
			close_game(game);
		}
		else
			return ;
	}
	else if (game->map[x][y] == '0')
	{
		game->map[game->pos_x][game->pos_y] = '0';
		update(game, x, y);
		game->map[game->pos_x][game->pos_y] = 'P';
	}
}
