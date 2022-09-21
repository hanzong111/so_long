/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/21 17:49:56 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
	int		width;
	int		height;
	int		counter;
	void		*img;
}t_data;

int event(int keycode, t_data *data)
{
	printf("keycode is %d\n", keycode);
	if (keycode == 13) /* W */
		data->y -= 64;
	if (keycode == 1) /* S */
		data->y += 64;
	if (keycode == 0) /* A */
		data->x -= 64;
	if (keycode == 2) /* D */
		data->x += 64;
	return (0);
}

int	render_next_frame(t_data *data)
{
	static int	i = 0;
	static int	temp;
	char	*path_1 = "/Users/ojing-ha/so_long/sprites/Player_run_1.xpm";
	char	*path_2 = "/Users/ojing-ha/so_long/sprites/Player_run_2.xpm";
	char	*path_3 = "/Users/ojing-ha/so_long/sprites/Player_run_3.xpm";
	char	*path_4 = "/Users/ojing-ha/so_long/sprites/Player_run_4.xpm";

	i++;
	temp = i % 40;
	// printf("i is %d\n", i);
	// printf("temp is %d\n", temp);
	mlx_key_hook(data->mlx_win, event, data);
	if (i != 1)
		mlx_clear_window(data->mlx,data->mlx_win);
	if (temp <= 10)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, path_1, &data->width, &data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	}
	else if (temp <= 20)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, path_2, &data->width, &data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	}
	else if (temp <= 30)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, path_3, &data->width, &data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	}
	else if (temp <= 40)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, path_4, &data->width, &data->height);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	}
	data->counter = 0;
	return (0);
}

int	main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "so_long");
	data.x = 0;
	data.y = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

/*	mlx_init() : To create a mlx pointer. 	*/
/*	mlx_new_window() : To create a window.	*/
/*	mlx_hook() : To loop.					*/
