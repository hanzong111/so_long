/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/08 23:43:05 by ojing-ha         ###   ########.fr       */
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
	sl_copy_image(&data->enemy.f_frame, &data->final_img, data->enemy.x, data->enemy.y);
}

int	render_next_frame(t_data *data)
{
	static int	i = 0;
	int		x = -1;
	int		y = -1;
	static int	temp;
	char	*path_1 = "sprites/Player_run_1.xpm";
	char	*path_2 = "sprites/Player_run_2.xpm";
	char	*path_3 = "sprites/Player_run_3.xpm";
	char	*path_4 = "sprites/Player_run_4.xpm";

	i++;
	temp = i % 40;
	// printf("i is %d\n", i);
	// printf("temp is %d\n", temp);
	if (temp <= 10)
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_1, &data->sprites.player.width, &data->sprites.player.height);
	else if (temp <= 20)
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_2, &data->sprites.player.width, &data->sprites.player.height);
	else if (temp <= 30)
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_3, &data->sprites.player.width, &data->sprites.player.height);
	else if (temp <= 40)
		data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, path_4, &data->sprites.player.width, &data->sprites.player.height);
	// data->final_img = (t_sl_img *)malloc(sizeof(t_sl_img));
	render_map(data);
	while (++x <= 15)
	{
		y = -1;
		while (++y <= 15)
			sl_copy_image(&data->sprites.pillar, &data->final_img, x * SPRITE_W, y * SPRITE_H);
	}
	enemy_move(data, i);
	sl_copy_image(&data->sprites.door, &data->final_img, 0, 7);
	sl_copy_image(&data->sprites.player, &data->final_img, data->player.x * SPRITE_W, data->player.y * SPRITE_H);
	mlx_put_image_to_window(data->mlx, data->window, data->final_img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->final_img.img);
	return (0);
}

void	get_sprites(t_data *data)
{
	char	*floor_path = "sprites/Floor.xpm";
	char	*coin_path = "sprites/Coin_1.xpm";
	char	*door_path = "sprites/Door Opened.xpm";


	data->sprites.coin.img = mlx_xpm_file_to_image(data->mlx, coin_path, &data->sprites.coin.width, &data->sprites.coin.height);
	data->sprites.door.img = mlx_xpm_file_to_image(data->mlx, door_path, &data->sprites.door.width, &data->sprites.door.height);
	data->sprites.pillar.img = mlx_xpm_file_to_image(data->mlx, floor_path, &data->sprites.pillar.width, &data->sprites.pillar.height);
}

int	main(int argc, char **argv)
{
	t_data			data;

	error_check(argc, argv, &data.map);
	grid_gen(argv, &data.map, &data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	render_map(&data);
	data.enemy.f_frame = data.sprites.coin;
	data.enemy.x = 6 * SPRITE_W;
	data.enemy.y = 6 * SPRITE_H;
	data.enemy.counter = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.window, event, &data);
	mlx_loop(data.mlx);
}
