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
    
    // Scaling info
    int     alpha; 
    int     beta;
    int     grid;
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

<br> </br>

---
<br> </br>

## Handle hooks

I have 2 type of hooks: keybord and mouse \
keyboard
- `a:` rotate_left
- `d:` rotate right
- `w:` rotate upword
- `s:` rotate downword
- `left+right+up+down:` translate
- `+:` zoom in
- `-:` zoom out  
- `t:` change translation model
- `c:` change color

