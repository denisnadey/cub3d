.PHONY: all clean fclean re
ULTRALIBX = ultralibx/libftprintf.a
MLX = mlx/libmlx.a
NAME =	cub3D
SRCS =	main.c parser/parser_setting.c other/cub_mini_utilc.c other/drawing.c other/draw_3d.c \
		other/key_tapper.c parser/parser_struct.c parser/zero_struct.c parser/checkers.c other/sprite.c other/sprites_render.c\
		other/screenshot_tools.c parser/ft_parse_and_check_map.c  other/key_tapper2.c\
		parser/parser_tool_1.c parser/parser_tool_2.c parser/parser_tool_3.c\
		other/other_part_one.c other/mainpart2.c parser/checkers_line.c other/sprite_2.c other/mainpart3.c\
		fornorme/norm1.c fornorme/norm2.c fornorme/norm3.c fornorme/norm4.c fornorme/norm5.c \
		fornorme/norme6.c fornorme/norme7.c

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINILIBX =	-L./mlx -lmlx -framework OpenGL -framework Appkit
RM  =	rm -f

all: $(NAME)

$(NAME): $(ULTRALIBX) $(OBJS) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(ULTRALIBX) $(MLX) $(MINILIBX)

$(ULTRALIBX):
	make -C ultralibx

$(MLX):
	make -C mlx

$(OBJS): cub3d.h

clean:
	make clean -C ultralibx
	make clean -C mlx
	${RM} bitmap.bmp $(OBJS)
fclean:
	make clean -C ultralibx
	make clean -C mlx
	make fclean -C ultralibx
	${RM} cub3D

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

run: $(NAME)
	./cub3D map.cub
fclean: clean
re: fclean all
