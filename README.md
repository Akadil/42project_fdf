# Fil de fer (FdF). 
> The graphical project to represent a landscape as a 3D object \
> Status: Ongoing, planning phase

<img src="./images/fdf_example1.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 400px">

# About the project
#### End product:
- Create controllable 2-d representation of 3-d object
#### Features:
- Show the 3d object in 2 projections (iso + smth)
- Zoom in and out
- Translate the model
- Rotate the model
- Add one more bonus
#### Requirements:
- We have to use the MiniLibx and math library
- Take a map as an input (taking into account that map is properly formatted)
- Use isometric projection for transforming 2d → 3d
- The management of my window must remain smooth
- ESC and cross button



# Planning and pseudocode 

My data structure. I have decided to store everything in one place to create the mvp of the project. At the end I will defactorize it 
```
typedef struct s_data{

    // MLX info
    void *win;
    void *ptr;
    
    // Matrix info
    int   **matrix;
    int   mtrx_length;
    int   mtrx_height;
    int     z_max;
    
    // Scaling info
    int     alpha; 
    int     beta;
    int     grid_coef;
    int     attitude_coef;
    int     x_offset;
    int     y_offset;
    int     proj_model;

} t-data;
```

## Main part. 
Here I have to have only the mlx configurations
1. Initialize my data
2. Prepare my data
    1. Parse the map
    2. Prepare the scale coefficients
3. Draw the 3d object with default configuration 
4. Allow mouse and keyboard hooks to control the object
5. Clean at the end 
```
def main():
    t_data  my_data;

    mlx_init();
    ft_prepare_the_data();

    ft_draw();
    mlx_hook_keyboard();
    mlx_hook_mouse();
    mlx_clean();
```
<br> </br>

---
<br> </br>
## Ft_prepare the data
```
def ft_prepare_the_data(int argc, char **argv, t_data *my_data):
    ft_parse(argc, argv, my_data);
    ft_set_coefficients(my_data);
```

```
def ft_parse():
    int fd_infile;
    char *str;
    char **all_grids;

    fd_infile = open(argv[1]);

    while (go through each row)
        str = get_next_line(fd_infile);
        all_grids = ft_split(str, ' ');
        while (go through each element):
            if (normal)
                append to matrix
            else:
                free() and quit()

```

```
def ft_set_coefficients(t_data *my_data):
    my_data->grid_coef = ft_calculate_coef();
    my_data->alpha = 30;
    my_data->beta = 30;
    my_data->x_offset = 500;
    my_data->y_ofset = 250;
```

```
def ft_calculate_coef():
    int max;
    int z_max = ft_z_max();

    max = data->mtrx_width;
    if (data->mtrx_height > max)
        max = data->mtrx_height
    my_data->grid_coef = ( 1920 - x_offset * 2 ) / max / sqrt(2);
    my_data->attitude_coef = (1080 - y_offset * 2 ) / z_max;

    // if the coef are too small, try to handle with different offsets;

```

<br> </br>

---
<br> </br>

## Ft_draw()
Drawing part, with initially set coefficients

```
def ft_draw(t_data *data):
    
    int     row;
    int     col;

    row = 0;
    while (data->row)
    {
        col = 0;
        while (data->col)
        {
            ft_apply_coefficients(data, row, column);
            if (col != 0)
                ft_draw_line_row_row+1();
            if (row != 0)
                ft_draw_line_col_col+1();
            col++;
        }
        row ++;
    }
```

```
def draw_line(t_data *data, int point1[2], int point2[2], int z1, int z2):
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
		//printf("I was here %d %d\n", x0, y0);
        my_mlx_pixel_put(img, x0, y0, ft_color());
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    my_mlx_pixel_put(img, x0, y0, ft_color());
}

def ft_color(t_data *data, int z1, int z2, int x1, x0, x_new)
    int color;
    int z1_coef;
    int z2_coef;

    z1_coef = z1 * 255 / data->z_max; // 137
    z2_coef = z2 * 255 / data->z_max; // 156

    color = ft_min(z1_coef, z1_coef) + (x_new - x0) / (x1 - x0) * abs(z1_coef - z2_coef);
    return (create_rgb(255, 255, 255 - color));

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
```

```
def apply_coefficients(data, row, column):
    
    int     returner[2];
    float   alpha_rad;
    float   beta_rad;
    float   pi;

    pi = 3.142857;
    alpha_rad = data->alpha * (pi / 180.0);
    beta_rad = data->beta * (pi / 180.0);

    returner[0] = (x * data->grid_coef + data->x_offset) * cos(alpha_rad) - 
                    (data->matrix[row][col] * data->grid) * sin(beta_rad)
    returner[1] = (x * data->grid_coef + data->x_offset) * sin(alpha_rad) * sin(beta_rad)+ 
                    (y * data->grid_coef + data->y_offset) * cos(alpha_rad) + 
                    (data->matrix[row][col] * data_grid) * sin (alpha_rad) * cos (beta_rad)
```

<br> </br>

---
<br> </br>

## Handle hooks

I have 2 type of hooks: keybord and mouse \
### Keyboard:
- `a:` rotate_left
- `d:` rotate right
- `w:` rotate upword
- `s:` rotate downword
- `left+right+up+down:` translate
- `+:` zoom in
- `-:` zoom out  
- `t:` change translation model
- `c:` change color

```
int handle_keypress(int keysym, t_data *data)
{
    if (keysym == 'esc')
    {
        mlx_destroy and ft_clean;
    }
    if (keysym == 'w')
    {
        data->beta = data->beta + 10;
    }
    if (keysym == 'a')
    {
        data->alpha = data->alpha + 10;
    }
    if (keysym == +)
    {
        data->grid_coef = data_grid_coef + 1; // Or something like this
    }
    if (keysym == t)
    {
        change
    }
    if (translate)
        translate
}
```

<br> </br>

---
<br> </br>

## Handle the color
> How to manage drawing the fucking color !!!!!

