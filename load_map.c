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

/*This function reads *.ber files and duplicates them, returning the copy*/

char	*read_map_file(char *file_path)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;
	char	*str_map;

	fd = open(file_path, O_RDONLY); //read *.ber path, just open and read
	if (fd < 0)//verify errors
		return (NULL);
	bytes_read = read(fd, buffer, 1023); //read bytes
	close(fd);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	str_map = ft_strdup(buffer);
	return (str_map);
}

/*Map validity conditions, if not met, this function called to end the program execution*/

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

/*Function to free the map in case an error occurred*/

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

/*Converts the full map string into a double pointer (matrix),
stores it in s_game, checks if the map is rectangular,
and returns a copy of the matrix.*/

char	**initialize_map(char *str_map, t_game *game)
{
	game->map_copy = ft_split(str_map, '\n');//Contains the entire map as a string with newline characters
	game->map = ft_split(str_map, '\n');//The same
	if (!game->map_copy || !game->map)// If one or the other fails, free the resources and return NULL
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
	return (game->map_copy);// Returns the final valid copy
}

/* Responsible for reading, validating, and preparing the map for the game
Receives the duplicate of the map
Converts the map into a matrix
return the map*/

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
