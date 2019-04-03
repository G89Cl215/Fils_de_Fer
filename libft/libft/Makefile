# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flviret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 21:22:39 by flviret           #+#    #+#              #
#    Updated: 2019/04/03 13:16:23 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_intlen.c		\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_arrlen.c		\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_isblank.c	\
			ft_iscntrl.c	\
			ft_isgraph.c	\
			ft_isin.c		\
			ft_islower.c	\
			ft_isspace.c	\
			ft_isupper.c	\
			ft_isxdigit.c	\
			ft_str_is_alpha.c	\
			ft_str_is_lowercase.c	\
			ft_str_is_numeric.c	\
			ft_str_is_printable.c	\
			ft_str_is_uppercase.c	\
			ft_strcapitalize.c	\
			ft_strlowcase.c	\
			ft_strupcase.c	\
			ft_strcasecmp.c	\
			ft_strncasecmp.c	\
			ft_strcasestr.c	\
			ft_strndup.c	\
			ft_printtab.c	\
			ft_strrev.c	\
			ft_strlcpy.c	\
			get_next_line.c	\
			ft_putchar_err.c	\
			ft_putstr_err.c	\
			ft_putendl_err.c	\
			ft_swap.c	\
			ft_itoa_base.c	\
			ft_range.c	\
			putnbr_base.c	\
			ft_uitoa_base.c	\
			putunbr_base.c	\
			putlnbr_base.c	\
			putulnbr_base.c	\
			putllnbr_base.c	\
			putullnbr_base.c	\
			ft_atol_base.c	\
			ft_putdouble.c	\
			ft_ltoa_base.c	\
			ft_ultoa_base.c	\
			ft_lltoa_base.c	\
			ft_ulltoa_base.c	\
			ft_dtoa.c	\
			ft_ldtoa.c	\
			ft_abs.c	\
			ft_tabdel.c	\
			ft_strjoin_free.c	\
			ft_strpbrk.c	\
			ft_instr.c	\
			ft_strncpy_safe.c	\
			ft_pow_ten.c	\
			ft_dtoa_concat.c	\
			ft_memjoin.c	\
			ft_memjoin_free.c \
			ft_strsubfree.c \
			ft_strjoinfree.c \
			option.c

OBJFILE	= $(SRCS:.c=.o)
OBJDIR	= obj
OBJS	= $(addprefix $(OBJDIR)/,$(OBJFILE))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -c

LIB		=	libft.h

RM		=	rm -f

CLEAN	=	clean

.PHONY: all re clean fclean

all		:	$(NAME)	

$(NAME)	:	$(OBJS) $(LIB) Makefile
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "The libft.a file has been successfully created."

$(OBJDIR)/%.o : %.c | $(OBJDIR)
			@$(CC) $(CFLAGS) -o $@ -c $^
			@echo " \t \t \t \t \t \t \t \t [OK]  \r $^  \r "

$(OBJDIR) :
			@/bin/mkdir $(OBJDIR)

clean	:	
			@$(RM) $(OBJS)
			@$(RM) -R $(OBJDIR)
			@echo "All .o files have been deleted."

fclean	:	clean
			@$(RM) $(NAME)
			@echo "The libft.a file has been deleted."

re		:	fclean all
