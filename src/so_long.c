/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:11:04 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/18 15:40:07 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	start_map(t_game *game)
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

static void	validations(t_game *game, int fd)
{
	check_map(game);
	check_walls(game);
	check_path(game, fd);
}

/*
void	start_game(t_game *game)
{	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->column * 64,
			game->line * 64, "So_long");
	mlx_hook(game->win, 02, 1L, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	put_images(game);
	render_img(game);
	mlx_loop(game->mlx);
}
*/

int	main(int argc, char **argv)
{
	t_game	game;	
	int		fd_map;

	check_args(&game, argc, argv);
	start_map(&game);
	fd_map = open(argv[1], O_RDONLY);
	game.line = get_lines(&game, fd_map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	get_map(&game, fd_map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	close(fd_map);
	validations(&game, fd_map);
	
	printf ("\ngame->collectibles = %d\n", game.collectibles);
	printf ("game->player_x = %d\n", game.player_x);
	printf ("game->player_y = %d\n", game.player_y);
	printf ("game->player_on_box = %d\n", game.player_on_box);
	printf ("game->exit = %d\n", game.exit);
	printf ("game->player = %d\n", game.player);
	printf ("game->line = %d\n", game.line);
	printf ("game->column = %d\n", game.column);
	printf ("game->end_game = %d\n", game.end_game);
	printf ("game->move = %d\n\n", game.move);
	
/*	
	fd = open(argv[1], O_RDONLY);
	if (game.column <= 0)
		quit("Invalid number of columns.", &game, 15);
	if (game.line <= 0)
		quit("Invalid number of lines.", &game, 16);
	player_position(&game);
	start_game(&game);
*/
	return(0);
}
