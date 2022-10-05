/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:28:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/05 22:13:18 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_black_pixel(char *source, int pixel)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (source[pixel + i] != 0x00)
			return (0);
	}
	return (1);
}

void	sl_copy_pixel(t_sl_data_addr *s, t_sl_data_addr *d)
{
	d->address[d->pixel + 0] = s->address[s->pixel + 0];
	d->address[d->pixel + 1] = s->address[s->pixel + 1];
	d->address[d->pixel + 2] = s->address[s->pixel + 2];
	d->address[d->pixel + 3] = s->address[s->pixel + 3];
}

int	get_start_pixel(int a)
{
	int	coordinate;

	coordinate = -1;
	while (a < 0)
	{
		coordinate++;
		a++;
	}
	return (coordinate);
}

void	sl_copy_image(t_sl_img *src, t_sl_img *des, int x, int y)
{
	t_sl_data_addr	s;
	t_sl_data_addr	d;
	int				s_height;
	int				s_width;

	if (x <= -1 * SPRITE_W || y <= -1 * SPRITE_H)
		return ;
	s.address = mlx_get_data_addr(src->img, &s.pixel_bits,
			&s.size_line, &s.endian);
	d.address = mlx_get_data_addr(des->img, &d.pixel_bits,
			&d.size_line, &d.endian);
	s_height = get_start_pixel(y);
	while (++s_height < src->height && (s_height + y) < des->height)
	{
		s_width = get_start_pixel(x);
		while (++s_width < src->width && (s_width + x) < des->height)
		{
			s.pixel = (s_height * s.size_line) + (s_width * 4);
			d.pixel = ((s_height + y) * d.size_line) + ((s_width + x) * 4);
			if (!check_black_pixel(s.address, s.pixel))
				sl_copy_pixel(&s, &d);
		}
	}
}
