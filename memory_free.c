/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:55 by yeparra-          #+#    #+#             */
/*   Updated: 2025/04/14 15:45:28 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	internal_close_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_copy)
	{
		while (i < game->map_height)
		{
			if (game->map_copy[i])
				free(game->map_copy[i]);
			game->map_copy[i] = NULL;
			i++;
		}
		free(game->map_copy);
		game->map_copy = NULL;
	}
	if (game->win.win)
	{
		free_resources(game);
		mlx_destroy_window(game->win.mlx, game->win.win);
		game->win.win = NULL;
	}
}

void	close_game(t_game *game)
{
	int	i;

	i = 0;
	internal_close_game(game);
	if (game->map)
	{
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->win.mlx)
	{
		mlx_destroy_display(game->win.mlx);
		free(game->win.mlx);
		game->win.mlx = NULL;
	}
	write(1, "game cerrado.\n", 15);
	exit(0);
}

void	free_resources(t_game *game)
{
	mlx_loop_end(game->win.mlx);
	if (game->player_img)
		mlx_destroy_image(game->win.mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->win.mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->win.mlx, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->win.mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->win.mlx, game->exit_img);
	if (game->move_str)
		free(game->move_str);
}

void	initialize_t_game(t_game *game)
{
	game->win.mlx = NULL;
	game->win.win = NULL;
	game->map = NULL;
	game->map_copy = NULL;
	game->move_str = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
}
