/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:29 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/03 17:14:03 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

static void	mandelbrot(t_fractol *fractol)
{
	set_starting_values(fractol, "Mandelbrot", NULL, 0);
	init_mlx(fractol);
	render_mandelbrot(fractol);
}

static void	julia(t_fractol *fractol, int ac, char **av)
{
	set_starting_values(fractol, "Julia", av, ac);
	init_mlx(fractol);
	render_julia(fractol);
}

int	main(int ac, char *av[])
{
	t_fractol	fractol;

	if (ac == 2 && !ft_strcmp("Mandelbrot", av[1]))
		mandelbrot(&fractol);
	else if (ac == 4 && !ft_strcmp("Julia", av[1]))
	{
		if (!check_if_valid(av))
			print_valid_commands();
		julia(&fractol, ac, av);
	}
	else
		print_valid_commands();
	listen_for_events(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
