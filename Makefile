NAME			= fdf

SRCS            =	utils/ft_init.c \
					ft_main.c \
					utils/ft_clean.c \
					utils/ft_error.c \
					parsing/ft_parse_matrix.c \
					parsing/ft_set_coefficients.c \
					parsing/ft_set_colors.c \
					ft_parsing.c \
					rendering/ft_put_pixel.c \
					rendering/ft_render_projection.c \
					ft_render.c

SRCS_DIR		= ./______________srcs__________________
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
			${CC} -g $(HFLAGS) ${CFLAGS} -O3 -c $< -o $@ 

clean			:
			rm -rf ${OBJS}

fclean			: clean
			rm -rf ${NAME}

re				: fclean all

.PHONY			: all clean fclean re