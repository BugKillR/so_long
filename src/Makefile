NAME = src.a

SRCS = create_map.c \
		free.c \
		map_debugger.c \
		validate_map1.c \
		validate_map2.c \
		validate_map3.c \
		validate_map4.c \
		validate_map5.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re