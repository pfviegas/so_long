/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:19:42 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/22 17:52:05 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WALL "./images/wall.xpm"
# define PLAYER "./images/cat.xpm"
# define FLOOR "./images/floor.xpm"
# define EXIT "./images/exit.xpm"
# define COLLECTIBLE "./images/sushi.xpm"
# define ON_EXIT "./images/on_box.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364


typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*floor;
	void	*exit;
	void	*collectible;
	void	*on_exit;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_floodfill;
	char	temp;
	int		collectibles;
	int		player_gamey;
	int		player_x;
	int		player_y;
	int		player_on_box;
	int		exit;
	int		player;
	int		line;
	int		column;
	int		end_game;
	int		move;
}	t_game;

void		check_args(t_game *game, int argc, char **argv);
void		quit(char *s, t_game *game, int exit_code);
int			count_collectibles(t_game *game);
int			get_lines(t_game *game, int fd);
void		get_map(t_game *game, int fd);
void		check_map(t_game *game);
void		check_char(t_game *game, char c, int line, int col);
void		check_walls(t_game *game);
void		check_path(t_game *game);
int			floodfill(t_game *game);
bool		fill(t_game *game, char c, int line, int col);
void		free_map(t_game *game);
void		free_map_floodfill(t_game *game);
void		free_img(t_game *game);
void		map_malloc_path(t_game *game);
void		valid_path(t_game *game, int fd);
void		player_position(t_game *game);
void		start_game(t_game *game);
int			key_handling(int keycode, t_game *game);
int			close_window(t_game *game);
void		init_images(t_game *game);
int			render_image(t_game *game);
void		put_map(int x, int y, char c, t_game *game);

#endif
