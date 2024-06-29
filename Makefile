CC = cc
SRCS = fractol.c utils.c
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework AppKit -framework OpenGL
DEPS = fractol.h
LIB = fractol.a
OUT = fractol
OBJS = $(SRCS:.c=.o)

all: $(OUT)

$(OUT): $(LIB) $(DEPS)
	$(CC) $(CFLAGS) $(MLX) fractol.c $(LIB) -o $(OUT)

$(LIB): $(OBJS)
	ar -rc $(LIB) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS) $(LIB)

fclean: clean
	rm -rf $(LIB) $(OUT)

re: fclean all

