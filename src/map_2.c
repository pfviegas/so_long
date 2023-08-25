/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:28:48 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/25 18:10:55 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// coloca as imagens do jogo na janela de acordo com mapa
void	put_map(int x, int y, int *len, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 64, y * 64);
	if (c == 'E')
	{
		if (game->collectibles == 0)
		{
			mlx_destroy_image(game->mlx, game->img.exit);
			game->img.exit = mlx_xpm_file_to_image
				(game->mlx, PORTAL, len, len);
		}
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	}
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * 64, y * 64);
	if (c == 'B')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.on_exit, x * 64, y * 64);
}

// Inicializa as imagens do jogo
void	init_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, BAG, &len, &len);
	game->img.on_exit = mlx_xpm_file_to_image(game->mlx, ON_EXIT, &len, &len);
}
