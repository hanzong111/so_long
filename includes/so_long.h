/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:54:10 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/27 07:21:32 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include "../minilibx_linux/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
// Dont Change This :(
# define SCREEN_W 960
# define SCREEN_H 960

//Linux
# define KEY_UP 'w'
# define KEY_DOWN 's'
# define KEY_LEFT 'a'
# define KEY_RIGHT 'd'
# define KEY_ESC 65307

//MAC
// # define KEY_UP 13
// # define KEY_DOWN 1
// # define KEY_LEFT 0
// # define KEY_RIGHT 2
// # define KEY_ESC 53

// In pixels
# define SPRITE_W 64
# define SPRITE_H 64

// Steps taken to walk thru a block
# define PLAYER_MOVE 4

// Ticks per cycle
# define PLAYER_ANIM 40
# define ENEMY_ANIM 64
# define COIN_ANIM 35

// Some Events
# define MOVE_UP 1
# define MOVE_DOWN 2
# define MOVE_LEFT 3
# define MOVE_RIGHT 4

# define EXIT_CLOSED 1
# define EXIT_OPENED 2

// Event definition
# define ON_DESTROY 17

typedef struct s_sl_data_addr
{
	char	*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		pixel;
}	t_sl_data_addr;

typedef struct s_sl_img
{
	void	*img;
	int		w;
	int		h;
}	t_sl_img;

typedef struct s_sl_map
{
	char	**grid;
	char	*line;

	int		map_w;
	int		map_h;
	int		counter;
	int		line_len;

	int		space;
	int		wall;
	int		coins;
	int		exit;
	int		player;
	int		enemy;
}	t_sl_map;

typedef struct s_sl_sprites
{
	t_sl_img		numbers[10];
	t_sl_img		move;

	t_sl_img		coin_1;
	t_sl_img		coin_2;
	t_sl_img		coin_3;
	t_sl_img		coin_4;
	t_sl_img		player_1;
	t_sl_img		player_2;
	t_sl_img		player_3;
	t_sl_img		player_4;
	t_sl_img		player_5;
	t_sl_img		player_6;
	t_sl_img		player_7;
	t_sl_img		player_8;
	t_sl_img		player_9;

	t_sl_img		enemy_1;
	t_sl_img		enemy_2;
	t_sl_img		enemy_3;
	t_sl_img		enemy_4;

	t_sl_img		door_o;
	t_sl_img		door_c;
	t_sl_img		floor;
	t_sl_img		wall;
	t_sl_map		map;
}	t_sl_sprites;

typedef struct s_sl_list
{
	int					content;
	struct s_sl_list	*next;
}	t_sl_list;

typedef struct s_sl_enemy
{
	int				x;
	int				y;
}	t_sl_enemy;

typedef struct s_sl_player
{
	t_sl_img		ff;
	int				x;
	int				y;
	int				state;
	t_sl_list		*move_list;
}	t_sl_player;

typedef struct s_sl_counters
{
	int	player_moves;
	int	picked_coins;
	int	exit_status;
	int	loop_count;
}	t_sl_counters;

typedef struct s_sl_path_check
{
	int	coins;
	int	exit;
}	t_sl_path_check;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	int				start_x;
	int				start_y;
	int				enemy_state;

	t_sl_sprites	sprites;
	t_sl_img		final_img;
	t_sl_map		map;
	t_sl_map		flood_map;

	t_sl_player		player;
	t_sl_enemy		enemy;

	t_sl_img		enemy_ff;
	t_sl_img		coin_ff;
	t_sl_img		door_ff;
	t_sl_counters	counters;
	t_sl_path_check	path;
}	t_data;

void		sl_copy_image(t_sl_img *src, t_sl_img *des, int x, int y);

void		error_check(int argc, char **argv, t_sl_map *map);
void		format_check(char **argv, t_sl_map *map);
void		grid_gen(char **argv, t_sl_map *map, t_data *data);

void		var_init(t_data *data);

void		render_map(t_data *data);
void		print_floor(t_data *data, int x, int y);
void		print_wall(t_data *data, int x, int y);
void		print_coin(t_data *data, int x, int y);
void		print_exit(t_data *data, int x, int y);
void		get_sprites(t_data *data);

void		choose_frame(int tick, t_data *data);

void		sl_lstadd_back(t_sl_list **lst, t_sl_list *new);
t_sl_list	*sl_lstnew(int content);

void		check_move_list(t_data *data);
int			check_move(t_data *data, int x, int y);

void		path_check(char **argv, t_data *data);

void		move_enemies(t_data *data);
void		enemies(t_data *data);
void		add_enemy(t_data *data);

int			check_place(int x, int y);
int			check_wall(t_data *data, int x, int y);

void		check_coins_exit(t_data *data, int x, int y);
void		check_players_hit_enemies(t_data *data);

void		generate_ui(t_data *data);

int			player_not_moving(t_data *data);

#endif