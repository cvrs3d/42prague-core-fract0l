# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yustinov <yustinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 14:51:02 by yustinov          #+#    #+#              #
#    Updated: 2024/10/21 14:10:22 by yustinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Program name
NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./minilibx-linux/

# Sources
SRC_PATH	=	src/
SRC			=	main.c  \
				init.c  \
				events.c  \
				render.c  \
				color.c  \
				string_utils.c  \
				math_utils.c  \
				singleprocessing.c  \
				julia.c  \
				mandelbrot.c  \

SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Bonus (Multiprocessing)
BONUS_SRC =	main.c  \
				init.c  \
				events.c  \
				multiprocessing.c  \
				proc_utils.c  \
				color.c  \
				string_utils.c  \
				render.c  \
				math_utils.c  \
				julia.c  \
				mandelbrot.c  \

BSRCS = $(addprefix $(SRC_PATH), $(BONUS_SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Objects bonus
BOBJ_PATH	= obj/
BOBJ			= $(BONUS_SRC:.c=.o)
BOBJS		= $(addprefix $(BOBJ_PATH), $(BOBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

#Bonus object making
$(BOBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(BOBJS): $(BOBJ_PATH)

$(BOBJ_PATH):
	@mkdir $(BOBJ_PATH)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make -C $(MLX_PATH) clean

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)

re: fclean all

multi: $(BOBJS) $(MLX)
	@echo "Compiling multiprocesed fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(MLX) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

.PHONY: all re clean fclean multi
