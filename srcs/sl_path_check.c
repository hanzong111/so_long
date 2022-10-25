/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:30:03 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/19 20:19:19 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_data *data, char **grid, int x, int y)
{
	if (grid[y][x] == '1')
		return ;
	else
	{
		if (grid[y][x] == 'C')
			data->path.coins++;
		else if (grid[y][x] == 'E')
			data->path.exit++;
		grid[y][x] = '1';
		flood_fill(data, grid, (x + 1), y);
		flood_fill(data, grid, (x - 1), y);
		flood_fill(data, grid, x, (y + 1));
		flood_fill(data, grid, x, (y - 1));
	}
}

void	flood_grid_gen(char **argv, t_data *data)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	data->flood_map.grid = malloc(sizeof(char *) * (data->map.map_h + 1));
	data->map.grid[data->map.map_h] = NULL;
	data->flood_map.line = get_next_line(fd);
	i = -1;
	while (++i < data->map.map_h)
	{
		data->flood_map.grid[i] = ft_substr(data->flood_map.line,
				0, data->map.map_w);
		free(data->flood_map.line);
		data->flood_map.line = get_next_line(fd);
	}
	close(fd);
}

int	set_enemy_position(int x, int y, int counter, t_data *data)
{
	data->enemy_list[counter] = (t_sl_enemy *)malloc(sizeof(t_sl_enemy) * 2);
	data->enemy_list[counter][0].x = x * SPRITE_W;
	data->enemy_list[counter][0].y = y * SPRITE_H;
	return (counter + 1);
}

void	get_enemy_positions(t_data *data)
{
	int	x;
	int	y;
	int	counter;

	y = 0;
	counter = 0;
	data->enemy_list = (t_sl_enemy **)malloc(sizeof(t_sl_enemy *)
			* (data->map.enemy + 1));
	data->enemy_list[data->map.enemy] = NULL;
	while (y < data->map.map_h)
	{
		x = 0;
		while (data->flood_map.grid[y][x] != '\0')
		{
			if (data->flood_map.grid[y][x] == 'N')
				counter = set_enemy_position(x, y, counter, data);
			x++;
		}
		y++;
	}
}

void	path_check(char **argv, t_data *data)
{
	flood_grid_gen(argv, data);
	get_enemy_positions(data);
	flood_fill(data, data->flood_map.grid, data->player.x / SPRITE_W,
		data->player.y / SPRITE_H);
	if (data->path.coins != data->map.coins)
	{
		ft_printf("Error\nNot all coins are accesible\n");
		exit (0);
	}
	if (data->path.exit == 0)
	{
		ft_printf("Error\nNo valid path to exit\n");
		exit (0);
	}
}
