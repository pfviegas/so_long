/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:19:42 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/18 17:38:18 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define CAT "./images/cat.xpm"
# define SUSHI "./images/sushi.xpm"
# define BOX "./images/exit.xpm"
# define WALL "./images/wall.xpm"
# define FLOOR "./images/floor.xpm"
# define ON_BOX "./images/on_box.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_box;
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
void		free_map_floodfill(t_game *game);
void		player_position(t_game *game);
void		start_game(t_game *game);
int			key_handler(int keycode, t_game *game);
int			close_window(t_game *game);

#endif
