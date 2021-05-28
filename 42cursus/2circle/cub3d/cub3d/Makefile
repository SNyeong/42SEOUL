# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 01:18:45 by seungnle          #+#    #+#              #
#    Updated: 2021/05/28 12:47:39 by seungnle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_PATH = scripts
SRC_NAMES = cube3d_utils.c map_file_parser_utils.c sprite.c destruct.c sprite_utils.c events.c \
			parse_floor_ceilling_resolution.c sprite_utils2.c init_data.c parse_map.c utils.c \
			intersection.c parse_textures.c utils2.c main.c ray_casting.c wall_utils.c \
			map_error_handling.c render.c walls.c map_file_parser.c screenshot.c \
			get_next_line.c get_next_line_utils.c utils3.c


LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g
OPT = -Ofast -O3
LD_LIBS = -lm -framework OpenGL -framework AppKit libs/libmlx.a

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAMES))

all: $(NAME)

$(NAME): $(SRC)
	@ make -C $(LIBFT_PATH)
	@ $(CC) $(CFLAGS) $(SRC) $(OPT) -o $(NAME) $(LD_LIBS) $(LIBFT)

run:
	@./cub3d "maps/map.cub"

save:
	@./cub3d "maps/map.cub" "--save"

norm:
	@ norminette scripts
	@ norminette include

clean:

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C $(LIBFT_PATH)

re: fclean all
