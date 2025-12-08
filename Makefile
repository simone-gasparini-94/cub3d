CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror 
INCS		=	-Iinc											\
				-Ilibft/inc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	main.c											\
				data/data.c										\
				data/destroy.c									\
				extras/print.c									\
				extras/str_utils.c								\
				parsing/color.c									\
				parsing/map_check.c								\
				parsing/map.c									\
				parsing/parse.c									\
				parsing/texture.c								\
				ray_casting/graphic.c							\
				ray_casting/key_presses.c						\
				ray_casting/render.c			
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBFT		=	-Llibft -lft
MLX			= 	-lmlx -lXext -lX11
NAME		=	cub3D

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
