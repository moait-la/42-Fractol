/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:32 by moait-la          #+#    #+#             */
/*   Updated: 2024/08/29 22:29:29 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	do_formula(int x, int y, t_fractol *fractol)
{
	int		iter_nbr;
	t_point	z;
	t_point	c;
	t_point	res;

	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, -2, 2, WIDTH - 1) * fractol->zoom + fractol->shift_x;
	c.y = scale(y, 2, -2, HEIGHT - 1) * fractol->zoom + fractol->shift_y;
	iter_nbr = 0;
	while (iter_nbr < fractol->max_iter)
	{
		res.x = z.x * z.x - z.y * z.y + c.x;
		res.y = 2 * (z.x * z.y) + c.y;
		if (sqrt(res.x * res.x + res.y * res.y) > 2)
			return (iter_nbr);
		z = res;
		iter_nbr++;
	}
	fractol->mybool = 1;
	return (0);
}



void	put_pixel(int x, int y, int iter_nbr, t_fractol *fractol)
{
	int		offset;
	char	*dst;
	t_color	color;

	offset = (y * fractol->line_length) + (x * (fractol->bpp / 8));
	dst = fractol->addr + offset;
	color = get_color(iter_nbr, fractol);
	if (fractol->mybool == 1)
		*(int *)dst = 0x000000;
	else
		*(int *)dst = (color.g << 16) | (color.b << 8) | (color.r);
}

void	render_mandelbrot(t_fractol *fractol)
{
	int	iter_nbr;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->mybool = 0;
			iter_nbr = do_formula(x, y, fractol);
			put_pixel(x, y, iter_nbr, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->wind, fractol->img, 0, 0);
}
