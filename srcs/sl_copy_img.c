/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_copy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:28:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/22 21:30:20 by ojing-ha         ###   ########.fr       */
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

void	sl_copy_image(t_sl_img *src, t_sl_img *des, int x, int y)
{
	t_sl_data_addr	s;
	t_sl_data_addr	d;
	int				s_height;
	int				s_width;

	x *= SPRITE_SIZE;
	y *= SPRITE_SIZE;
	s.address = mlx_get_data_addr(src->img, &s.pixel_bits,
			&s.size_line, &s.endian);
	d.address = mlx_get_data_addr(des->img, &d.pixel_bits,
			&d.size_line, &d.endian);
	s_height = -1;
	while (++s_height < src->height && (s_height + y) < des->height)
	{
		s_width = -1;
		while (++s_width < src->width && (s_width + x) < des->height)
		{
			s.pixel = (s_height * s.size_line) + (s_width * 4);
			d.pixel = ((s_height + y) * d.size_line) + ((s_width + x) * 4);
			if (!check_black_pixel(s.address, s.pixel))
				sl_copy_pixel(&s, &d);
		}
	}
}
