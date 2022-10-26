/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:15:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/27 06:59:09 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_data *data)
{
	t_sl_list	*temp;

	if (data->player.move_list)
	{
		if (data->player.move_list->content == MOVE_UP)
				data->player.y -= SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_DOWN)
			data->player.y += SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_LEFT)
			data->player.x -= SPRITE_W / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_RIGHT)
			data->player.x += SPRITE_W / PLAYER_MOVE;
		data->counters.loop_count++;
	}
	if (data->counters.loop_count % PLAYER_MOVE == 0 && data->player.move_list)
	{
		temp = data->player.move_list;
		check_coins_exit(data, data->player.x / SPRITE_W,
			data->player.y / SPRITE_H);
		check_players_hit_enemies(data);
		data->player.move_list = data->player.move_list->next;
		free(temp);
		data->counters.player_moves++;
	}
}

int	player_not_moving(t_data *data)
{
	if (check_wall(data, data->player.x / SPRITE_W,
			data->player.y / SPRITE_H) && check_place(data->player.x,
			data->player.y))
		return (1);
	else
		return (0);
}

void	check_move_list(t_data *data)
{
	t_sl_list	*temp;

	enemies(data);
	if (player_not_moving(data))
	{
		temp = data->player.move_list;
		data->player.move_list = data->player.move_list->next;
		free(temp);
	}
	else
		move_player(data);
}
