/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:58 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/09 17:21:43 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map->grid[++i])
	{
		j = -1;
		while (game->map->grid[i][++j])
		{
			if (game->map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window->win_ptr,
					game->map->wall_img, TILE_SIZE * j,
					TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx, game->window->win_ptr,
					game->map->floor_img, TILE_SIZE * j,
					TILE_SIZE * i);
		}
	}
	return ;
}

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window->win_ptr,
		game->player->img[game->player->direction - 'i'],
		TILE_SIZE * game->player->pos->y,
		TILE_SIZE * game->player->pos->x);
	return ;
}

int	render_window(t_game *game)
{
	int		i;
	int		j;

	if (game->window->win_ptr != NULL)
	{
		render_map(game);
		i = -1;
		while (game->map->grid[++i])
		{
			j = -1;
			while (game->map->grid[i][++j])
			{
					if (game->map->grid[i][j] == 'E')
						mlx_put_image_to_window(game->mlx, game->window->win_ptr,
							game->map->exit_img, TILE_SIZE * j,
							TILE_SIZE * i);
					if (game->map->grid[i][j] == 'C')
						mlx_put_image_to_window(game->mlx, game->window->win_ptr,
							game->collectible->img, TILE_SIZE * j,
							TILE_SIZE * i);
					if (game->map->grid[i][j] == 'M')
						mlx_put_image_to_window(game->mlx, game->window->win_ptr,
							game->map->mewtwo_img, TILE_SIZE * j,
							TILE_SIZE * i);
			}
		}
		render_player(game);
	}
	return (0);
}

void	render_you_won(t_game *game)
{
	close_window(game);
	return ;
}

void	open_window(t_game *game)
{
	game->window->width = TILE_SIZE * game->map->cols;
	game->window->height = TILE_SIZE * game->map->rows;
	game->window->win_ptr = mlx_new_window(game->mlx,
			game->window->width,
			game->window->height,
			"ma fenetre");
	if (game->window->win_ptr == NULL)
		flush("MLX_ERROR while opening new window", 0, game);
	return ;
}
