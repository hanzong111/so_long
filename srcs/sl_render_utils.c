/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:36:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/10 23:09:17 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_floor(t_data *data, int x, int y)
{
	sl_copy_image(&data->sprites.floor, &data->final_img,
		data->start_x + (x * SPRITE_W), data->start_y + (y * SPRITE_H));
}

void	print_wall(t_data *data, int x, int y)
{
	sl_copy_image(&data->sprites.wall, &data->final_img,
		data->start_x + (x * SPRITE_W), data->start_y + (y * SPRITE_H));
}

void	print_collectables(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	sl_copy_image(&data->coin_ff, &data->final_img,
		data->start_x + (x * SPRITE_W), data->start_y + (y * SPRITE_H));
}

void	print_exit(t_data *data, int x, int y)
{
	print_floor(data, x, y);
	sl_copy_image(&data->sprites.door, &data->final_img,
		data->start_x + (x * SPRITE_W), data->start_y + (y * SPRITE_H));
}
