# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalhmoud <aalhmoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:34:41 by aalhmoud          #+#    #+#              #
#    Updated: 2023/05/01 23:26:05 by aalhmoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERPOSE
.SILENT:
endif


R	= "\033[1;31m"
G	= "\033[1;32m"
Y	= "\033[1;33m"
B	= "\033[1;34m"
C	= "\033[0;36m"
P	= "\033[0;35m"
RS	= "\033[0m"


RCS	= ./src/cub3d.c\
./src/ft_bzero.c \
./src/parsing.c \
./src/parsing_utils.c \
./src/convertbase.c \
./src/number_parsing_utils.c \
./src/arr_utils.c \
./src/basic_utils.c \
./src/colors.c \
./src/error.c \


OBJS	= $(RCS:.c=.o)

NAME	= cub3d

CFLAGS	= -Wall -Werror -Wextra

mlx = ./mlx/libmlx.a

$(NAME)	:
		echo $(G)"cub3d is being compiled..." $(RS)
		-@make -C ./mlx 2>/dev/null || true
		@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
		@echo $(B)"         ║"$(C)"░░░░░███████░░██░░░░██░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░███████░░░███████░░██░░░░░░██░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░██░░░░░░░░██░░░░██░░██░░░░██░░░░░░░██░░██░░░░░██░░░░"$(B)"║"$(RS)
		@echo $(B)"         ║"$(C)"░░░░░███████░░████████░░████████░░███████░░███████░░░░░░"$(B)"║"$(RS)
		@echo $(B)"         ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "$(RS)
		@echo "\n"
		gcc $(CFLAGS) -o cub3d $(RCS) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		echo $(R)"object files deleted" $(RS)
		rm -f $(OBJS)
		-@make clean -C mlx 2>/dev/null || true

fclean : clean
		echo $(R)"executable file deleted" $(RS)
		rm -f $(NAME)
		-@make clean -C mlx 2>/dev/null || true

re : fclean all
