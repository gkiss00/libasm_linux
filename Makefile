# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkiss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 18:15:43 by gkiss             #+#    #+#              #
#    Updated: 2020/02/01 11:36:40 by gkiss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_read.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_strdup.s \
				ft_strlen.s \
				ft_write.s \

OBJS    	=	$(SRCS:.s=.o)

FLAGS		=	-f elf64

NAME		=	libasm.a

all :			${NAME}

${NAME} :		${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

%.o:			%.s
				nasm ${FLAGS} $< -o $@

clean :			
				rm -rf ${OBJS}

fclean :		clean
				rm -rf ${NAME}

re :            fclean all

.PHONY:         all clean fclean re
