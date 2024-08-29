/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:31:15 by moait-la          #+#    #+#             */
/*   Updated: 2024/06/01 19:42:30 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

static char	*ft_skip_zero(const char *str)
{
	if (*(str + 1) == '.')
		return ((char *)str);
	while (*str && *str == '0' && *(str + 1) != '.')
		str++;
	return ((char *)str);
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static double	get_nbr(const char *str)
{
	double	total;
	double	division;
	int		count;

	division = 10.00;
	total = 0.00;
	count = -1;
	while (*str)
	{
		total = (total * 10) + (*str - '0');
		str++;
		if (*str == '.')
		{
			str++;
			while (*str)
			{
				total += (*str - '0') / division;
				division *= 10;
				str++;
			}
		}
	}
	return (total);
}

double	ft_atod(const char *str)
{
	int			sign;
	double		total;

	sign = get_sign(&str);
	str = ft_skip_zero(str);
	total = get_nbr(str);
	return (total * sign);
}
