/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:54:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/09 17:01:59 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_tile(t_data *data, int x, int y)
{
	if (data->map.grid[y][x] == 'C')
		print_collectables(data, x, y);
	else if (data->map.grid[y][x] == 'E')
		print_exit(data, x, y);
	else if (data->map.grid[y][x] == '1')
		print_wall(data, x, y);
	else if (data->map.grid[y][x] == '0' || data->map.grid[y][x] == 'P')
		print_floor(data, x, y);
}

void	get_data(t_data *data)
{
	data->final_img.img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->final_img.width = SCREEN_W;
	data->final_img.height = SCREEN_H;
	data->start_x = 7 - data->player.x;
	data->start_y = 7 - data->player.y;
}

void	render_map(t_data *data)
{
	int	width;
	int	height;

	get_data(data);
	height = 0;
	while (data->map.grid[height] != NULL)
	{
		width = 0;
		while (data->map.grid[height][width] != '\0')
		{
			if (data->start_x + width < 0)
				width++;
			else
			{
				copy_tile(data, width, height);
				width++;
			}
		}
		height++;
	}
	sl_copy_image(&data->sprites.player, &data->final_img,
		7 * SPRITE_H, 7 * SPRITE_W);
}
