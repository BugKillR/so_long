MAIN = main.c
EXE = so_long

# ---------- Compiler ----------
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lminilibx-linux -lmlx -lX11 -lXext -lm

# ---------- Libft ----------
LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ---------- GNL ----------

GNL_DIR		= ./get_next_line
GNL			= $(GNL_DIR)/get_next_line.a

# ---------- Minilibx (Linux) ----------

MLX_DIR		= ./minilibx-linux
MLX			= $(MLX_DIR)/libmlx_Linux.a

# ---------- Sources ----------

SRC_DIR		= ./src
SRC			= $(SRC_DIR)/src.a

# ---------- Commands ----------

all: $(LIBFT) $(MLX) $(GNL) $(SRC)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MAIN) $(SRC) $(GNL) $(LIBFT) $(MLX) -o $(EXE)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(MLX):
	make -C $(MLX_DIR) all

$(GNL):
	make -C $(GNL_DIR) all

$(SRC):
	make -C $(SRC_DIR) all

clean:
	make -C $(GNL_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(SRC_DIR) clean

fclean: clean
	make -C $(GNL_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(SRC_DIR) fclean
	rm -f $(EXE)
	rm -f $(MLX) $(MLX_DIR)/libmlx_*.a

re: fclean all

.PHONY: all clean fclean re