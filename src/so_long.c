/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:11:04 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/23 14:13:58 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_var(t_game *game)
{
	game->collectibles = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_box = 0;
	game->exit = 0;
	game->player = 0;
	game->line = 0;
	game->column = 0;
	game->end_game = 0;
	game->move = 1;
}

static void	validations(t_game *game)
{
	check_map(game);
	check_walls(game);
	check_path(game);
	if (game->column <= 0)
		quit("Invalid number of columns.", game, 14);
	if (game->line <= 0)
		quit("Invalid number of lines.", game, 15);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->column * 64,
			game->line * 64, "So_long");
	init_images(game);
	render_image(game);
	mlx_hook(game->win, 02, 1L, key_handling, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;	
	int		fd_map;

	check_args(&game, argc, argv);
	init_var(&game);
	fd_map = open(argv[1], O_RDONLY);
	game.line = get_lines(&game, fd_map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	get_map(&game, fd_map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	close(fd_map);
	validations(&game);
	start_game(&game);
	player_position(&game);
	return (0);
}
