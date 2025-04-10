# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:12:49 by ngordobi          #+#    #+#              #
#    Updated: 2024/04/10 14:19:24 by ngordobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3d

CC					=	gcc
CC_FLAGS			=	-Wall -Wextra -Werror

LIBFT				=	libft.a

SRC_PATH			=	./src/
LIBFT_PATH			=	./libft/

SOURCES				=	$(SRC_PATH)cub3d.c \
						
OBJECTS				= 	$(SOURCES:%.c=%.o)

INCLUDES			=	./includes/cub3d.h \
						./includes/libft.h \

#COLORS
BLUE				=	\033[1;34m
BOLD_BLUE			=	\033[0;34m
WHITE				=	\033[0m

define CUB3D
$(BOLD_BLUE)

                     ▓▓▓▓▓      ▓▓▓▓▓▓▓▓      ▓▓▓▓▓
                    ░░▓▓▓      ▓▓▓░░░░▓▓▓    ░░▓▓▓ 
  ▓▓▓▓▓▓  ▓▓▓▓▓ ▓▓▓▓ ░▓▓▓▓▓▓▓ ░░░    ░▓▓▓  ▓▓▓▓▓▓▓ 
 ▓▓▓░░▓▓▓░░▓▓▓ ░▓▓▓  ░▓▓▓░░▓▓▓   ▓▓▓▓▓▓░  ▓▓▓░░▓▓▓ 
░▓▓▓ ░░░  ░▓▓▓ ░▓▓▓  ░▓▓▓ ░▓▓▓  ░░░░░░▓▓▓░▓▓▓ ░▓▓▓ 
░▓▓▓  ▓▓▓ ░▓▓▓ ░▓▓▓  ░▓▓▓ ░▓▓▓ ▓▓▓   ░▓▓▓░▓▓▓ ░▓▓▓ 
░░▓▓▓▓▓▓  ░░▓▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓▓ ░░▓▓▓▓▓▓▓▓ ░░▓▓▓▓▓▓▓▓
 ░░░░░░    ░░░░░░░░ ░░░░░░░░   ░░░░░░░░   ░░░░░░░░ 

$(WHITE)
$(END)
endef
export CUB3D

.SILENT:

all:				$(NAME) $(LIBFT)

$(NAME):			$(OBJECTS) $(LIBFT) $(INCLUDES)
					$(CC) $(CC_FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
					mkdir -p $(SRC_PATH).objects/
					mv $(OBJECTS) $(SRC_PATH).objects/
					echo "\n··············· Compilation complete ················"
					echo "$$CUB3D"

$(LIBFT):
					@make --no-print-directory -C $(LIBFT_PATH)

clean:
					rm -rf $(SRC_PATH).objects/
					rm -rf $(SRC_PATH)*.o
					@make clean --no-print-directory -C $(LIBFT_PATH)
					echo "$(WHITE) · $(BLUE)Cub3d objects removed.$(WHITE)\n"
					
fclean:				clean
					rm -rf $(NAME)
					rm -rf $(LIBFT)
					rm -rf .temp_file_*
					@make fclean --no-print-directory -C $(LIBFT_PATH)
					echo "$(WHITE) · $(BLUE)Cub3d executable removed.$(WHITE)\n"

re:					fclean all
.PHONY:				all clean fclean re
