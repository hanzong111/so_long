/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:53:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/14 22:24:33 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();c
	mlx_win = mlx_new_window(mlx, 1000, 1000, "so_long");
	mlx_loop(mlx);
}

/*	mlx_init() : To create a mlx pointer. 	*/
/*	mlx_new_window() : To create a window.	*/
/*	mlx_hook() : To loop.					*/
