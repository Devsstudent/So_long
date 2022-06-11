FLAG = -Wall -Werror -Wextra -g -MMD -O3
NAME = so_long
HEADER_DIR = ./includes/
OBJ = $(addprefix obj/,  sl_parsing.o sl_check_map_utils.o sl_check_map.o sl_free_things.o sl_core.o sl_load_img.o sl_init_game.o sl_hitbox.o sl_movement.o sl_hook.o sl_coins.o sl_exit.o sl_mlx_utils.o sl_animate_coins.o sl_animate_enemy.o sl_enemy.o sl_display_counter.o sl_animate_whirl.o main.o)
D_FILE = $(addprefix obj/,sl_parsing.d sl_check_map_utils.d sl_check_map.d sl_free_things.d  sl_core.d sl_load_img.d sl_init_game.d sl_hitbox.d sl_movement.d sl_hook.d sl_coins.d sl_exit.d sl_mlx_utils.d sl_animate_coins.d sl_animate_enemy.d sl_enemy.d sl_display_counter.d sl_animate_whirl.d main.d)
LIB = -L $(addprefix lib/, libft) -lft -L $(addprefix lib/, mlx) -lmlx -lXext -lX11 -lm 
HEADER = -I $(addprefix lib/, mlx) -I $(addprefix lib/, libft)

all : $(NAME)

$(NAME) : $(OBJ) MAKE
	$(CC) $(FLAG) $(OBJ) $(LIB) -o $@

obj/%.o: src/%.c $(HEADER_DIR)
	$(CC) $(FLAG) -o $@ -c $< -I includes/ $(HEADER)

MAKE:
	make bonus -s -C lib/libft
	make -s -C lib/mlx

clean :
	make -s clean -C lib/libft
	make -s clean -C lib/mlx
	rm -f $(OBJ)
	rm -f $(D_FILE)

fclean :	clean
	make -s fclean -C lib/libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

-include $(D_FILE)
