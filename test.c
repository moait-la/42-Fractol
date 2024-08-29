#include <stdio.h>
#include <mlx.h>

typedef struct img_values
{
    int bpp;
    int line_length;
    int endian;
} img;

int main()
{
    img img;
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
        //It initializes the connection between your program and the windowing system
    mlx_win = mlx_new_window(mlx, 1000, 1000, "window");
        // creates the window
    void *mlx_img = mlx_new_image(mlx, 1000, 1000);
        // allocates (block of memory) a 2d array of pixels
    char *addr = mlx_get_data_addr(mlx_img, &img.bpp, &img.line_length, &img.endian);
        //pointer to the actuall pixels
        //This pointer can be used to access and manipulate the pixel data of the image
        //points to the start of the pixel data within the image
        //Using a char * pointer allows for easy manipulation of individual bytes
        //The line_length parameter tells you how many bytes are allocated for each line of the image.
    int offset = (500 * img.line_length + 500 * (img.bpp / 8));
    //This offset value can be used to access the memory location of a specific pixel within the image data.
    char  *dst = addr + offset;
    //This line of code calculates the memory address of a specific pixel within the image buffer
    //img.addr represents the starting address of the image buffer, where the pixel data is stored.
    *(int *)dst = 0xFFFFFF;
    mlx_put_image_to_window(mlx, mlx_win, mlx_img, 0, 0);
    /*
    it takes the image data pointed to by img_ptr and renders it onto the specified window (win_ptr). 
    The image is displayed starting at the coordinates (x, y) within the window.
    */
    mlx_loop(mlx);
    // it creates an infinite loop so the program keeps executing and it also lisents for events
}


/*
** the maximum iteration count is a parameter that determines how many times the iterative formula is applied to each point in the complex plane

** For each point c in the complex plane, the iteration starts from . The formula is repeatedly applied, with the result of each iteration becoming the input for the next iteration.
The iteration continues until either the magnitude of 
exceeds a certain threshold (indicating that
is not in the Mandelbrot set), or the maximum iteration count is reached.
*/


/*
00000000         00000000         00000000         00000000
the most significant byte                          the least signifacnt byte

the shift operation is performed before the assignment
*/



/*

(new_max - new_min) -> calculate length of the new range
(unscaled - 0)      -> calculate distance of the unsacled point from the starting point of the old range
(old_max - 0)       -> calculates the length of the old range

(new_max - new_min) * (unscaled - old_min) -> This part essentially scales the distance of the unscaled
                                              value from the old minimum to the new range.

+ new_min           -> we add it to adjust starting point to start from the new_min in new range
                        Without adding new_min, the scaled value would start from 0 in the new range

*/

MiniLibX uses AppKit for window management and user input handling on macOS, and OpenGL for graphics rendering. It abstracts these complexities,
making graphics programming easier for beginners.




x11 how li resposible 3la gui gracphich user interface bhal screen mangement o drawings color 





opengl is library used for rendering 2d and 3d graphics, it provides set of functions to intract with GPU and draw graphics, and opengl handles colors and textures and visula effects




appkit is framework provided by apple

