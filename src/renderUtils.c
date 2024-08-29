/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:35 by moait-la          #+#    #+#             */
/*   Updated: 2024/08/30 00:28:26 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_error();
	fractol->wind = mlx_new_window(fractol->mlx, WIDTH, HEIGHT,
			fractol->frac_name);
	if (fractol->wind == NULL)
		ft_error();
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->wind);
		ft_error();
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bpp,
			&fractol->line_length, &fractol->endian);
}

t_color interpolate_color(t_color start, t_color end, double factor) {
    double smooth_factor = (1 - cos(factor * M_PI)) / 3;
    t_color color;
    color.r = (uint8_t)(start.r + smooth_factor * (end.r - start.r));
    color.g = (uint8_t)(start.g + smooth_factor * (end.g - start.g));
    color.b = (uint8_t)(start.b + smooth_factor * (end.b - start.b));
    return color;
}

t_color get_color(int iter_nbr, t_fractol *fractol) {
    t_color colors[4] = {
        {180, 105, 180},  
        {100, 255, 203},  
        {180, 165, 0},   
        {255, 0, 0}     
    };

    double factor = (double)iter_nbr / fractol->max_iter;
    int num_colors = sizeof(colors) / sizeof(colors[0]);
    int index = (int)(factor * (num_colors - 1));
    double local_factor = (factor * (num_colors - 1)) - index;

    return interpolate_color(colors[index], colors[index + 1], local_factor);
}


double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min);
}

void	set_starting_values(t_fractol *fractol, char *name, char **av, int ac)
{
	fractol->zoom = 1;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->color_factor = 1;
	fractol->frac_name = name;
	fractol->max_iter = MAX_ITER;
	if (ac == 4)
	{
		fractol->r_point = ft_atod(av[2]);
		fractol->i_point = ft_atod(av[3]);
	}
}

void	redraw_pixels(t_fractol fractol)
{
	if (!ft_strcmp(fractol.frac_name, "Mandelbrot"))
		render_mandelbrot(&fractol);
	else if (!ft_strcmp(fractol.frac_name, "Julia"))
		render_julia(&fractol);
}

