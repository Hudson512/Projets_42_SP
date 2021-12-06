/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:47 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/06 20:45:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		input_validation(int argc, char *map_path, t_game *game)
{
	// passou qtd certa de argumentos?
	if (argc != 2)
		flush("Invalid number of arguments (only one accepted)", game);
	// extensão do mapa é .ber?
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		flush("Map format invalid (only .ber allowed)", game);
	game->map->map_path = ft_strdup(map_path);
	return ;
}

static void	char_validation(char *map_str, t_game *game)
{
	while(*map_str)
	{
		if (*map_str == 'C')
			game->map->C_count++;
		if (*map_str == 'E')
			game->map->E_count++;
		if (*map_str == 'P')
			game->map->P_count++;
		if (*map_str != '\n' && !ft_strchr(VALID_MAP_CHARS, *map_str))
			flush("Invalid char found, only EPC10 allowed", game);
		map_str++;
	}
	if (game->map->C_count < 1)
		flush("Map has no collectibles", game);
	if (game->map->E_count < 1)
		flush("Map has no exit", game);
	if (game->map->P_count != 1)
		flush("Map must have no more and no less than one player", game);
	return ;
}

static int	surrounded_by_walls(t_game *game)
{
	size_t	i;

	i = -1;
	// checa paredes laterais
	while (game->map->grid[++i])
	{
		if (game->map->grid[i][0] != '1'
			|| game->map->grid[i][game->map->cols - 1] != '1')
			return (0);
	}
	i = -1;
	// checa paredes de cima e de baixo
	while (++i < game->map->cols)
	{
		if (game->map->grid[0][i] != '1'
			|| game->map->grid[game->map->rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

static int	is_rectangular(t_game *game)
{
	int i;

	game->map->cols = ft_strlen(game->map->grid[0]);
	i = -1;
	while(game->map->grid[++i])
	{
		if (ft_strlen(game->map->grid[i]) != game->map->cols)
			return (0);
		game->map->rows++;
	}
	return (1);
}

void	map_validation(t_game *game)
{
	int		fd;
	char 	*buffer;
	char	linear_map[500];
	int		read_count;

	fd = open(game->map->map_path, O_RDONLY);
	if (fd < 0)
		flush("nError while opening file", game);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		flush("Error while allocating memory for map", game);
	buffer[BUFFER_SIZE] = '\0';
	ft_bzero(linear_map, 500);
	read_count = read(fd, buffer, BUFFER_SIZE);
	while(read_count > 0)
	{
		buffer[read_count] = '\0';
		ft_strlcat(linear_map, buffer, 500);
		read_count = read(fd, buffer, BUFFER_SIZE);
	}
	if (!*linear_map)
		flush("Map is e m p t y !", game);
	char_validation(linear_map, game);
	// monta o MAPA
	game->map->grid = ft_split(linear_map, '\n');
	if (game->map->grid == NULL)
		flush("Error while allocating memory for map", game);
	// valida linha por linha
	if (!is_rectangular(game))
		flush("Map must be square/rectangular", game);
	if (!surrounded_by_walls(game))
		flush("Map must be surrounded by walls", game);
	if (close(fd) == -1)
		flush("Error while closing fd", game);
	free(buffer);
	return ;
}
