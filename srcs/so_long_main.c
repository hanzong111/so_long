/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/13 02:01:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	export DISPLAY=localhost:0.0	*/

int	event(int keycode, t_data *data)
{
	if (check_move(keycode, data, data->player.x / SPRITE_W,
			data->player.y / SPRITE_H))
	{
		if (keycode == 65307) /*65307 || 53*/
			exit(0);
		if (keycode == 'w') /* W  || 13*/
			sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_UP));
		if (keycode == 's') /* S  || 1*/
			sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_DOWN));
		if (keycode == 'a') /* A  || 0*/
			sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_LEFT));
		if (keycode == 'd') /* D  || 2*/
			sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_RIGHT));
	}
	return (0);
}

void	enemy_move(t_data *data, int i)
{
	int	max;
	int	min;
	int	temp;

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
	static int	i;

	i++;
	check_move_list(data);
	choose_frame(i, data);
	render_map(data);
	// enemy_move(data, i);
	mlx_put_image_to_window(data->mlx, data->window, data->final_img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->final_img.img);
	return (0);
}

int	sl_close_window(t_data *data)
{
	data->start_x = 3;
	ft_printf("Window closed.\n");
	ft_printf("Exiting so_long...\n");
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	var_init(&data);
	error_check(argc, argv, &data.map);
	grid_gen(argv, &data.map, &data);
	ft_printf("Checking map...\n");
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	ft_printf("Getting beautiful sprites...\n");
	data.enemy.ff = data.sprites.coin_1;
	data.enemy.x = 6 * SPRITE_W;
	data.enemy.y = 6 * SPRITE_H;
	data.enemy.counter = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.window, event, &data);
	mlx_hook(data.window, ON_DESTROY, 0L, sl_close_window, &data);
	mlx_loop(data.mlx);
}
