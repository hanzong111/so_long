/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:10:52 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/10 18:19:11 by ojing-ha         ###   ########.fr       */
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
			&data->sprites.coin_1.width, &data->sprites.coin_1.height);
	data->sprites.coin_2.img = mlx_xpm_file_to_image(data->mlx, coin_2,
			&data->sprites.coin_2.width, &data->sprites.coin_2.height);
	data->sprites.coin_3.img = mlx_xpm_file_to_image(data->mlx, coin_3,
			&data->sprites.coin_3.width, &data->sprites.coin_3.height);
	data->sprites.coin_4.img = mlx_xpm_file_to_image(data->mlx, coin_4,
			&data->sprites.coin_4.width, &data->sprites.coin_4.height);
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
			&data->sprites.player_1.width, &data->sprites.player_1.height);
	data->sprites.player_2.img = mlx_xpm_file_to_image(data->mlx, player_2,
			&data->sprites.player_2.width, &data->sprites.player_2.height);
	data->sprites.player_3.img = mlx_xpm_file_to_image(data->mlx, player_3,
			&data->sprites.player_3.width, &data->sprites.player_3.height);
	data->sprites.player_4.img = mlx_xpm_file_to_image(data->mlx, player_4,
			&data->sprites.player_4.width, &data->sprites.player_4.height);
}

void	get_sprites(t_data *data)
{
	char	*floor_path;
	char	*door_path;
	char	*wall_path;

	floor_path = "sprites/Floor.xpm";
	door_path = "sprites/Door Opened.xpm";
	wall_path = "sprites/Wall.xpm";
	get_coin(data);
	get_player(data);
	data->sprites.door.img = mlx_xpm_file_to_image(data->mlx, door_path, &data->sprites.door.width, &data->sprites.door.height);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx, floor_path, &data->sprites.floor.width, &data->sprites.floor.height);
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx, wall_path, &data->sprites.wall.width, &data->sprites.wall.height);
}
