# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 19:18:41 by efinda            #+#    #+#              #
#    Updated: 2026/07/27 07:22:10 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS_PRINTF =	printf/ft_printf.o	\
				printf/ft_dprintf.o	\
				printf/aux.o		\
				printf/char.o		\
				printf/flags.o		\
				printf/init.o		\
				printf/integer.o	\
				printf/no_type.o	\
				printf/parse.o		\
				printf/print.o		\
				printf/read.o		\
				printf/string.o		\
				printf/type.o		\
				printf/utils.o		\

OBJS_CTYPE =	ctype/ft_isalnum.o	\
				ctype/ft_isalpha.o	\
				ctype/ft_isascii.o	\
				ctype/ft_isdigit.o	\
				ctype/ft_isprint.o	\
				ctype/ft_tolower.o	\
				ctype/ft_toupper.o	\
				ctype/ft_isupper.o	\
				ctype/ft_islower.o	\
				ctype/ft_isblank.o	\
				ctype/ft_isspace.o	\

OBJS_STDLIB =	stdlib/ft_atoi.o 	\
				stdlib/ft_calloc.o 	\

OBJS_STRING =	string/ft_bzero.o	\
				string/ft_memchr.o 	\
				string/ft_memcmp.o 	\
				string/ft_memcpy.o 	\
				string/ft_memmove.o \
				string/ft_memset.o 	\
				string/ft_strchr.o 	\
				string/ft_strdup.o 	\
				string/ft_strlcat.o \
				string/ft_strlcpy.o \
				string/ft_strlen.o 	\
				string/ft_strncmp.o \
				string/ft_strnstr.o \
				string/ft_strrchr.o \

OBJS_NSTD =	non_standard/ft_itoa.o			\
			non_standard/ft_substr.o		\
			non_standard/ft_putchar_fd.o	\
			non_standard/ft_putendl_fd.o	\
			non_standard/ft_putnbr_fd.o		\
			non_standard/ft_putstr_fd.o		\
			non_standard/ft_split.o 		\
			non_standard/ft_striteri.o		\
			non_standard/ft_strmapi.o		\
			non_standard/ft_strtrim.o		\

OBJS_LL =	linked_list/del.o				\
			linked_list/ft_lstadd_back.o 	\
			linked_list/ft_lstadd_front.o 	\
			linked_list/ft_lstclear.o 		\
			linked_list/ft_lstdelone.o 		\
			linked_list/ft_lstiter.o 		\
			linked_list/ft_lstlast.o 		\
			linked_list/ft_lstmap.o			\
			linked_list/ft_lstnew.o 		\
			linked_list/ft_lstsize.o 		\

OBJS_EXTRAS =	extras/ft_mtxfree.o			\
				extras/ft_mtxlen.o			\
				extras/ft_strcmp.o			\
				extras/ft_strfree.o			\
				extras/ft_strnfill.o		\
				extras/ft_strcpy.o			\
				extras/ft_mtxdup.o			\
				extras/ft_addstr_mtx.o		\
				extras/ft_strndup.o			\
				extras/ft_countstr_mtx.o	\
				extras/ft_strjoin.o			\
				extras/ft_lstmtx.o			\
				extras/ft_join.o			\
				extras/ft_nbrlen.o			\
				extras/ft_realloc.o			\
				extras/ft_strnbr.o			\
				extras/ft_strspn.o			\
				extras/ft_strspn_rev.o		\
				extras/ft_strcspn.o			\
				extras/ft_atoll.o			\
				extras/ft_getpid.o			\
				extras/ft_strchr_count.o	\
				extras/ft_swaptr.o			\
				extras/ft_word_count.o		\
				extras/ft_longestr_mtx.o	\
				extras/ft_flood_fill.o		\
				extras/ft_replace_char.o	\
				extras/ft_strpbrk.o			\
				extras/ft_strqbrk.o			\
				extras/ft_strint.o			\
				extras/ft_map.o				\
				extras/ft_origin_point.o	\
				extras/ft_negative_point.o	\
				extras/ft_str_case_cmp.o	\
				extras/ft_center_range.o	\
				extras/ft_gettimeofday.o	\

OBJS =	$(OBJS_PRINTF) $(OBJS_CTYPE) $(OBJS_STDLIB) $(OBJS_STRING) $(OBJS_NSTD) $(OBJS_LL) $(OBJS_EXTRAS) get_next_line/get_next_line.o

HEADERS	=	inc/libft.h					\
			inc/printf.h				\
			my_mlx/inc/my_mlx.h			\
			my_mlx/inc/my_mlx_structs.h	\

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -fPIC
ARC = ar rcs
RM = rm -f

MY_MLX_PATH = my_mlx
MY_MLX = $(MY_MLX_PATH)/my_mlx.a

all: $(NAME) $(MY_MLX)

$(OBJS): $(HEADERS)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

$(MY_MLX): $(NAME)
	@$(MAKE) -s -C $(MY_MLX_PATH)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(MY_MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(MY_MLX_PATH) fclean

re: fclean all
	@$(MAKE) -s -C $(MY_MLX_PATH) re

.PHONY: all clean fclean re
