/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:54:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/17 17:55:31 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	copy_tile(t_data *data, int x, int y)
{
	if (data->map.grid[y][x] == 'C')
		print_coin(data, x, y);
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
	data->final_img.w = SCREEN_W;
	data->final_img.h = SCREEN_H;
	data->start_x = 7 * SPRITE_W - data->player.x;
	data->start_y = 7 * SPRITE_H - data->player.y;
}

void	render_map(t_data *data)
{
	int	width;
	int	h;

	get_data(data);
	h = 0;
	while (data->map.grid[h] != NULL)
	{
		width = 0;
		while (data->map.grid[h][width] != '\0')
		{
			if (data->start_x + (width * SPRITE_W) < -SPRITE_W)
				width++;
			else
			{
				copy_tile(data, width, h);
				width++;
			}
		}
		h++;
	}
	sl_copy_image(&data->player.ff, &data->final_img,
		7 * SPRITE_H, 7 * SPRITE_W);
}
