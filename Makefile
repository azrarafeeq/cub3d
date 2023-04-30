# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 02:20:26 by arafeeq           #+#    #+#              #
#    Updated: 2023/04/30 14:51:52 by arafeeq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main read_map free

GNLSRCS = ./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c

OBJDIR = objects

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

CC = cc

MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3

LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror

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