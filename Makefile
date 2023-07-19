# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 20:16:34 by mhabib-a          #+#    #+#              #
#    Updated: 2023/04/13 01:21:14 by mhabib-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_calloc.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strdup.c ft_strnstr.c ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c ft_split.c ft_strlcpy.c ft_memmove.c ft_strlcat.c 
#BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c
LIBC = ar rcs
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJBONUS = $(BONUS:.c=.o)
RM = rm -f
NAME = libft.a
LIB_FT = libft.h

all : $(NAME)

$(NAME) : $(OBJ) $(OBJBONUS)
	$(LIBC) $(NAME) $(OBJ)

BONUS : $(OBJBONUS) $(OBJ)
	$(LCC) $(NAME) $(OBJ) $(OBJBONUS)

%.o : %.c $(LIB_FT)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJ) $(OBJBONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all