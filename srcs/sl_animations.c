/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:18:45 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/10 22:49:24 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	choose_player(int temp, t_data *data)
{
	if (temp <= (PLAYER_SPEED / 4))
		data->player.ff = data->sprites.player_1;
	else if (temp <= (PLAYER_SPEED / 2))
		data->player.ff = data->sprites.player_2;
	else if (temp <= (3 * PLAYER_SPEED / 4))
		data->player.ff = data->sprites.player_3;
	else if (temp <= PLAYER_SPEED)
		data->player.ff = data->sprites.player_4;
}

void	choose_coin(int temp, t_data *data)
{
	if (temp <= (COIN_SPEED / 4))
		data->coin_ff = data->sprites.coin_1;
	else if (temp <= (COIN_SPEED / 2))
		data->coin_ff = data->sprites.coin_2;
	else if (temp <= (3 * COIN_SPEED / 4))
		data->coin_ff = data->sprites.coin_3;
	else if (temp <= COIN_SPEED)
		data->coin_ff = data->sprites.coin_4;
}

void	choose_frame(int tick, t_data *data)
{
	int	p_temp;
	int	c_temp;

	p_temp = tick % PLAYER_SPEED;
	c_temp = tick % COIN_SPEED;
	choose_player(p_temp, data);
	choose_coin(c_temp, data);
}
