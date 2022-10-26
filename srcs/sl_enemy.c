/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:14:59 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/26 18:23:46 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemies(t_data *data)
{
	data->enemy_state = MOVING;
	if (data->player.move_list)
	{
		if (data->player.move_list->content == MOVE_UP)
			data->enemy.y -= SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_DOWN)
			data->enemy.y += SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_LEFT)
			data->enemy.x -= SPRITE_W / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_RIGHT)
			data->enemy.x += SPRITE_W / PLAYER_MOVE;
	}
}

void	add_enemy(t_data *data)
{
	sl_copy_image(&data->enemy_ff, &data->final_img,
		data->start_x + (data->enemy.x),
		data->start_y + (data->enemy.y));
}

void	enemies(t_data *data)
{
	int	counter;

	if (!(check_wall(data, data->enemy.x / SPRITE_W,
				data->enemy.y / SPRITE_H) && check_place(
				data->enemy.x, data->enemy.y)))
	{
		if (check_wall(data, data->player.x / SPRITE_W,
				data->player.y / SPRITE_H) && check_place(data->player.x,
				data->player.y))
		{
			counter = 0;
			while (++counter <= PLAYER_MOVE)
				move_enemies(data);
			check_coins_exit(data, data->player.x / SPRITE_W,
				data->player.y / SPRITE_H);
			check_players_hit_enemies(data);
		}
		else
			move_enemies(data);
	}
}
