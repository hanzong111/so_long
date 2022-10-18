/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:14:59 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/18 18:33:03 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemies(t_data *data, int i)
{
	data->enemy_state = MOVING;
	if (data->player.move_list)
	{
		if (data->player.move_list->content == MOVE_UP)
				data->enemy_list[i]->y -= SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_DOWN)
			data->enemy_list[i]->y += SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_LEFT)
			data->enemy_list[i]->x -= SPRITE_W / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_RIGHT)
			data->enemy_list[i]->x += SPRITE_W / PLAYER_MOVE;
	}
}

void	enemies(t_data *data)
{
	int			i;
	int			counter;

	i = 0;
	while (data->enemy_list[i] != NULL)
	{
		if (!(check_wall(data, data->enemy_list[i]->x / SPRITE_W,
					data->enemy_list[i]->y / SPRITE_H) && check_place(
					data->enemy_list[i]->x, data->enemy_list[i]->y)))
		{
			counter = 0;
			if (check_wall(data, data->player.x / SPRITE_W,
					data->player.y / SPRITE_H) && check_place(data->player.x,
					data->player.y))
			{
				while (++counter <= PLAYER_MOVE)
					move_enemies(data, i);
				check_coins_exit(data, data->player.x / SPRITE_W,
					data->player.y / SPRITE_H);
				check_players_hit_enemies(data);
			}
			else
				move_enemies(data, i);
		}
		i++;
	}
}

void	add_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (data->enemy_list[i] != NULL)
	{
		sl_copy_image(&data->enemy_ff, &data->final_img,
			data->start_x + (data->enemy_list[i]->x),
			data->start_y + (data->enemy_list[i]->y));
		i++;
	}
}
