/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:54:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/25 08:12:56 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	char_compare(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	else
		return (1);
}

void	check_character(t_sl_map *map)
{
	int	i;

	i = 0;
	map->map_h++;
	if (map->line[0] == '\n')
	{
		ft_printf("Map Error : Invalid format (New line at the end of map)\n");
		free(map->line);
		exit (0);
	}
	while (map->line[i] != '\n')
	{
		if (map->line[i] == '\0')
			break ;
		if (char_compare(map->line[i]))
		{
			ft_printf("Map Error : '%c' not a valid character\n", map->line[i]);
			free(map->line);
			exit (0);
		}
		i++;
	}
}

void	get_wh_char_check(t_sl_map *map)
{
	int	fd;

	fd = open("maps/try.ber", O_RDONLY);
	map->line = get_next_line(fd);
	if (map->line == NULL)
	{
		ft_printf("Map Error : Invalid map format (Empty .ber File)\n");
		exit(0);
	}
	map->map_w = ft_strlen(map->line) - 1;
	while (map->line != NULL)
	{
		check_character(map);
		free(map->line);
		map->line = get_next_line(fd);
	}
	if (map->map_h < 3 || map->map_w < 4)
	{
		ft_printf("Map Error : Invalid map format (Map is Too Small)\n");
		exit(0);
	}
	close(fd);
}

void	error_check(t_sl_map *map)
{
	map_init(map);
	get_wh_char_check(map);
	format_check(map);
}
