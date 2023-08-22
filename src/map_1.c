/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:35:05 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/22 18:25:11 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// lê as linhas do mapa e retorna o número de linhas
int	get_lines(t_game *game, int fd)
{
	char	*content_line;
	int		lines;

	lines = 0;
	content_line = ft_get_next_line(fd);
	while (content_line)
	{
		lines++;
		free(content_line);
		content_line = ft_get_next_line(fd);
	}
	free(content_line);
	if (lines == 0)
		quit("The file is empty or not exist.", game, 3);
	return (lines);
}

// verifica se o mapa é retangular e armazena o mapa e o número de colunas
void	get_map(t_game *game, int fd)
{
	int		i;
	char	*content_line;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->line + 1));
	game->map_floodfill = (char **)malloc(sizeof(char *) * (game->line + 1));
	if (!game->map || !game->map_floodfill)
		quit("Malloc error.", game, 4);
	while (i < game->line)
	{
		content_line = ft_get_next_line(fd);
		game->map[i] = ft_strtrim(content_line, "\n");
		game->map_floodfill[i] = ft_strtrim(content_line, "\n");
		if (i > 0)
		{
			if (ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			{
				free(content_line);
				quit("The map must be rectangular.", game, 13);
			}
		}
		i++;
		free(content_line);
	}
	game->map[i] = NULL;
	game->map_floodfill[i] = NULL;
	game->column = ft_strlen(game->map[i - 1]);
}

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

// localiza a posição do jogador no mapa
void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line)
	{
		while (y < game->column)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	render_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->line)
	{
		x = 0;
		while (x < game->column)
		{
			put_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
