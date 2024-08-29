/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:12 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/01 20:34:04 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"
#include "../libft/libft.h"

static int	check_point(char *av)
{
	int	point;
	int	i;

	point = 0;
	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == 46)
		return (0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && av[i] != 46)
			return (0);
		if (av[i] == 46)
			point++;
		i++;
	}
	if (point > 1)
		return (0);
	return (1);
}

int	check_if_valid(char **av)
{
	if (!check_point(av[2]) || !check_point(av[3]))
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s2 != *s1)
			return (1);
		s2++;
		s1++;
		if (!*s2 && *s1)
			return (1);
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("MiniLibX Allocation Error !\n", 0);
	exit(1);
}

void	print_valid_commands(void)
{
	ft_putstr_fd("\nTry Again, With Commands Below!\n\n", 1);
	ft_putstr_fd("./fractol Mandelbrot\n\n", 1);
	ft_putstr_fd("./fractol Julia real.point imaginary.point\n\n", 1);
	exit(1);
}
