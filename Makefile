# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/03/20 12:17:53 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
G_CFLAGS	=	-Wall -Werror -Wextra

MLX_CFLAG	=	-lmlx -lXext -lX11 -lmlx -framework OpenGL -framework AppKit

NAME		=	fdf

LIB_PATH	=	libft
LIB			=	libftprintf.a

LIBS 		=	 $(addprefix $(LIB_PATH)/,$(LIB)) 

DIR_O		=   obj

SRC_PATH	=	src
SOURCES 	=	main.c \

SRCS    	=   $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS    	=   $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

TEST		=	bresenham.c \


TEST_OBJS	=	$(TEST:.c=.o)

HDR			=	libft/option.h \
				libft/libft.h \
				list_lib/ls_list.h \
				fdf.h

HDR_FLAG	=	-I libft \
				-I includes

CLEAN		=   clean

all : $(NAME)

$(LIB_PATH)/$(LIB) :
	@echo "Comping $(LIB)"
	@make -C $(LIB_PATH)

$(NAME) : $(LIBS) $(TEST_OBJS) $(HDR) Makefile
	@$(CC) $(CFLAGS) $(MLX_CFLAG) $(TEST_OBJS) $(LIBS) -o $(NAME) $(HDR_FLAG)
	@echo "ft_ls has been successfully created."

$(DIR_O) :
	@mkdir -p $(DIR_O)

$(DIR_O)/%.o : $(SRC_PATH)/%.c | $(DIR_O)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HDR_FLAG)
	@echo " \t \t \t \t \t \t \t \t [OK]  \r $^  \r "

clean :
	@rm -f $(OBJS)
	@rm -Rf $(DIR_O)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean :   clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "ft_ls and libft.a have been deleted."

re  :   fclean all

.PHONY: all clean fclean re lib_msg
