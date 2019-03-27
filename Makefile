# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flviret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 14:20:14 by flviret           #+#    #+#              #
#    Updated: 2019/03/26 15:56:59 by flviret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    fdf

LIBFT_PATH    =    libft/
LMLX_PATH    =    minilibx_macos/

SRCS    =    main.c    \
			 create_window.c \
			 loopandevent.c \
			 manage_array.c \
			 open_error.c \
			 set_view.c \
			 update_image.c \
			 window_manipulation.c

OBJS    =    $(SRCS:.c=.o)

HDR        =    fdf.h

CC        =    gcc
CFLAGS    =    -Wall -Werror -Wextra

LIB        =    $(LIBFT_PATH)/libftprintf.a
LMLX    =    $(LMLX_PATH)/libmlx.a

FRAMEWORKS    =    -framework OpenGL -framework AppKit

RM        =    rm -f

CLEAN    =    clean

all        :    $(NAME)

$(LIB)    :
	@make -C $(LIBFT_PATH)

$(LMLX)        :
	@make -C $(LMLX_PATH)

$(NAME)    :    $(OBJS) $(HDR) $(LIB) $(LMLX) Makefile
	@$(CC) $(CFLAGS) $(LIB) $(LMLX) -o $(NAME) $(SRCS) -I $(HDR) $(FRAMEWORKS)
	@echo "fdf has been successfully created."

clean    :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(LMLX_PATH)
	@echo "All .o files have been deleted."

fclean    :    clean
	@$(RM) $(NAME) $(LIB)
	@echo "fclean done."

re        :    fclean all

.PHONY:    all clean fclean re
