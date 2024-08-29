/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:35 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/01 20:42:26 by moait-la         ###   ########.fr       */
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

void	set_starting_values_bonus(t_fractol *fractol, char *name)
{
	fractol->zoom = 1;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->color_factor = 1;
	fractol->frac_name = name;
	fractol->max_iter = MAX_ITER;
}

void	redraw_pixels(t_fractol fractol)
{
	render_burningship(&fractol);
}

t_color	get_color(int iter_nbr, t_fractol *fractol)
{
	t_color	color;

	color.r = (iter_nbr * 3 * fractol->color_factor) + 120;
	color.g = (iter_nbr * 7) * fractol->color_factor;
	color.b = (iter_nbr * 9 * fractol->color_factor);
	return (color);
}

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min);
}
