/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeparra- <yeparra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:47 by yeparra-          #+#    #+#             */
/*   Updated: 2024/11/14 19:08:44 by yeparra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map_file(char *file_path)
{
	int		fd;
	char	*line;
	char	*str_map;
	char	*temp;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str_map = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = str_map;
		str_map = ft_strjoin(str_map, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (str_map);
}

int	validate_map_content(char **map, t_game *game)
{
	if (!is_surrounded_by_walls(map, game->map_width, game->map_height))
	{
		write(1, "Error: El mapa debe estar rodeado de muros.\n", 44);
		return (0);
	}
	if (!run_check_items(game))
	{
		write(1, "Error: 1 player, at least 1 Coin and 1 Exit.\n", 46);
		free_arrays(map, NULL);
		return (0);
	}
	if (!validate_walls(map, game->map_width, game->map_height))
	{
		write(1, "Error: El mapa debe estar rodeado de muros.\n", 44);
		return (0);
	}
	return (1);
}

char	**initialize_map(char *str_map, t_game *game)
{
	char	**map;

	map = ft_split(str_map, '\n');
	game->map = ft_split(str_map, '\n');
	if (!map || !game->map)
	{
		free(map);
		write(1, "map NULL\n", 10);
		return (NULL);
	}
	game->map_height = ft_len(map);
	game->map_width = ft_strlen(map[0]);
	if (!validate_map_content(map, game))
	{
		close_game(game);
		free(str_map);
		return (NULL);
	}
	return (map);
}

char	**load_map(char *file_path, t_game *game)
{
	char	*str_map;
	char	**map;

	str_map = read_map_file(file_path);
	if (!str_map)
		return (NULL);
	map = initialize_map(str_map, game);
	free(str_map);
	if (!map || !game_conditions(game))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
