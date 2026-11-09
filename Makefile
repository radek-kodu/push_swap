NAME = push_swap.a

CC = cc
CGFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	lib_data.c \
	disorder.c \
	bench.c \
	stack_utils.c \
	stack_utils2.c \
	input/convert_input.c \
	input/input_utils.c \
	input/input_utils2.c \
	input/input_utils3.c \
	input/parse_flags.c \
	input/parse_nbrs.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	algorithms/adaptive.c \
	algorithms/complex.c \
	algorithms/indexing.c \
	algorithms/medium.c \
	algorithms/simple.c \
	algorithms/small.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all