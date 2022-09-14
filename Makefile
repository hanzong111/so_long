# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 20:26:19 by ojing-ha          #+#    #+#              #
#    Updated: 2022/09/14 21:03:15 by ojing-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc

LIBFT_DIR	= libft/
MLX_DIR	= mlx/
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

INCLUDES	= -I includes

CFLAGS	= -Wall -Werror -Wextra $(HEADER) #-fsanitize=address -g3
LIBFTFLAGS	= -L$(LIBFT_DIR) -lft
MLXFLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

SRC_FILES	= so_long_main

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all		:
		mkdir -p $(OBJS_DIR)
		make -C ${LIBFT_DIR}
		make -C ${MLX_DIR}
		make $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $^ -o $@

$(NAME)	: ${OBJS}
		$(CC) $(CFLAGS) $(LIBFTFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

clean	:
		rm -rf $(OBJS_DIR)
		make clean -C ${MLX_DIR}
		make clean -C ${LIBFT_DIR}

fclean	:	clean
		rm -f $(NAME)
		make fclean -C ${MLX_DIR}
		make fclean -C ${LIBFT_DIR}

re		:fclean all

.PHONY	:all clean fclean re
