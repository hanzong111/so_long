/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/09 20:01:02 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	export DISPLAY=localhost:0.0	*/

int event(int keycode, t_data *data)
{
	if (keycode == 13) /* W  || 13*/
		data->player.y -= 1;
	if (keycode == 1) /* S  || 1*/
		data->player.y += 1;
	if (keycode == 0) /* A  || 0*/
		data->player.x -= 1;
	if (keycode == 2) /* D  || 2*/
		data->player.x += 1;
	return (0);
}

void	enemy_move(t_data *data, int i)
{
	int	max;
	int	min;
	int temp;

	temp = i;
	max = 8 * SPRITE_H;
	min = 4 * SPRITE_H;
	if (temp)
	{
		if (data->enemy.y <= max && data->enemy.counter == 0)
		{
			if (data->enemy.y == max)
				data->enemy.counter++;
			if (data->enemy.y != max)
				data->enemy.y += ENEMY_STEPS;
		}
		else if (data->enemy.y >= min && data->enemy.counter == 1)
		{
			if (data->enemy.y == min)
				data->enemy.counter--;
			if (data->enemy.y != min)
				data->enemy.y -= ENEMY_STEPS;
		}
	}
	sl_copy_image(&data->enemy.ff, &data->final_img, data->enemy.x - data->start_x * SPRITE_W, data->enemy.y - data->start_y * SPRITE_H);
}

int	render_next_frame(t_data *data)
{
	static int	i = 0;
	static int	temp;
	char	*path_1 = "sprites/Player_run_1.xpm";
	char	*path_2 = "sprites/Player_run_2.xpm";
	char	*path_3 = "sprites/Player_run_3.xpm";
	char	*path_4 = "sprites/Player_run_4.xpm";
	char	*coin_path1 = "sprites/Coin_1.xpm";
	char	*coin_path2 = "sprites/Coin_2.xpm";
	char	*coin_path3 = "sprites/Coin_3.xpm";
	char	*coin_path4 = "sprites/Coin_4.xpm";

	i++;
	temp = i % 20;
	if (temp <= 5)
	{
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_1, &data->sprites.player.width, &data->sprites.player.height);
		data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path1, &data->sprites.coin.width, &data->sprites.coin.height);
	}
	else if (temp <= 10)
	{
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_2, &data->sprites.player.width, &data->sprites.player.height);
		data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path2, &data->sprites.coin.width, &data->sprites.coin.height);
	}
	else if (temp <= 15)
	{
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_3, &data->sprites.player.width, &data->sprites.player.height);
		data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path3, &data->sprites.coin.width, &data->sprites.coin.height);
	}
	else if (temp <= 20)
	{
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_4, &data->sprites.player.width, &data->sprites.player.height);
		data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path4, &data->sprites.coin.width, &data->sprites.coin.height);
	}
	render_map(data);
	enemy_move(data, i);
	mlx_put_image_to_window(data->mlx, data->window, data->final_img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->final_img.img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	error_check(argc, argv, &data.map);
	grid_gen(argv, &data.map, &data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	data.enemy.ff = data.sprites.coin;
	data.enemy.x = 6 * SPRITE_W;
	data.enemy.y = 6 * SPRITE_H;
	data.enemy.counter = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.window, event, &data);
	mlx_loop(data.mlx);
}
