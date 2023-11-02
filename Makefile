NAME	= 	miniRT

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror
LINK	=	-lmlx  -framework OpenGL -framework AppKit

SRCS	= 	src/*.c \
			libft/libft.a

$(NAME):
	@make all -C libft
	@$(CC) $(CFLAGS) $(LINK) -L ./libmlx $(SRCS) -o $(NAME)
	@echo "miniRT has been created"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -f $(NAME)
	@echo "miniRT has been cleaned"

fclean: clean
	@make fclean -C libft
	@echo "miniRT has been fcleaned"

re: fclean all

.PHONY: all, clean, fclean, re
