NAME			= fdf


SRCS            = tester_init.c

SRCS_DIR		= ./testers
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./headers

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR)

all					: ${NAME}

${NAME}         	: ${OBJS}
			${CC} $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${BUILD_DIR}/%.o	:$(SRCS_DIR)/%.c
			${CC} ${CFLAGS} $(HFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean			:
			rm -rf ${OBJS}

fclean			: clean
			rm -rf ${NAME}

re				: fclean all

.PHONY			: all clean fclean re