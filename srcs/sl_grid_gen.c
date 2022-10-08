/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:16:07 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/08 23:33:15 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_char_count(t_sl_map *map, char *str)
{
	while (*str != '\0')
	{
		if (*str == 'C')
			map->collectible++;
		else if (*str == 'E')
			map->exit++;
		else if (*str == 'P')
			map->player++;
		if (map->player >= 2 || map->exit >= 2)
		{
			if (map->player >= 2)
				ft_printf("Error\nThere can only be 1 Player\n");
			else
				ft_printf("Error\nThere can only be 1 exit\n");
			exit (0);
		}
		str++;
	}
}

void	get_player_position(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.grid[x] != NULL)
	{
		y = 0;
		while (data->map.grid[x][y] != '\0')
		{
			if (data->map.grid[x][y] == 'P')
			{
				data->player.x = y;
				data->player.y = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	grid_gen(char **argv, t_sl_map *map, t_data *data)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	map->grid = malloc(sizeof(char *) * (map->map_h + 1));
	map->grid[map->map_h] = NULL;
	map->line = get_next_line(fd);
	i = -1;
	while (++i < map->map_h)
	{
		map->grid[i] = ft_substr(map->line, 0, map->map_w);
		map_char_count(map, map->grid[i]);
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
	if (map->player == 0 || map->exit == 0)
	{
		if (map->player == 0)
			ft_printf("Error\nThere needs to be at least 1 player\n");
		else
			ft_printf("Error\nThere needs to be at least 1 exit\n");
		exit (0);
	}
	get_player_position(data);
}
