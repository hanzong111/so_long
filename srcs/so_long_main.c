/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/10 23:47:49 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	export DISPLAY=localhost:0.0	*/

int event(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 'w') /* W  || 13*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_UP));
	if (keycode == 's') /* S  || 1*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_DOWN));
	if (keycode == 'a') /* A  || 0*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_LEFT));
	if (keycode == 'd') /* D  || 2*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_RIGHT));
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

void	check_move_list(t_data *data)
{
	static int	counter;

	if (data->player.move_list != NULL)
	{
		if (data->player.move_list->content == MOVE_UP)
			data->player.y -= SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_DOWN)
			data->player.y += SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_LEFT)
			data->player.x -= SPRITE_W / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_RIGHT)
			data->player.x += SPRITE_W / PLAYER_MOVE;
		counter++;
	}
	if (counter % PLAYER_MOVE == 0 && data->player.move_list != NULL)
		data->player.move_list = data->player.move_list->next;
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

int	main(int argc, char **argv)
{
	t_data			data;

	error_check(argc, argv, &data.map);
	grid_gen(argv, &data.map, &data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	data.player.move_list = NULL;
	data.enemy.ff = data.sprites.coin_1;
	data.enemy.x = 6 * SPRITE_W;
	data.enemy.y = 6 * SPRITE_H;
	data.enemy.counter = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.window, event, &data);
	mlx_loop(data.mlx);
}
