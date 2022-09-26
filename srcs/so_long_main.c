/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/26 21:50:15 by ojing-ha         ###   ########.fr       */
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
	t_sl_img	coin;
	t_sl_img	pillar;
	t_sl_img	player;
	t_sl_img	door;
	t_sl_img	final_img;
}t_data;

int event(int keycode, t_data *data)
{
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
	int		x = -1;
	int		y = -1;
	static int	temp;
	char	*path_1 = "sprites/Coin_1.xpm";
	char	*path_2 = "sprites/Coin_2.xpm";
	char	*path_3 = "sprites/Coin_3.xpm";
	char	*path_4 = "sprites/Coin_4.xpm";

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
			sl_copy_image(&data->pillar, &data->final_img, x, y);
	}
	sl_copy_image(&data->coin, &data->final_img, 6, 6);
	sl_copy_image(&data->door, &data->final_img, 6, 7);
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
	if (data->coin.img == NULL)
		printf("nope\n");
	data->door.img = mlx_xpm_file_to_image(data->mlx, door_path, &data->door.width, &data->door.height);
	data->pillar.img = mlx_xpm_file_to_image(data->mlx, floor_path, &data->pillar.width, &data->pillar.height);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_sl_map		map;

	error_check(argc, argv, &map);
	grid_gen(argv, &map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "so_long");
	get_sprites(&data);
	data.x = 0;
	data.y = 0;
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_key_hook(data.mlx_win, event, &data);
	mlx_loop(data.mlx);
}

/*	mlx_init() : To create a mlx pointer. 	*/
/*	mlx_new_window() : To create a window.	*/
/*	mlx_hook() : To loop.					*/
