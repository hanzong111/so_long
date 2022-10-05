/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/05 22:36:18 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	export DISPLAY=localhost:0.0	*/

int event(int keycode, t_data *data)
{
	if (keycode == 'w') /* W  || 13*/
		data->y -= 1 * SPRITE_H;
	if (keycode == 's') /* S  || 1*/
		data->y += 1 * SPRITE_H;
	if (keycode == 'a') /* A  || 0*/
		data->x -= 1 * SPRITE_W;
	if (keycode == 'd') /* D  || 2*/
		data->x += 1 * SPRITE_W;
	printf("x is %d\n", data->x);
	printf("y is %d\n", data->y);
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
		data->player.img = mlx_xpm_file_to_image(data->mlx, path_1, &data->player.width, &data->player.height);
	else if (temp <= 20)
		data->player.img = mlx_xpm_file_to_image(data->mlx, path_2, &data->player.width, &data->player.height);
	else if (temp <= 30)
		data->player.img = mlx_xpm_file_to_image(data->mlx, path_3, &data->player.width, &data->player.height);
	else if (temp <= 40)
		data->player.img = mlx_xpm_file_to_image(data->mlx, path_4, &data->player.width, &data->player.height);
	// data->final_img = (t_sl_img *)malloc(sizeof(t_sl_img));
	data->final_img.img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->final_img.width = SCREEN_W;
	data->final_img.height= SCREEN_H;
	while (++x <= 10)
	{
		y = -1;
		while (++y <= 10)
			sl_copy_image(&data->pillar, &data->final_img, x * SPRITE_W, y * SPRITE_H);
	}
	enemy_move(data, i);
	sl_copy_image(&data->door, &data->final_img, 0, 7);
	sl_copy_image(&data->player, &data->final_img, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->final_img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->final_img.img);
	data->counter = 0;
	return (0);
}

void	get_sprites(t_data *data)
{
	char	*floor_path = "sprites/Floor.xpm";
	char	*coin_path = "sprites/Coin_1.xpm";
	char	*door_path = "sprites/Door Opened.xpm";


	data->coin.img = mlx_xpm_file_to_image(data->mlx, coin_path, &data->coin.width, &data->coin.height);
	data->door.img = mlx_xpm_file_to_image(data->mlx, door_path, &data->door.width, &data->door.height);
	data->pillar.img = mlx_xpm_file_to_image(data->mlx, floor_path, &data->pillar.width, &data->pillar.height);
}

int	main(int argc, char **argv)
{
	t_data			data;

	error_check(argc, argv, &data.map);
	grid_gen(argv, &data.map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	data.enemy.f_frame = data.coin;
	data.enemy.x = 6 * SPRITE_W;
	data.enemy.y = 6 * SPRITE_H;
	data.enemy.counter = 0;
	data.x = 30;
	data.y = 30;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.mlx_win, event, &data);
	mlx_loop(data.mlx);
}

/*	mlx_init() : To create a mlx pointer. 	*/
/*	mlx_new_window() : To create a window.	*/
/*	mlx_hook() : To loop.					*/
