/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:41:19 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/14 18:42:52 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h" 

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define MAX_MAP_SIZE 100

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_game
{
	t_win		win;
	char		**map;
	//char **run_map;
	int			map_width;
	int			map_height;
	void		*floor_img;
	void		*wall_img;
	void		*player_img;
	void		*collectible_img;
	void		*exit_img;
	int			collects;
	int			player_x;
	int			player_y;
	int			pos_x;
	int			pos_y;
	int			move_count;
	int			is_closed;
}	t_game;
void	move_player(t_game *game, int x, int y);
void	find_player(t_game *game);
char	**load_map(char *file_path, t_game *game);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
void	close_game(t_game *game);
int		ft_len(char **array);
void	free_resources(t_game *game);
void	put_image(t_game *game, char tile, int x, int y);
void	load_image(void **img, void *mlx, char *path, t_game *game);
void	load_images(t_game *game);
int		main(int argc, char **argv);
void	initialize_game(t_game *game);
int		is_valid_file(char *filename);
int		count_exits(char **map, int height);
int		count_collectibles(char **map, int height);
int		count_player(char **map, int height);
int		validate_walls(char **map, int width, int height);
int		is_surrounded_by_walls(char **map, int width, int height);
void	flood_fill(t_game *game, int x, int y);
int		game_conditions(t_game *game);
int		check_items(t_game *game);
int		run_check_items(t_game *game);
void	free_arrays(char **map1, char **map2);
char	*read_map_file(char *file_path);
void	render_map(t_game *game);
int		validate_map_content(char **map, t_game *game);
char	**initialize_map(char *str_map, t_game *game);
void	handle_tile_interaction(t_game *game, int x, int y);
void	update(t_game *game, int x, int y);

#endif
