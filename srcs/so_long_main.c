/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/17 22:29:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	export DISPLAY=localhost:0.0	*/

int	event(int keycode, t_data *data)
{
	if (keycode == 53) /*65307 || 53*/
		exit(0);
	if (keycode == 13) /* W  || 13*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_UP));
	if (keycode == 1) /* S  || 1*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_DOWN));
	if (keycode == 0) /* A  || 0*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_LEFT));
	if (keycode == 2) /* D  || 2*/
		sl_lstadd_back(&data->player.move_list, sl_lstnew(MOVE_RIGHT));
	return (0);
}

int	render_next_frame(t_data *data)
{
	static int	tick;

	tick++;
	check_move_list(data);
	choose_frame(tick, data);
	render_map(data);
	add_enemy(data);
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
	ft_printf("Checking map...\n");
	grid_gen(argv, &data.map, &data);
	path_check(argv, &data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "so_long");
	get_sprites(&data);
	ft_printf("Getting beautiful sprites...\n");
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.window, event, &data);
	mlx_hook(data.window, ON_DESTROY, 0L, sl_close_window, &data);
	mlx_loop(data.mlx);
}
