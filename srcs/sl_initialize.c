/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:22:32 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/14 22:08:25 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	map->counter : 	To keep track of which line 			*/
/*					I am checking when doing map checks		*/
void	var_init(t_data *data)
{
	data->map.map_w = 0;
	data->map.map_h = 0;
	data->map.line_len = 0;
	data->map.space = 0;
	data->map.wall = 0;
	data->map.coins = 0;
	data->map.exit = 0;
	data->map.player = 0;
	data->map.enemy = 0;
	data->map.counter = 1;
	data->counters.picked_coins = 0;
	data->counters.player_moves = 0;
	data->counters.exit_status = EXIT_CLOSED;
	data->player.move_list = NULL;
	data->counters.loop_count = 0;
	data->path.coins = 0;
	data->path.exit = 0;
}
