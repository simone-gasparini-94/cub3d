CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror 
INCS		=	-Iinc											\
				-Ilibft/inc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	main.c											\
				color.c											\
				data.c											\
				destroy.c										\
				graphic.c										\
				key_presses.c									\
				map.c											\
				map_check.c										\
				render.c										\
				str_utils.c										\
				parse.c											\
				print.c											\
				texture.c						
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBFT		=	-Llibft -lft
MLX			= 	-lmlx -lXext -lX11
MATH		= 	-lm
NAME		=	cub3D

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) $(MATH) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
