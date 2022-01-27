NAME = so_long

NAME_B = so_long_bonus

HEADER = so_long.h

LIB_NAME = so_long.a
# LIBFT_PATH =

SRSC = sl_validation_map.c sl_check_wall.c sl_read_and_split.c sl_utils.c sl_change_inmap.c sl_display_game.c sl.c

SRSC_B = sl_validation_map_b.c sl_check_wall_b.c sl_read_and_split_b.c sl_utils_b.c sl_change_inmap_b.c sl_display_game_b.c sl_b.c

OBJ = $(SRSC:%.c=%.o)

OBJ_B = $(SRSC_B:%.c=%.o)

CC = cc

FLAGS =  -Wall -Wextra -Werror -fsanitize=address

.PHONY: all bonus clean fclean re libre

all : libre $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(FLAGS) -lmlx -Llibft -lft -framework OpenGL -framework AppKit  -o $(NAME)

$(OBJ) : %.o : %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -Ilibft -c $< -o $@


bonus: libre $(NAME_B)
	
$(NAME_B): $(OBJ_B) $(HEADER)
	ar rc $(LIB_NAME) $(OBJ_B)
	$(CC) $(OBJ_B) $(FLAGS) -lmlx -Llibft -lft -framework OpenGL -framework AppKit  -o $(NAME_B)

$(OBJ_B) : %.o : %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -Ilibft -c $< -o $@

libre:
	@cd libft && make
	

clean: 
	rm -rf $(OBJ) $(OBJ_B) $(LIB_NAME)

fclean: clean
	rm -rf $(NAME) $(NAME_B)
	@cd libft && make fclean

re: fclean all
