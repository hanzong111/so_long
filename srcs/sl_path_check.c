/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:30:03 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/14 23:22:57 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	data_count(t_data *data, char var)
// {
// 	if (var == 'C')
// 		data->path.coins++;
// 	else if (var == 'E')
// 		data->path.exit++;
// }

void	flood_fill(t_data *data, char **grid, int x, int y)
{
	int	w;
	int	h;

	w = data->map.map_w;
	h = data->map.map_h;
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

void	path_check(char **argv, t_data *data)
{
	flood_grid_gen(argv, data);
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
