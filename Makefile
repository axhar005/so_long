# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/08/02 14:16:58 by olivierbouc      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ➜  ~ git clone https://github.com/codam-coding-college/MLX42.git
# ➜  ~ cd MLX42
# ➜  ~ cmake -B build # build here refers to the outputfolder.
# ➜  ~ cmake --build build -j4 # or do make -C build -j4

#--- LIBRARY NAME ---#
NAME = so_long
LDIR = lib/libft_/
LIBFT = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -f
AR = ar rcs
MK = mkdir -p

#--- MLX42 CODAM ---#
MLXDIR = lib/MLX42_/build/
MLXA = libmlx42.a
MLX = $(MLXDIR)$(MLXA)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" #"/usr/local/opt/glfw/lib"

#--- COLORS ---#
GREEN	=	\033[1;32m
RED		=	\033[1;31m
RESET 	= 	\033[0m

#--- INCLUDE ---#
INCDIR = inc

#--- SOURCE ---#
SRCDIR	=	src
SRC		= 	main.c utils_0.c utils_1.c texture_0.c texture_1.c string_0.c string_1.c animation.c \
			image_0.c image_1.c player_utils.c movement.c auto_tiling_0.c auto_tiling_1.c \
			set_tile_0.c set_tile_1.c set_tile_2.c draw_0.c draw_1.c static_function.c move_and_colide.c \
			tile_handling.c key.c collision.c tile_convertion.c free.c read.c load.c \
			parsing_0.c parsing_1.c init_0.c init_1.c selector.c step_0.c step_1.c step_2.c
VPATH	=	$(SRCDIR)

#--- OBJECT ---#
OBJDIR  =   obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#--- RULES ---#
$(OBJDIR)/%.o:	%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -I. -c $< -o $@
	
all:	mlx42 libft $(NAME)
	
${NAME}:	$(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -I$(INCDIR) -o $(NAME) $(MLX) $(OBJ) $(LDIR)$(LIBFT)
	@echo "$(NAME)$(GREEN) sucessefully compiled 📁.$(RESET)"

$(OBJDIR):
	@$(MK) $(OBJDIR)

mlx42:
	@cmake lib/MLX42_/ -B lib/MLX42_/build
	@cmake --build lib/MLX42_/build -j4
	
libft:
	@$(MAKE) -C $(LDIR)

run:	all
	@./$(NAMES)
	
clean:
	@$(MAKE) -C $(LDIR) clean
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	@$(RM)r $(MLXDIR)
	
fclean:	clean	
	@$(MAKE) -C $(LDIR) fclean
	@$(RM) $(NAME)
	@echo "$(NAME)$(GREEN) object files and executable successfully removed 🗑.$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re libft