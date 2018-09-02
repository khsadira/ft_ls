# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khsadira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 12:54:28 by khsadira          #+#    #+#              #
#    Updated: 2018/09/02 16:55:59 by khsadira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_aclattr.c ft_print_color.c ft_print_ln.c ft_print_flag.c ft_del_flag.c ft_lst_print2.c ft_freetab.c ft_put_off_t.c ft_lst_print_l.c ft_free_lst.c ft_lst_sort_t.c ft_stat.c ft_blocks.c ft_nblen.c ft_format.c ft_make_dir.c controler.c ft_error.c ft_ls.c ft_ls_l.c ft_ls_r.c ft_lst_make.c ft_lst_print.c ft_lst_sort.c ft_make_flag.c

OBJ		=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all

.PHONY : all clean fclean re
