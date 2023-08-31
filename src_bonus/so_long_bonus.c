/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:11:04 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/31 12:07:46 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// inicializa as variáveis do jogo
static void	init_var(t_game *game)
{
	game->map = NULL;
	game->map_floodfill = NULL;
	game->collectibles = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_exit = 0;
	game->exit = 0;
	game->player = 0;
	game->line = 0;
	game->column = 0;
	game->end_game = 0;
	game->move = 1;
	game->anim_speed = 0;
	game->frame = 1;
	game->img.wall = NULL;
	game->img.player = NULL;
	game->img.floor = NULL;
	game->img.exit = NULL;
	game->img.collectible = NULL;
	game->img.on_exit = NULL;
	game->img.danger = NULL;
}

// valida o mapa, as paredes e o caminho
static void	validations(t_game *game)
{
	check_map(game);
	if (game->column <= 0)
		quit("Invalid number of columns.", game, 14);
	if (game->line <= 0)
		quit("Invalid number of lines.", game, 15);
	check_walls(game);
	check_path(game);
}

// inicializa o ambiente gráfico, as imagens e o jogo
void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->column * 64,
			game->line * 64, "So_long");
	init_images(game);
	render_map(game);
	mlx_hook(game->win, 02, 1L << 0, key_handling, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_loop_hook(game->mlx, &animation, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;	
	int		fd_map;

	init_var(&game);
	check_args(&game, argc, argv);
	fd_map = open(argv[1], O_RDONLY);
	game.line = get_lines(&game, fd_map);
	close(fd_map);
	fd_map = open(argv[1], O_RDONLY);
	get_map(&game, fd_map);
	close(fd_map);
	validations(&game);
	start_game(&game);
	return (0);
}
