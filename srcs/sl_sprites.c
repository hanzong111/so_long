/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/13 02:13:44 by ojing-ha         ###   ########.fr       */
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

void	get_player(t_data *data)
{
	char	*player_1;
	char	*player_2;
	char	*player_3;
	char	*player_4;

	player_1 = "sprites/Player_run_1.xpm";
	player_2 = "sprites/Player_run_2.xpm";
	player_3 = "sprites/Player_run_3.xpm";
	player_4 = "sprites/Player_run_4.xpm";
	data->sprites.player_1.img = mlx_xpm_file_to_image(data->mlx, player_1,
			&data->sprites.player_1.w, &data->sprites.player_1.h);
	data->sprites.player_2.img = mlx_xpm_file_to_image(data->mlx, player_2,
			&data->sprites.player_2.w, &data->sprites.player_2.h);
	data->sprites.player_3.img = mlx_xpm_file_to_image(data->mlx, player_3,
			&data->sprites.player_3.w, &data->sprites.player_3.h);
	data->sprites.player_4.img = mlx_xpm_file_to_image(data->mlx, player_4,
			&data->sprites.player_4.w, &data->sprites.player_4.h);
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
	data->sprites.door_o.img = mlx_xpm_file_to_image(data->mlx, door_o_path,
			&data->sprites.door_o.w, &data->sprites.door_o.h);
	data->sprites.door_c.img = mlx_xpm_file_to_image(data->mlx, door_c_path,
			&data->sprites.door_c.w, &data->sprites.door_c.h);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx, floor_path,
			&data->sprites.floor.w, &data->sprites.floor.h);
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx, wall_path,
			&data->sprites.wall.w, &data->sprites.wall.h);
}
