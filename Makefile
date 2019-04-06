# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flviret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 14:20:14 by flviret           #+#    #+#              #
#    Updated: 2019/04/06 13:48:56 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=    fdf

LIBFT_PATH		=    libft

SOURCES			=   main.c    \
					create_window.c \
					loopandevent.c \
					manage_array.c \
					manage_array2.c \
					open_error.c \
					set_view.c \
					set_viewtools.c \
					update_image.c \
					window_manipulation.c

SRC_DIR			=	sources

SRCS			=    $(addprefix $(SRC_DIR)/,$(SOURCES))

DIR_O			=	objects

OBJS			=    $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS			=	fdf.h \
					window_manipulation.h \
					set_view.h \

HDR_DIR			=	includes

HDR				=	 $(addprefix $(HDR_DIR)/,$(HEADERS))

HDR_FLAG		=	-I $(LIBFT_PATH)/$(LIBFT_PATH) \
					-I $(LIBFT_PATH)/printf \
					-I $(HDR_DIR)

CC				=    gcc
CFLAGS			=    -Wall -Werror -Wextra

LIB				=    $(LIBFT_PATH)/libftprintf.a

FRAMEWORKS		=  -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit

RM				=    rm -f


all				:    $(NAME)

$(LIB)			:
	@make -C $(LIBFT_PATH)

$(NAME)			:   $(LIB) Makefile $(OBJS) $(HDR)
	@$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(SRCS) $(HDR_FLAG) $(FRAMEWORKS)
	@echo "fdf has been successfully created."

$(DIR_O)/%.o	:	$(SRC_DIR)/%.c $(HDR) | $(DIR_O)
	@$(CC) $(CFLAGS) $(HDR_FLAG) -c $< -o $@
	@echo " \t \t \t \t \t \t \t \t [OK] \r $< \r"

$(DIR_O)		:
	@/bin/mkdir -p $(DIR_O)

clean			:
	@rm -Rf $(DIR_O)
	@make clean -C $(LIBFT_PATH)
	@echo "All .o files have been deleted."

fclean			:    clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) $(LIB)
	@echo "fclean done."

re				:    fclean all

.PHONY:    all clean fclean re
