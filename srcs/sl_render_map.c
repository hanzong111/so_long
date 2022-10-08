/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:54:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/08 23:42:27 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_data *data)
{
	data->final_img.img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->final_img.width = SCREEN_W;
	data->final_img.height = SCREEN_H;
}
