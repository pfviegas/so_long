/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:08:51 by paulo             #+#    #+#             */
/*   Updated: 2023/08/23 14:11:09 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	game->temp = '0';
	if (game->map[line][col] == '1')
		return (-1);
	if (game->map[line][col] == 'C')
		game->collectibles--;
	if (game->map[line][col] == 'E' && game->collectibles > 0)
	{
		game->player_on_box = 1;
		game->temp = 'B';
		return (1);
	}
	if (game->map[line][col] == 'E' && game->collectibles == 0)
	{
		game->end_game = 1;
		ft_printf("\n\n\t\tCongrats!!!\tYOU WIN 🏆\n\n");
		close_window(game);
	}
	if (pressed_key != W && pressed_key != ARROW_UP 
		&& pressed_key != S && pressed_key != ARROW_DOWN
		&& pressed_key != A && pressed_key != ARROW_LEFT
		&& pressed_key != D && pressed_key != ARROW_RIGHT)
		return (-1);
	else
		return (1);
}

static void	move_player(t_game *game, int col, int line, int pressed_key)
{
	int	valid;
	int	tcol;
	int	tline;

	tcol = game->player_y;
	tline = game->player_x;
	valid = valid_move(game, col, line, pressed_key);
	if (valid != -1)
	{
		game->player_y = line;
		game->player_x = col;
		if (game->temp != 'B')
			game->map[line][col] = 'P';
		else
			game->map[line][col] = 'B';
		if (game->map[tcol][tline] != 'B')
			game->map[tcol][tline] = '0';
		else
			game->map[tcol][tline] = 'E';
		ft_printf("Movements: %d\n", game->move++);
		render_image(game);
	}
}

int	key_handling(int keycode, t_game *game)
{
	int	col;
	int	line;

	col = game->player_x;
	line = game->player_y;
	if (keycode == A || keycode == ARROW_LEFT)
		col--;
	else if (keycode == W || keycode == ARROW_UP)
		line--;
	else if (keycode == S || keycode == ARROW_DOWN)
		line++;
	else if (keycode == D || keycode == ARROW_RIGHT)
		col++;
	else if (keycode == ESC)
		close_window(game);
	if (game->end_game != 1)
		move_player(game, col, line, keycode);
	return (0);
}
