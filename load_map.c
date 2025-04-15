/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:47 by yeparra-          #+#    #+#             */
/*   Updated: 2025/04/14 14:15:04 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map_file(char *file_path)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;
	char	*str_map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, 1023);
	close(fd);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	str_map = ft_strdup(buffer);
	return (str_map);
}

int	validate_map_content(char **map, t_game *game)
{
	if (!is_rectangular_map(map))
	{
		write(1, "Error: El mapa debe ser rectangular.\n", 37);
		return (0);
	}
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
	}
}

char	**initialize_map(char *str_map, t_game *game)
{
	game->map_copy = ft_split(str_map, '\n');
	game->map = ft_split(str_map, '\n');
	if (!game->map_copy || !game->map)
	{
		write(1, "map NULL\n", 10);
		free_map(game->map_copy);
		free_map(game->map);
		return (NULL);
	}
	game->map_height = ft_len(game->map_copy);
	game->map_width = ft_strlen(game->map_copy[0]);
	if (!validate_map_content(game->map_copy, game))
	{
		free_map(game->map_copy);
		free_map(game->map);
		game->map_copy = NULL;
		game->map = NULL;
		free(str_map);
		close_game(game);
		return (NULL);
	}
	return (game->map_copy);
}

char	**load_map(char *file_path, t_game *game)
{
	char	*str_map;
	char	**map;

	map = NULL;
	str_map = read_map_file(file_path);
	if (!str_map)
	{
		return (close_game(game), NULL);
		str_map = NULL;
	}
	map = initialize_map(str_map, game);
	free(str_map);
	str_map = NULL;
	if (!map || !game_conditions(game))
	{
		close_game(game);
		return (NULL);
	}
	free_map(game->map);
	return (map);
}
