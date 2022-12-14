/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:43 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/26 17:56:41 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	check_wall(t_data *data, int x, int y)
{
	if (data->player.move_list == NULL)
		return (0);
	if (data->player.move_list->content == MOVE_UP)
	{	
		if (data->map.grid[y - 1][x] == '1')
			return (1);
	}
	else if (data->player.move_list->content == MOVE_DOWN)
	{
		if (data->map.grid[y + 1][x] == '1')
			return (1);
	}
	else if (data->player.move_list->content == MOVE_LEFT)
	{
		if (data->map.grid[y][x - 1] == '1')
			return (1);
	}
	else if (data->player.move_list->content == MOVE_RIGHT)
	{
		if (data->map.grid[y][x + 1] == '1')
			return (1);
	}
	return (0);
}

int	check_place(int x, int y)
{
	if (x % SPRITE_W == 0)
	{
		if (y % SPRITE_H == 0)
			return (1);
	}
	return (0);
}

void	check_players_hit_enemies(t_data *data)
{
	if (data->player.x == data->enemy.x)
	{
		if (data->player.y == data->enemy.y)
		{
			ft_printf("You Died :(\n");
			exit (0);
		}
	}
}
