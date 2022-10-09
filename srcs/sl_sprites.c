/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/09 20:01:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_sprites(t_data *data)
{
	char	*floor_path = "sprites/Floor.xpm";
	// char	*coin_path = "sprites/Coin_1.xpm";
	char	*door_path = "sprites/Door Opened.xpm";
	char	*wall_path = "sprites/Wall.xpm";

	// data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path, &data->sprites.coin.width, &data->sprites.coin.height);
	data->sprites.door.img = mlx_xpm_file_to_image(data->mlx, door_path, &data->sprites.door.width, &data->sprites.door.height);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx, floor_path, &data->sprites.floor.width, &data->sprites.floor.height);
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx, wall_path, &data->sprites.wall.width, &data->sprites.wall.height);
}
