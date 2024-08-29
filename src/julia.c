/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:30:58 by moait-la          #+#    #+#             */
/*   Updated: 2024/08/29 22:30:01 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

static int	do_formula_julia(int x, int y, t_fractol *fractol)
{
	int		iter_nbr;
	t_point	z;
	t_point	c;
	t_point	res;

	iter_nbr = 0;
	c.x = fractol->r_point;
	c.y = fractol->i_point;
	z.x = scale(x, -2, 2, WIDTH - 1) * fractol->zoom + fractol->shift_x;
	z.y = scale(y, 2, -2, HEIGHT - 1) * fractol->zoom + fractol->shift_y;
	while (iter_nbr < fractol->max_iter)
	{
		res.x = z.x * z.x - z.y * z.y + c.x;
		res.y = 2 * z.x * z.y + c.y;
		if (sqrt(res.x * res.x + res.y * res.y) > 2)
			return (iter_nbr);
		z = res;
		iter_nbr++;
	}
	return (0);
}

static void	put_pixel_julia(int x, int y, int iter_nbr, t_fractol *fractol)
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

void	render_julia(t_fractol *fractol)
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
			iter_nbr = do_formula_julia(x, y, fractol);
			put_pixel_julia(x, y, iter_nbr, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->wind, fractol->img, 0, 0);
}
