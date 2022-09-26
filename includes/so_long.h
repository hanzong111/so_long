/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:54:10 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:13 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SCREEN_W 1000
# define SCREEN_H 1000
# define SPRITE_W 64
# define SPRITE_H 64

typedef struct s_sl_data_addr
{
	char	*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		pixel;
}	t_sl_data_addr;

typedef struct s_sl_img
{
	void	*img;
	int		width;
	int		height;
}	t_sl_img;

typedef struct s_sl_map
{
	char	**grid;
	char	*line;
	
	int		map_w;
	int		map_h;
	int		counter;
	int		line_len;

	int		space;
	int		wall;
	int		collectible;
	int		exit;
	int		player;
	int		enemy;
}	t_sl_map;

void	sl_copy_image(t_sl_img *src, t_sl_img *des, int x, int y);
void	error_check(int argc, char **argv, t_sl_map *map);
void	format_check(char **argv, t_sl_map *map);
void	grid_gen(char **argv, t_sl_map *map);

void	map_init(t_sl_map *map);

#endif