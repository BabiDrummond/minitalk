CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include/ -I$(LIBFT_DIR)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src/
SRC = bit_utils.c
OBJ_DIR = objs/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

C_SRC = client.c
C_OBJ = $(C_SRC:%.c=$(OBJ_DIR)%.o)
C_NAME = client

S_SRC = server.c
S_OBJ = $(S_SRC:%.c=$(OBJ_DIR)%.o)
S_NAME = server

all: $(LIBFT) $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ) $(OBJ)
	$(CC) $(C_OBJ) $(OBJ) $(LIBFT) $(INCLUDES) -o $(C_NAME)

$(S_NAME): $(S_OBJ) $(OBJ)
	$(CC) $(S_OBJ) $(OBJ) $(LIBFT) $(INCLUDES) -o $(S_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(C_NAME) $(S_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all