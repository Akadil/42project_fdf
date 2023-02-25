NAME			= fdf

SRCS            = ft_init.c ft_prepare_data.c ft_main.c

SRCS_DIR		= ./srcs
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
			${CC} $(OBJS) -o $(NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibft -lft  

${BUILD_DIR}/%.o	:$(SRCS_DIR)/%.c
			${CC} ${CFLAGS} $(HFLAGS) -g -Imlx_linux -Ilibft/includes -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

clean			:
			rm -rf ${OBJS}

fclean			: clean
			rm -rf ${NAME}

re				: fclean all

.PHONY			: all clean fclean re