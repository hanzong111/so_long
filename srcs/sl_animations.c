/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:18:45 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/18 18:34:58 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	choose_player(int temp, t_data *data)
{
	if (temp <= (PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_1;
	else if (temp <= (2 * PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_2;
	else if (temp <= (PLAYER_ANIM / 3))
		data->player.ff = data->sprites.player_3;
	else if (temp <= (4 * PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_4;
	else if (temp <= (5 * PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_5;
	else if (temp <= (2 * PLAYER_ANIM / 3))
		data->player.ff = data->sprites.player_6;
	else if (temp <= (7 * PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_7;
	else if (temp <= (8 * PLAYER_ANIM / 9))
		data->player.ff = data->sprites.player_8;
	else if (temp <= PLAYER_ANIM)
		data->player.ff = data->sprites.player_9;
}

void	choose_coin(int temp, t_data *data)
{
	if (temp <= (COIN_ANIM / 4))
		data->coin_ff = data->sprites.coin_1;
	else if (temp <= (COIN_ANIM / 2))
		data->coin_ff = data->sprites.coin_2;
	else if (temp <= (3 * COIN_ANIM / 4))
		data->coin_ff = data->sprites.coin_3;
	else if (temp <= COIN_ANIM)
		data->coin_ff = data->sprites.coin_4;
}

void	choose_enemy(int temp, t_data *data)
{
	if (temp <= (ENEMY_ANIM / 4))
		data->enemy_ff = data->sprites.enemy_1;
	else if (temp <= (ENEMY_ANIM / 2))
		data->enemy_ff = data->sprites.enemy_2;
	else if (temp <= (3 * ENEMY_ANIM / 4))
		data->enemy_ff = data->sprites.enemy_3;
	else if (temp <= ENEMY_ANIM)
		data->enemy_ff = data->sprites.enemy_4;
}

void	choose_door(t_data *data)
{
	if (data->counters.exit_status == EXIT_CLOSED)
		data->door_ff = data->sprites.door_c;
	else
		data->door_ff = data->sprites.door_o;
}

void	choose_frame(int tick, t_data *data)
{
	int	p_temp;
	int	c_temp;

	p_temp = tick % PLAYER_ANIM;
	c_temp = tick % COIN_ANIM;
	choose_player(p_temp, data);
	choose_coin(c_temp, data);
	choose_door(data);
	choose_enemy(p_temp, data);
}
