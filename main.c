/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:30:44 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/14 19:09:11 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
valgrind --leak-check=full --show-leak-kinds=all --log-file=valgrind-report.txt ./so_long maps/pruebas.ber*/
#include "so_long.h"

void	load_image(void **img, void *mlx, char *path, t_game *game)
{
	int	img_width;
	int	img_height;

	*img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (!*img)
	{
		write(1, "Error al cargar una imagen.\n", 28);
		close_game(game);
	}
}

void	load_images(t_game *game)
{
	load_image(&game->floor_img, game->win.mlx, "img/floor.xpm", game);
	load_image(&game->player_img, game->win.mlx, "img/wizark.xpm", game);
	load_image(&game->wall_img, game->win.mlx, "img/wall.xpm", game);
	load_image(&game->collectible_img, game->win.mlx, "img/star.xpm", game);
	load_image(&game->exit_img, game->win.mlx, "img/portal.xpm", game);
}

void	initialize_game(t_game *game)
{
	game->floor_img = 0;
	game->wall_img = 0;
	game->player_img = 0;
	game->collectible_img = 0;
	game->exit_img = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
	game->pos_x = 0;
	game->is_closed = 0;
	load_images(game);
	render_map(game);
	find_player(game);
	mlx_hook(game->win.win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win.win, 17, 0, (void *)close_game, game);
	mlx_loop(game->win.mlx);
}

int	is_valid_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	return (len >= 5 && ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		width;
	int		height;

	if (argc != 2 || !is_valid_file(argv[1]))
	{
		write(1, "No es un fichero .ber válido\n", 31);
		return (1);
	}
	game.win.mlx = mlx_init();
	if (!game.win.mlx)
		return (1);
	game.map = load_map(argv[1], &game);
	if (!game.map)
		return (1);
	width = game.map_width * TILE_SIZE;
	height = game.map_height * TILE_SIZE;
	game.win.win = mlx_new_window(game.win.mlx, width, height, "so_long");
	if (!game.win.win)
	{
		write(1, "Error: No se pudo crear la ventana.\n", 36);
		close_game(&game);
	}
	initialize_game(&game);
	return (0);
}
