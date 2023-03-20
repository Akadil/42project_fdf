# Fil de fer (FdF)
> The graphical project to represent a landscape as a 3D object [Subject](en.subject.pdf) \
> Status: Finished

<img src="./images/fdf_example1.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 400px">

Table of contents
=================

<!--ts-->
   * [About](#About)
   * [Installation](#Installation)
   * [Structure](#Structure)
   * [Keyboard](#Keyboard)
   * [Result](#Results)

<!--te-->

About
=====

### End product:
- Create controllable 2-d representation of 3-d object
### Features:
- Show the 3d object
- Zoom in and out
- Translate the model
- Rotate the model
- Add one more bonus (color change)
### Requirements:
- We have to use the MiniLibx and math library
- Take a map as an input
- Use isometric projection for transforming 2d → 3d
- The management of the window must remain smooth
- ESC and cross button

<br> </br>

Structure
=====================
Structure of the code

    .
    ├── mlx_linux					# Graphic library
    |── libft						# Previously saved function
    |── headers
    └── srcs
        ├── main.c					# All big stages of the code  
        ├── ft_parsing.c			# Parsing and preprocessing
        |    └── parsing
        |        ├── includes
        |        ├── utils
        |        └── *.c
        ├── ft_rendering.c			# functions to run the render
        |    └── rendering
        |        ├── includes
        |        ├── utils
        |        └── *.c
        ├── ft_handling.c			# Control the map
        |    └── handling
        |        ├── includes
        |        ├── utils
        |        └── *.c
		└── utils
			├── ft_clean.c			
			└── ft_error.c

<br> </br>

Installation
============

On Linux:
```
make
./fdf maps/42.fdf
```

<br> </br>

Keyboard:
=========

- `a and d` rotate through y axes
- `w and s` rotate through x axes
- `q and e` rotate through z axes
- `u, h, j and k` move the map
- `+ and -` zoom in and out
- `z and x` change the height of the map
- `space` change the color

<br> </br>

Results
=======

<img src="./images/ezgif.com-video-to-gif.gif" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 400px">

<img src="./images/Screenshot from 2023-03-20 20-38-01.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 100px"> 
<img src="./images/Screenshot from 2023-03-20 21-01-24.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 100px">
<img src="./images/Screenshot from 2023-03-20 20-58-19.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 100px">
<img src="./images/Screenshot from 2023-03-20 20-59-19.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 100px">
<img src="./images/Screenshot from 2023-03-20 20-59-50.png" alt="Alt text" title="Final product" style="display: inline-block; margin: 0 auto; max-width: 100px">

<br> </br>


