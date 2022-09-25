/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:54:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/26 01:33:36 by ojing-ha         ###   ########.fr       */
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
		ft_printf("Error\nInvalid format (New line at the end of map)\n");
		free(map->line);
		exit (0);
	}
	while (map->line[i] != '\n')
	{
		if (map->line[i] == '\0')
			break ;
		if (char_compare(map->line[i]))
		{
			ft_printf("Error\n'%c' is not a valid character\n", map->line[i]);
			free(map->line);
			exit (0);
		}
		i++;
	}
}

void	get_wh_char_check(char **argv, t_sl_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	map->line = get_next_line(fd);
	if (map->line == NULL)
	{
		ft_printf("Error\nInvalid map format (Empty .ber File)\n");
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
		ft_printf("Error\nInvalid map format (Map is Too Small)\n");
		exit(0);
	}
	close(fd);
}

void	arguments_check(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error\nPlease pass only 1 map at a time\n");
		else
			ft_printf("Error\nPlease pass at least 1 map\n");
		exit (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found/File Does not exist (Specify Path)\n");
		close(fd);
		exit (0);
	}
	close(fd);
	str = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (str == NULL || ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
	{
		ft_printf("Error\nFile is not a .ber file\n");
		exit(0);
	}
}

void	error_check(int argc, char **argv, t_sl_map *map)
{
	arguments_check(argc, argv);
	map_init(map);
	get_wh_char_check(argv, map);
	format_check(argv, map);
}
