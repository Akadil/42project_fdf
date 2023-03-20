#include "ft_data.h"
#include <stdio.h>

void ft_print(t_data *data, char **argv)
{
    int i;
    int j;

    i = 0;
    printf("The map - %s\n\n", argv[1]);
    printf("Height: %d, Width: %d\n", data->mtrx.mtrx_height, data->mtrx.mtrx_length);
    while (i < data->mtrx.mtrx_height)
    {
        j = 0;
        while (j < data->mtrx.mtrx_length)
        {
            printf("%d ", data->mtrx.matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("Angles: alpha %d, beta %d\n", data->coef.alpha, data->coef.beta);
    printf("Coefficients: grid %d, att %d\n", data->coef.grid, data->coef.attitude);
    printf("Offsets: x %d, y %d\n", data->coef.x_offset, data->coef.y_offset);
    printf("\n");
}