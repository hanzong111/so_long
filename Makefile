# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 20:26:19 by ojing-ha          #+#    #+#              #
#    Updated: 2022/10/05 22:31:57 by ojing-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc

LIBFT_DIR	= libft/
#MLX_DIR	= mlx/
MLX_DIR	= minilibx-linux/
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

INCLUDES	= -I includes

CFLAGS	= -Wall -Werror -Wextra $(HEADER) -fsanitize=address -g3
LIBFTFLAGS	= -L$(LIBFT_DIR) -lft
MLXFLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

SRC_FILES	= so_long_main\
				sl_copy_img\
				sl_error_checks\
				sl_initialize\
				sl_format_checks\
				sl_grid_gen\
		

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all		:
		mkdir -p $(OBJS_DIR)
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		make $(NAME)

#$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
#				$(CC) $(CFLAGS) -c $^ -o $@
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


#$(NAME)	: ${OBJS}
#		$(CC) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) -L${MLX_DIR} -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean	:
		rm -rf $(OBJS_DIR)
		make clean -C ${LIBFT_DIR}

fclean	:	clean
		rm -f $(NAME)
		make fclean -C ${LIBFT_DIR}

re		:fclean all

.PHONY	:all clean fclean re
