/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:01:19 by pviegas           #+#    #+#             */
/*   Updated: 2023/09/01 12:01:21 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	frame_update(t_game *game)
{
	if (game->frame < 5)
		game->frame++;
	else
		game->frame = 1;
}

static void	animate_danger(t_game *game)
{
	int	s;

	s = 64;
	mlx_destroy_image(game->mlx, game->img.danger);
	if (game->frame == 1)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER1, &s, &s);
	else if (game->frame == 2)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER2, &s, &s);
	else if (game->frame == 3)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER3, &s, &s);
	else if (game->frame == 4)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER4, &s, &s);
	else if (game->frame == 5)
		game->img.danger = mlx_xpm_file_to_image(game->mlx, DANGER5, &s, &s);
}

int	animation(t_game *game)
{
	if (game->anim_speed < ANIMATION_SPEED)
	{
		usleep(1000);
		game->anim_speed++;
		return (0);
	}
	else
		game->anim_speed = 0;
	frame_update(game);
	animate_danger(game);
	render_map(game);
	return (0);
}
