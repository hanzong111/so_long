/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_generate_ui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:40:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/26 04:03:11 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_ui(t_data *data)
{
	char	*num;
	char	*init;
	int		position;

	position = 0;
	num = ft_itoa(data->counters.player_moves);
	init = num;
	while (*num != '\0')
	{
		sl_copy_image(&data->sprites.numbers[*num - '0'], &data->final_img, position, 10);
		position += 110;
		num++;
	}
	free(init);
}
