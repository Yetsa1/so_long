/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:33:55 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/14 19:26:56 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->win.win)
	{
		free_resources(game);
		//mlx_destroy_window(game->win.mlx, game->win.win);
		//mlx_destroy_display(game->win.mlx);
	}
	if (game->map)
	{
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		printf("Mapa liberado.\n");
	}
	free(game);
	write(1, "game cerrado.\n", 15);
	exit (0);
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
	if (game->win.win)
		mlx_destroy_window(game->win.mlx, game->win.win);
	if (game->win.mlx)
	{
		mlx_destroy_display(game->win.mlx);
		free(game->win.mlx);
	}
}
