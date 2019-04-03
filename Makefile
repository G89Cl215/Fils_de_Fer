# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flviret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 14:20:14 by flviret           #+#    #+#              #
#    Updated: 2019/04/03 14:21:29 by flviret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    fdf

LIBFT_PATH    =    libft/
LMLX_PATH    =    minilibx_macos/

SRCS    =    main.c    \
			 create_window.c \
			 loopandevent.c \
			 manage_array.c \
			 manage_array2.c \
			 open_error.c \
			 set_view.c \
			 set_viewtools.c \
			 update_image.c \
			 window_manipulation.c

OBJS    =    $(SRCS:.c=.o)

HDR        =    fdf.h

CC        =    gcc
CFLAGS    =    -Wall -Werror -Wextra

LIB        =    $(LIBFT_PATH)/libftprintf.a

FRAMEWORKS    =  -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit

RM        =    rm -f

CLEAN    =    clean

all        :    $(NAME)

$(LIB)    :
	@make -C $(LIBFT_PATH)


$(NAME)    :    $(OBJS) $(HDR) $(LIB) Makefile
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(SRCS) -I $(HDR) $(FRAMEWORKS)
	@echo "fdf has been successfully created."

clean    :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@echo "All .o files have been deleted."

fclean    :    clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) $(LIB)
	@echo "fclean done."

re        :    fclean all

.PHONY:    all clean fclean re
