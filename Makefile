# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/05/31 11:53:16 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- LIBRARY NAME ---#
NAME = so_long
LDIR = inc/libft/
LIBFT = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -f
AR = ar rcs
MK = mkdir -p

#--- MLX42 CODAM ---#
MLX = MLX42/build/libmlx42.a
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

#--- COLORS ---#
GREEN	=	\033[1;32m
RED		=	\033[1;31m
RESET 	= 	\033[0m

#--- INCLUDE ---#
INCDIR = inc

#--- SOURCE ---#
SRCDIR	=	src
SRC		= 	main.c
VPATH	=	${SRCDIR}

#--- OBJECT ---#
OBJDIR  =   obj
OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})

#--- RULES ---#
${OBJDIR}/%.o:	%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
all:	$(NAME)
	
${NAME}:	$(OBJDIR) $(OBJ)
	@${CC} ${CFLAGS} -I${INCDIR} -o ${NAME} ${OBJ}
	@echo "$(NAME)${GREEN} sucessefully compiled 📁.${RESET}"

$(OBJDIR):
	@$(MK) ${OBJDIR}

libft:
	@$(MAKE) -C $(LDIR)
	
# update:
# 	@git submodule update --remote --recursive

# init:
# 	@git submodule update --init --recursive

run:	all
	@./${NAMES}
	
clean:
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	
fclean:	clean	
	@$(RM) $(NAME)
	@echo "$(NAME)${GREEN} object files and executable successfully removed 🗑.${RESET}"

re:	fclean all

.PHONY:	all clean fclean re libft