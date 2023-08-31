/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:13:32 by paulo             #+#    #+#             */
/*   Updated: 2023/08/31 12:10:38 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	animation(t_game *game)
{
	animate(game);
	return (0);
}

static void	frame_update(t_game *game)
{
	if (game->frame < 5)
		game->frame++;
	else
		game->frame = 1;
}

static void	animate_danger(t_game *game)
{
	int	len;

	len = 64;
	mlx_destroy_image(game->mlx, game->img.danger);
	if (game->frame == 1)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER1, &len, &len);
	else if (game->frame == 2)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER2, &len, &len);
	else if (game->frame == 3)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER3, &len, &len);
	else if (game->frame == 4)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER4, &len, &len);
	else if (game->frame == 5)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER5, &len, &len);
}

void	animate(t_game *game)
{
	if (game->anim_speed < ANIMATION_SPEED)
	{
		game->anim_speed++;
		return ;
	}
	else
		game->anim_speed = 0;
	frame_update(game);
	animate_danger(game);
	render_map(game);
}
