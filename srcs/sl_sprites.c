/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/18 18:20:59 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_coin(t_data *data)
{
	char	*coin_1;
	char	*coin_2;
	char	*coin_3;
	char	*coin_4;

	coin_1 = "sprites/Coin_1.xpm";
	coin_2 = "sprites/Coin_2.xpm";
	coin_3 = "sprites/Coin_3.xpm";
	coin_4 = "sprites/Coin_4.xpm";
	data->sprites.coin_1.img = mlx_xpm_file_to_image(data->mlx, coin_1,
			&data->sprites.coin_1.w, &data->sprites.coin_1.h);
	data->sprites.coin_2.img = mlx_xpm_file_to_image(data->mlx, coin_2,
			&data->sprites.coin_2.w, &data->sprites.coin_2.h);
	data->sprites.coin_3.img = mlx_xpm_file_to_image(data->mlx, coin_3,
			&data->sprites.coin_3.w, &data->sprites.coin_3.h);
	data->sprites.coin_4.img = mlx_xpm_file_to_image(data->mlx, coin_4,
			&data->sprites.coin_4.w, &data->sprites.coin_4.h);
}

void	get_enemy(t_data *data)
{
	char	*enemy_1;
	char	*enemy_2;
	char	*enemy_3;
	char	*enemy_4;

	enemy_1 = "sprites/Enemy_1.xpm";
	enemy_2 = "sprites/Enemy_2.xpm";
	enemy_3 = "sprites/Enemy_3.xpm";
	enemy_4 = "sprites/Enemy_4.xpm";
	data->sprites.enemy_1.img = mlx_xpm_file_to_image(data->mlx, enemy_1,
			&data->sprites.enemy_1.w, &data->sprites.enemy_1.h);
	data->sprites.enemy_2.img = mlx_xpm_file_to_image(data->mlx, enemy_2,
			&data->sprites.enemy_2.w, &data->sprites.enemy_2.h);
	data->sprites.enemy_3.img = mlx_xpm_file_to_image(data->mlx, enemy_3,
			&data->sprites.enemy_3.w, &data->sprites.enemy_3.h);
	data->sprites.enemy_4.img = mlx_xpm_file_to_image(data->mlx, enemy_4,
			&data->sprites.enemy_4.w, &data->sprites.enemy_4.h);
}

void	get_player(t_data *data)
{
	char	*player_1;
	char	*player_2;
	char	*player_3;
	char	*player_4;
	char	*player_5;
	char	*player_6;
	char	*player_7;
	char	*player_8;
	char	*player_9;

	player_1 = "sprites/Player_1.xpm";
	player_2 = "sprites/Player_2.xpm";
	player_3 = "sprites/Player_3.xpm";
	player_4 = "sprites/Player_4.xpm";
	player_5 = "sprites/Player_5.xpm";
	player_6 = "sprites/Player_6.xpm";
	player_7 = "sprites/Player_7.xpm";
	player_8 = "sprites/Player_8.xpm";
	player_9 = "sprites/Player_9.xpm";

	data->sprites.player_1.img = mlx_xpm_file_to_image(data->mlx, player_1,
			&data->sprites.player_1.w, &data->sprites.player_1.h);
	data->sprites.player_2.img = mlx_xpm_file_to_image(data->mlx, player_2,
			&data->sprites.player_2.w, &data->sprites.player_2.h);
	data->sprites.player_3.img = mlx_xpm_file_to_image(data->mlx, player_3,
			&data->sprites.player_3.w, &data->sprites.player_3.h);
	data->sprites.player_4.img = mlx_xpm_file_to_image(data->mlx, player_4,
			&data->sprites.player_4.w, &data->sprites.player_4.h);
	data->sprites.player_5.img = mlx_xpm_file_to_image(data->mlx, player_5,
			&data->sprites.player_5.w, &data->sprites.player_5.h);
	data->sprites.player_6.img = mlx_xpm_file_to_image(data->mlx, player_6,
			&data->sprites.player_6.w, &data->sprites.player_6.h);
	data->sprites.player_7.img = mlx_xpm_file_to_image(data->mlx, player_7,
			&data->sprites.player_7.w, &data->sprites.player_7.h);
	data->sprites.player_8.img = mlx_xpm_file_to_image(data->mlx, player_8,
			&data->sprites.player_8.w, &data->sprites.player_8.h);
	data->sprites.player_9.img = mlx_xpm_file_to_image(data->mlx, player_9,
			&data->sprites.player_9.w, &data->sprites.player_9.h);
}

void	get_sprites(t_data *data)
{
	char	*floor_path;
	char	*door_o_path;
	char	*door_c_path;
	char	*wall_path;

	floor_path = "sprites/Floor.xpm";
	door_o_path = "sprites/Door Opened.xpm";
	door_c_path = "sprites/Door Closed.xpm";
	wall_path = "sprites/Wall.xpm";
	get_coin(data);
	get_player(data);
	get_enemy(data);
	data->sprites.door_o.img = mlx_xpm_file_to_image(data->mlx, door_o_path,
			&data->sprites.door_o.w, &data->sprites.door_o.h);
	data->sprites.door_c.img = mlx_xpm_file_to_image(data->mlx, door_c_path,
			&data->sprites.door_c.w, &data->sprites.door_c.h);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx, floor_path,
			&data->sprites.floor.w, &data->sprites.floor.h);
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx, wall_path,
			&data->sprites.wall.w, &data->sprites.wall.h);
}
