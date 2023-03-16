NAME			= fdf

SRCS            =	utils/ft_init.c \
					utils/ft_clean.c \
					utils/ft_error.c \
					parsing/utils/ft_get_matrix_utils.c \
					parsing/utils/ft_gm_fill_matrix_utils.c \
					parsing/utils/ft_gm_get_rows_utils.c \
					parsing/utils/ft_mlx_create_utils.c \
					parsing/utils/ft_set_params_utils.c \
					parsing/ft_get_matrix.c \
					parsing/ft_gm_fill_matrix.c \
					parsing/ft_gm_get_rows.c \
					parsing/ft_mlx_create.c \
					parsing/ft_set_params.c \
					rendering/utils/ft_draw_line_utils.c \
					rendering/utils/ft_color_utils.c \
					rendering/ft_color.c \
					rendering/ft_draw_line.c \
					rendering/ft_put_pixel.c \
					rendering/ft_render_background.c \
					rendering/ft_render_projection.c \
					rendering/ft_transform.c \
					ft_parsing.c \
					ft_rendering.c \
					ft_main.c \

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