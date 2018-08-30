# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khsadira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 12:54:28 by khsadira          #+#    #+#              #
#    Updated: 2018/08/30 17:18:17 by khsadira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

CC		=	gcc

CFLAGS	=	#-Wall -Wextra -Werror

SRC		=	ft_put_off_t.c ft_lst_print_l.c ft_free_lst.c ft_lst_sort_t.c ft_check_ln.c ft_stat1.c ft_blocks.c ft_nblen.c ft_format.c ft_make_dir.c controler.c ft_error.c ft_good_timer.c ft_ls.c ft_ls_l.c ft_ls_r.c ft_lst_make.c ft_lst_print.c ft_lst_sort.c ft_make_flag.c

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
