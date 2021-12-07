/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:14:44 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/07 02:02:35 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_memory(t_game *game)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->window = ft_calloc(1, sizeof(t_window));
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos = ft_calloc(1, sizeof(t_coords));
	game->collectible = ft_calloc(1, sizeof(t_collectible));
	game->map->tile = ft_calloc(1, sizeof(t_collectible));
	if (game->map == NULL || game->window == NULL || game->player == NULL
		|| game->collectible == NULL || game->player->pos == NULL
		|| game->map->tile == NULL)
		flush("Memory allocation failed, closing game. . .", game);
	return ;
}

void	initialise_values(t_game *game)
{
	game->map->c_count = 0;
	game->map->e_count = 0;
	game->map->p_count = 0;
	game->map->rows = 0;
	game->map->tile_width = 64;
	game->map->tile_height = 64;
	game->player->direction = 'l';
	game->player->moves_count = 0;
	return ;
}

void	load_sprites(t_game *game)
{
	game->player->sprite_path = ft_calloc(4, sizeof(char *));
	if (game->player->sprite_path == NULL)
		flush("Error allocating memory for player sprite paths", game);
	game->player->sprite_path[0] = "./resources/images/pikachu_u1_64.xpm";
	game->player->sprite_path[1] = "./resources/images/pikachu_l1_64.xpm";
	game->player->sprite_path[2] = "./resources/images/pikachu_d1_64.xpm";
	game->player->sprite_path[3] = "./resources/images/pikachu_r1_64.xpm";
	game->map->floor_path = "./resources/images/floor_64.xpm";
	game->map->wall_path = "./resources/images/stone_64.xpm";
	game->map->exit_path = "./resources/images/exit_64.xpm";
	game->collectible->sprite_path = "./resources/images/pokeball_64.xpm";
	*(game->player->pos) = find_position('P', game);
	return ;
}

void	generate_images(t_game *game)
{
	generate_player_img(game);
	generate_floor_img(game);
	generate_wall_img(game);
	generate_exit_img(game);
	generate_collectibles_img(game);
	return ;
}

void	initialise_minilibx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		flush("MLX_ERROR while initialising mlx", game);
	return ;
}