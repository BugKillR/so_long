NAME	= libft.a

SRCS	= ft_bzero.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_realloc.c \
			ft_flood_fill.c \
			ft_count_chr.c \
			ft_strlcpy.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
