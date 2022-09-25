/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_format_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:42:57 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/26 01:33:34 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_n_lines(t_sl_map *map)
{
	int	i;

	i = -1;
	map->line_len = ft_strlen(map->line) - 1;
	if (map->line_len != map->map_w)
	{
		ft_printf("Error\nMap is not rectangular\n");
		exit(0);
	}
	while (++i < map->map_w)
	{
		if (i == 0 || i == (map->map_w - 1))
		{
			if (map->line[i] != '1')
			{
				ft_printf("Error\nMap is not enclosed\n");
				exit(0);
			}
		}
	}
}

void	check_first_last_line(t_sl_map *map)
{
	int	i;

	i = -1;
	while (++i < map->map_w)
	{
		if (map->line[i] != '1')
		{
			ft_printf("Error\nMap is not enclosed\n");
			exit(0);
		}
	}
	if (map->counter == map->map_h && map->line[i] != '\0')
	{
		ft_printf("Error\nInvalid format (New line at the end of map)\n");
		exit (0);
	}
}

void	format_check(char **argv, t_sl_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	map->line = get_next_line(fd);
	while (map->line != NULL)
	{
		if (map->counter == 1 || map->counter == map->map_h)
			check_first_last_line(map);
		else
			check_n_lines(map);
		map->counter++;
		free(map->line);
		map->line = get_next_line(fd);
	}
	close(fd);
}
