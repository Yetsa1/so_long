/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:44:28 by yeparra-          #+#    #+#             */
/*   Updated: 2025/04/14 14:31:39 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Updates the player's current coordinates within the t_game structure

void	update(t_game *game, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
}

// Draws the entire map cell by cell and places the corresponding images using the put_image function

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_image(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

// Handles movement input:
// - Checks if the player can move (not into a wall)
// - Updates the internal map and player position if valid
// - Increments the move counter for 'P'
// - Displays the move count in the terminal

void	move_player(t_game *game, int x, int y)
{
	char	*move_str;

	if (game->map[x][y] == '1')
		return ;
	handle_tile_interaction(game, x, y);
	game->move_count++;
	move_str = ft_itoa(game->move_count);
	write(1, "Número de movimientos: ", 23);
	write(1, move_str, ft_strlen(move_str));
	write(1, "\n", 1);
	free(move_str);
	render_map(game);
}

// Detects the keys pressed by the player

int	handle_key(int keycode, t_game *game)
{
	find_player(game);
	if (keycode == KEY_W)
		move_player(game, game->pos_x - 1, game->pos_y);
	else if (keycode == KEY_A)
		move_player(game, game->pos_x, game->pos_y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->pos_x + 1, game->pos_y);
	else if (keycode == KEY_D)
		move_player(game, game->pos_x, game->pos_y + 1);
	else if (keycode == 65307)
		close_game(game);
	return (1);
}
