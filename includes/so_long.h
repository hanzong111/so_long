/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:54:10 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/22 18:14:10 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"

# define SCREEN_W 1000
# define SCREEN_H 1000
# define SPRITE_SIZE 64

typedef struct s_sl_data_addr
{
	char	*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		pixel;
}	t_sl_data_addr;

typedef struct s_sl_img
{
	void	*img;
	int		width;
	int		height;
}	t_sl_img;

void	sl_copy_image(t_sl_img *src, t_sl_img *des, int x, int y);

#endif