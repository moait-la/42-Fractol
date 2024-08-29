/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:23 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/01 18:00:43 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

static int	destroy_window(void	*param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->wind);
	exit(0);
	return (0);
}

int	keys_input(int keycode, void *param)
{
	double		shift_factor;

	if (((t_fractol *)param)->zoom < 0.2)
		shift_factor = ((t_fractol *)param)->zoom / 2;
	else
		shift_factor = 0.04;
	if (keycode == 53 || keycode == 7)
		destroy_window(((t_fractol *)param));
	else if (keycode == 8)
		((t_fractol *)param)->color_factor += 1;
	else if (keycode == 123)
		((t_fractol *)param)->shift_x += shift_factor;
	else if (keycode == 124)
		((t_fractol *)param)->shift_x -= shift_factor;
	else if (keycode == 126)
		((t_fractol *)param)->shift_y -= shift_factor;
	else if (keycode == 125)
		((t_fractol *)param)->shift_y += shift_factor;
	if (keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126 || keycode == 15 || keycode == 8)
		redraw_pixels(*(t_fractol *)param);
	return (0);
}

int	mouse_input(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (x == 999999 || y == 999999)
		return (0);
	if (button == 5 || button == 2)
	{
		fractol->zoom *= 1.1;
		fractol->max_iter -= 0.5;
	}
	else if (button == 4 || button == 1)
	{
		fractol->zoom *= 0.90;
		fractol->max_iter += 0.5;
	}
	redraw_pixels(*fractol);
	return (0);
}

void	listen_for_events(t_fractol *fractol)
{
	mlx_hook(fractol->wind, 2, 0, keys_input, (void *)fractol);
	mlx_hook(fractol->wind, 4, 0, mouse_input, (void *)fractol);
	mlx_hook(fractol->wind, 17, 0, destroy_window, (void *)fractol);
}
