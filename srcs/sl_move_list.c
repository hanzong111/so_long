/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:15:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/13 02:07:40 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move(int keycode, t_data *data, int x, int y)
{
	if (keycode == 'w') /* W  || 13*/
	{	
		if (data->map.grid[y - 1][x] == '1')
			return (0);
	}
	else if (keycode == 's') /* S  || 1*/
	{
		if (data->map.grid[y + 1][x] == '1')
			return (0);
	}
	else if (keycode == 'a') /* A  || 0*/
	{
		if (data->map.grid[y][x - 1] == '1')
			return (0);
	}
	else if (keycode == 'd') /* D  || 2*/
	{
		if (data->map.grid[y][x + 1] == '1')
			return (0);
	}
	return (1);
}

void	check_coins_exit(t_data *data, int x, int y)
{
	if (data->map.grid[y][x] == 'C')
	{
		data->map.grid[y][x] = '0';
		data->counters.picked_coins++;
	}
	if (data->map.coins == data->counters.picked_coins)
	{
		data->counters.exit_status = EXIT_OPENED;
		data->door_ff = data->sprites.door_o;
	}
	if (data->map.grid[y][x] == 'E')
	{
		if (data->counters.exit_status == EXIT_OPENED)
		{
			ft_printf("Congratz ! U have won nothing :)\n");
			exit (0);
		}
		else
			ft_printf("Pls collect all the coins before exiting :(\n");
	}
}

void	check_move_list(t_data *data)
{
	static int	counter;
	t_sl_list	*temp;

	if (data->player.move_list != NULL)
	{
		if (data->player.move_list->content == MOVE_UP)
			data->player.y -= SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_DOWN)
			data->player.y += SPRITE_H / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_LEFT)
			data->player.x -= SPRITE_W / PLAYER_MOVE;
		else if (data->player.move_list->content == MOVE_RIGHT)
			data->player.x += SPRITE_W / PLAYER_MOVE;
		counter++;
	}
	if (counter % PLAYER_MOVE == 0 && data->player.move_list != NULL)
	{
		temp = data->player.move_list;
		check_coins_exit(data, data->player.x / SPRITE_W,
			data->player.y / SPRITE_H);
		data->player.move_list = data->player.move_list->next;
		free(temp);
		data->counters.player_moves++;
	}
}
