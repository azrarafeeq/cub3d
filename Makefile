# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 02:20:26 by arafeeq           #+#    #+#              #
#    Updated: 2023/05/05 04:38:16 by arafeeq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ifndef VERPOSE
# .SILENT:
# endif

# R	= "\033[1;31m"
# G	= "\033[1;32m"
# Y	= "\033[1;33m"
# B	= "\033[1;34m"
# C	= "\033[0;36m"
# P	= "\033[0;35m"
# RS	= "\033[0m"


NAME = cub3d

SRCS = utils base check colors cub3d draw error ft_init \
		get_texture keys parsing raycast

GNLSRCS = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

OBJDIR = objects

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

CC = cc

MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	make all -C minilibx
	make all -C libft
	$(CC) $(CFLAGS) $(OBJS) $(GNLSRCS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	make clean -C minilibx
	make clean -C libft
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all