NAME			= fdf
LIBFT			= libft.a
MLX				= libmlx_Linux.a

SRCS            =	utils/ft_init.c \
					utils/ft_clean.c \
					utils/ft_error_1.c \
					utils/ft_error_2.c \
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
					handling/ft_exit_button.c \
					handling/ft_keypress_utils.c \
					ft_handling.c \
					ft_parsing.c \
					ft_rendering.c \
					ft_main.c \

SRCS_DIR		= ./srcs
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./headers
LIBFT_DIR		= ./libft
MLX_DIR			= ./mlx_linux

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR) -I $(MLX_DIR)

all						: ${NAME}

${NAME}         		: ${OBJS}
			${CC} -g $(OBJS) -o $(NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Llibft -lft  

${BUILD_DIR}/%.o		: $(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
			${CC} $(HFLAGS) ${CFLAGS} -O3 -c $< -o $@ 

$(LIBFT_DIR)/$(LIBFT)	:
			make -C $(LIBFT_DIR)

$(MLX_DIR)/$(MLX)		:
			make -C $(MLX_DIR)

clean					:
			make -C $(LIBFT_DIR) clean
			make -C $(MLX_DIR) clean
			rm -rf ${OBJS}

fclean					: clean
			rm -rf ${NAME} $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

re						: fclean all

.PHONY					: all clean fclean re