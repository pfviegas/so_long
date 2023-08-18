/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:28:48 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/17 11:00:27 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (x < game->line)
	{
		while (y < game->column)
		{
			if (game->map[x][y] == 'C')
			{
				c++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (c);
}

/*
void	put_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.player = mlx_xpm_file_to_image(game->mlx, CAT, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, BOX, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, SUSHI, &len, &len);
	game->img.on_box = mlx_xpm_file_to_image(game->mlx, ON_BOX, &len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
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
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * 64, y * 64);
	if (c == 'B')//		ft_printf("Error\nFile must be of type .ber\n");
//		exit(2);
)
{
	int	x;
	int	y;

	x = 0;
	y = 0;//		ft_printf("Error\nFile must be of type .ber\n");
//		exit(2);

			y++;
		}
		y = 0;
		x++;
	}
}
*/
//		ft_printf("Error\nFile must be of type .ber\n");
//		exit(2);
