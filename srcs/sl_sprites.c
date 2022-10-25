/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/26 04:01:48 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	convert(t_data *data, char *path, t_sl_img *img)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->w, &img->h);
}

void	get_sprites_1(t_data *data)
{
	convert(data, "sprites/Coin_1.xpm", &data->sprites.coin_1);
	convert(data, "sprites/Coin_2.xpm", &data->sprites.coin_2);
	convert(data, "sprites/Coin_2.xpm", &data->sprites.coin_3);
	convert(data, "sprites/Coin_3.xpm", &data->sprites.coin_4);
	convert(data, "sprites/Enemy_1.xpm", &data->sprites.enemy_1);
	convert(data, "sprites/Enemy_2.xpm", &data->sprites.enemy_2);
	convert(data, "sprites/Enemy_3.xpm", &data->sprites.enemy_3);
	convert(data, "sprites/Enemy_4.xpm", &data->sprites.enemy_4);
	convert(data, "sprites/Door Opened.xpm", &data->sprites.door_o);
	convert(data, "sprites/Door Closed.xpm", &data->sprites.door_c);
	convert(data, "sprites/Floor.xpm", &data->sprites.floor);
	convert(data, "sprites/Wall.xpm", &data->sprites.wall);
	convert(data, "sprites/move.xpm", &data->sprites.move);
}

void	get_sprites_2(t_data *data)
{
	convert(data, "sprites/Player_1.xpm", &data->sprites.player_1);
	convert(data, "sprites/Player_2.xpm", &data->sprites.player_2);
	convert(data, "sprites/Player_3.xpm", &data->sprites.player_3);
	convert(data, "sprites/Player_4.xpm", &data->sprites.player_4);
	convert(data, "sprites/Player_5.xpm", &data->sprites.player_5);
	convert(data, "sprites/Player_6.xpm", &data->sprites.player_6);
	convert(data, "sprites/Player_7.xpm", &data->sprites.player_7);
	convert(data, "sprites/Player_8.xpm", &data->sprites.player_8);
	convert(data, "sprites/Player_9.xpm", &data->sprites.player_9);
	convert(data, "sprites/0.xpm", &data->sprites.numbers[0]);
	convert(data, "sprites/1.xpm", &data->sprites.numbers[1]);
	convert(data, "sprites/2.xpm", &data->sprites.numbers[2]);
	convert(data, "sprites/3.xpm", &data->sprites.numbers[3]);
	convert(data, "sprites/4.xpm", &data->sprites.numbers[4]);
	convert(data, "sprites/5.xpm", &data->sprites.numbers[5]);
	convert(data, "sprites/6.xpm", &data->sprites.numbers[6]);
	convert(data, "sprites/7.xpm", &data->sprites.numbers[7]);
	convert(data, "sprites/8.xpm", &data->sprites.numbers[8]);
	convert(data, "sprites/9.xpm", &data->sprites.numbers[9]);
}

void	get_sprites(t_data *data)
{
	get_sprites_1(data);
	get_sprites_2(data);
}
