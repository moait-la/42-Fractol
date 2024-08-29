/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:29 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/03 17:14:33 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

static void	burningship(t_fractol *fractol)
{
	set_starting_values_bonus(fractol, "BurningShip");
	init_mlx(fractol);
	render_burningship(fractol);
}

int	main(void)
{
	t_fractol	fractol;

	burningship(&fractol);
	listen_for_events(&fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
