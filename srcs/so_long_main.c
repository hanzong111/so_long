/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/25 08:18:43 by ojing-ha         ###   ########.fr       */
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
		data->y -= 1;
	if (keycode == 1) /* S */
		data->y += 1;
	if (keycode == 0) /* A */
		data->x -= 1;
	if (keycode == 2) /* D */
		data->x += 1;
	return (0);
}

void	draw_blue(t_sl_img *final_img)
{
	int color = 0xABCDEF;
	t_sl_data_addr		s;

	s.address = mlx_get_data_addr(final_img->img, &s.pixel_bits, &s.size_line, &s.endian);
	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
    int pixel = (y * s.size_line) + (x * 4);

    if (s.endian == 1)        // Most significant (Alpha) byte first
    {
        s.address[pixel + 0] = (color >> 24);
        s.address[pixel + 1] = (color >> 16) & 0xFF;
        s.address[pixel + 2] = (color >> 8) & 0xFF;
        s.address[pixel + 3] = (color) & 0xFF;
    }
    else if (s.endian == 0)   // Least significant (Blue) byte first
    {
        s.address[pixel + 0] = (color) & 0xFF;
        s.address[pixel + 1] = (color >> 8) & 0xFF;
        s.address[pixel + 2] = (color >> 16) & 0xFF;
        s.address[pixel + 3] = (color >> 24);
    }
	}
}

int	render_next_frame(t_data *data)
{
	static int	i = 0;
	static int	temp;
	char	*path_1 = "sprites/Player_run_1.xpm";
	char	*path_2 = "sprites/Player_run_2.xpm";
	char	*path_3 = "sprites/Player_run_3.xpm";
	char	*path_4 = "sprites/Player_run_4.xpm";
	char	*floor_path = "sprites/Pillar.xpm";
	t_sl_img	sprite;
	t_sl_img	final_img;
	t_sl_img	floor;

	i++;
	temp = i % 40;
	// printf("i is %d\n", i);
	// printf("temp is %d\n", temp);
	if (i != 1)
		mlx_clear_window(data->mlx, data->mlx_win);
	if (temp <= 10)
		sprite.img = mlx_xpm_file_to_image(data->mlx, path_1, &sprite.width, &sprite.height);
	else if (temp <= 20)
		sprite.img = mlx_xpm_file_to_image(data->mlx, path_2, &sprite.width, &sprite.height);
	else if (temp <= 30)
		sprite.img = mlx_xpm_file_to_image(data->mlx, path_3, &sprite.width, &sprite.height);
	else if (temp <= 40)
		sprite.img = mlx_xpm_file_to_image(data->mlx, path_4, &sprite.width, &sprite.height);
	final_img.img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	draw_blue(&final_img);
	floor.img = mlx_xpm_file_to_image(data->mlx, floor_path, &floor.width, &floor.height);
	sl_copy_image(&floor, &final_img, 4, 4);
	sl_copy_image(&floor, &final_img, 4, 5);
	sl_copy_image(&sprite, &final_img, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->mlx_win, final_img.img, 0, 0);
	mlx_destroy_image(data->mlx, final_img.img);
	data->counter = 0;
	return (0);
}

int	main()
{
	t_data		data;
	t_sl_map	map;

	error_check(&map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "so_long");
	data.x = 0;
	data.y = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.mlx_win, event, &data);
	mlx_loop(data.mlx);
}

/*	mlx_init() : To create a mlx pointer. 	*/
/*	mlx_new_window() : To create a window.	*/
/*	mlx_hook() : To loop.					*/
