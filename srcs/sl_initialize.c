/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:22:32 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/08 23:13:12 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*	map->counter : 	To keep track of which line 			*/
/*					I am checking when doing map checks		*/
void	map_init(t_sl_map *map)
{
	map->map_w = 0;
	map->map_h = 0;
	map->line_len = 0;
	map->space = 0;
	map->wall = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->enemy = 0;
	map->counter = 1;
}
