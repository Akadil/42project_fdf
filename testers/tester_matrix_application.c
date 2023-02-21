#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float *ft_apply_matrix(int x, int y, int z, int alpha, int beta)
{
	float	*returner;

    returner = (float *)malloc(sizeof(float) * 2);
	float	alpha_rad;
	float	beta_rad;
	float	pi;

	pi = 3.142857;
	alpha_rad = alpha * (pi / 180.0);
	beta_rad = beta * (pi / 180.0);

    returner[0] = x * cosf(beta_rad) - z * sinf(beta_rad);
	returner[1] = x * sinf(alpha_rad) * sinf(beta_rad) + y * cosf(alpha_rad) + z * sinf(alpha_rad) * cosf(beta_rad);
	//my_mlx_pixel_put(img, new_x, new_y, 0x00FF00);
	return (returner);
}

int main(void)
{
    float *val;

    val = ft_apply_matrix(1, 1, 1, 30, 45);
    printf("%f and %f", val[0], val[1]);
}