NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
#dirs
SRC_DIR=./src
#libft
LIBFT_DIR= ./libft
LIBFT= $(LIBFT_DIR)/libft.a
#mlx
#MLX_DIR =./minilibx-linux
#MLX_LIB = $(MLX_DIR)/libmlx.a
#INC= -I $(SRC_DIR)/includes/ -I $(GNL_DIR)/ -I $(LIBFT_DIR)/ -I $(MLX_DIR)/ -I ./bonus/includes/
#gnl
GNL_DIR= ./get_next_line
#includes
INC= -I $(SRC_DIR)/includes/ -I $(GNL_DIR)/ -I $(LIBFT_DIR)/ -I ./bonus/includes/
#linker to link the libs
LINK=  -L $(LIBFT_DIR) -lft -lmlx -lXext -lX11 -lm

SRCS= src/init/init.c \
		src/make_map/make_map.c \
		src/make_map/vaild_map.c \
		src/make_map/valid2d_map.c \
		src/make_map/flood_fill.c \
		src/make_map/ft_is_in_set.c \
		src/make_input/give_input.c \
		src/make_input/move_player.c \
		src/make_textures/load_textures.c \
		src/make_render/render_game.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c \
		src/main.c

OBJS=$(SRCS:.c=.o)

#bonus
SRCSB= bonus/init/init_bonus.c \
		bonus/make_map/make_map_bonus.c \
		bonus/make_map/vaild_map_bonus.c \
		bonus/make_map/valid2d_map_bonus.c \
		bonus/make_map/flood_fill_bonus.c \
		bonus/make_map/ft_is_in_set_bonus.c \
		bonus/make_input/give_input_bonus.c \
		bonus/make_input/move_player_bonus.c \
		bonus/make_textures/load_textures_bonus.c \
		bonus/make_render/render_game_bonus.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c \
		bonus/main_bonus.c \
		bonus/animate/animate_p_c_bonus.c

OBJSB = $(SRCSB:.c=.o)
#rules
all: $(NAME)
$(NAME):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LINK) -o $(NAME)
bonus: $(LIBFT) $(OBJSB)
	$(CC) $(CFLAGS) $(INC) $(OBJSB) $(LINK) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
$(MLX_LIB):
	@make -C $(MLX_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@rm -f $(OBJSB)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
