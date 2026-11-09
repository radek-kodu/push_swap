NAME = push_swap.a

CC = cc
CGFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	lib_data.c \
	disorder.c \
	bench.c \
	stack_utils.c \
	input/convert_input.c \
	input/ft_aoti.c \
	input/ft_memcpy.c \
	input/ft_strcmp.c \
	input/ft_strdup.c \
	input/ft_strlen.c \
	input/input_utils.c \
	input/parse_flags.c \
	input/parse_nbrs.c \
	input/validate.c \
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