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
    
} t-data;
```

Main part
```
def main():
    t_data  my_data;

    mlx_init();
    mlx_window();
    mlx_image();

    ft_parse();

    ft_draw();
    mlx_loop_hook();
    mlx_hook_keyboard();
    mlx_loop();
    mlx_clean();
```