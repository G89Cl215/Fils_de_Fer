# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flviret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 13:58:52 by flviret           #+#    #+#              #
#    Updated: 2019/04/03 13:13:35 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

PTF_PATH	=	printf

HDR			=	$(PTF_PATH)

LIB_PATH	=	libft

LIB			=	$(addprefix $(LIB_PATH)/,libft.a)

DIR_O		=	obj

SOURCES    =  	conv_numeric.c \
				conv_ptr.c \
				conv_str.c \
				format_char.c \
				format_comma.c \
				format_flags.c \
				format_numeric.c \
				format_precision.c \
				format_regular_op.c \
				ft_printf.c \
				memory.c \
				parse_flag.c \
				parse_format.c \
				select_conversion.c \

SRCS		=    $(addprefix $(PTF_PATH)/,$(SOURCES))

OBJS		=    $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CC			=    gcc

CFLAGS		=    -Wall -Werror -Wextra

RM			=    rm -f

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIB) Makefile
	@cp $(LIB) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a has been successfully created."

$(LIB)			:
	@echo "Compiling Libft"
	@make -C $(LIB_PATH)

$(DIR_O)/%.o	:	$(PTF_PATH)/%.c | $(DIR_O)
	@$(CC) $(CFLAGS) -I $(PTF_PATH) -o $@ -c $<
	@echo " \t \t \t \t \t \t \t \t [OK] \r $^ \r"

$(DIR_O)		:
	@/bin/mkdir -p $(DIR_O)

clean			:
	@$(RM) $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."


fclean			:	clean
	@$(RM) $(NAME) $(LIB)
	@make fclean -C $(LIB_PATH)
	@echo "libftprintf.a and libft.a has been deleted."

re				:	fclean all

.PHONY			:	all clean fclean re
