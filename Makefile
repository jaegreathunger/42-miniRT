NAME	= 	miniRT

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
LINK	=	-lmlx  -framework OpenGL -framework AppKit

SRCS	= 	src/mlx/*.c \
			src/*.c \
			lib/libft/libft.a

$(NAME):
	@make all -C lib/libft
	@$(CC) $(CFLAGS) $(LINK) -L ./lib/libmlx $(SRCS) -o $(NAME)
	@echo "miniRT has been created"

all: $(NAME)

clean:
	@make clean -C lib/libft
	@rm -f $(NAME)
	@echo "miniRT has been cleaned"

fclean: clean
	@make fclean -C lib/libft
	@echo "miniRT has been fcleaned"

re: fclean all

.PHONY: all, clean, fclean, re
