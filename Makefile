# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 14:34:48 by ymehlil           #+#    #+#              #
#    Updated: 2022/12/30 18:53:24 by ymehlil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	=	push_swap.c push_swap_parsing.c utils.c sa_sb.c pa_pb.c ra_rb.c rra_rrb.c \
			sort.c cost.c push.c
SRCSD 	= srcs/

OBJSD 	= objs/

LIBFT_PATH	= libft/
LIBFT_SRCS	= ft_atoi.c ft_putstr_fd.c ft_isdigit.c
LIBFT_OBJS = $(addprefix $(OBJSD), $(LIBFT_SRCS:.c=.o))
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

CC = gcc -c -o
LINKER = gcc -o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME):	$(OBJS) $(LIBFT_OBJS)
	$(LINKER) $@ $(OBJS) $(LIBFT_OBJS)
	@echo -ne '\033[32m                            (0%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#######################   (100%)\r'
	@echo -ne '\n'
	@echo "\033[33mCompilation finished"

$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $< $(FLAGS) 

$(OBJSD)%.o: $(LIBFT_PATH)%.c
	$(CC) $@ $< $(FLAGS)

clean:
	rm -rf $(OBJSD) $(OBJSBONUS)
	@echo -ne '\033[36m#######################   (100%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '                            (0%)\r'
	@echo -ne '\n'
	@echo "\033[33mClean finished"

fclean:	clean
	rm -rf $(NAME)
	@echo -ne '\033[34m#######################   (100%)\r'
	@sleep 0.2
	@echo -ne '#############              (66%)\r'
	@sleep 0.2
	@echo -ne '#####                      (33%)\r'
	@sleep 0.2
	@echo -ne '                            (0%)\r'
	@echo -ne '\n'
	@echo "\033[33mFclean finished"
re: fclean all 

.PHONY: all clean fclean re
