/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:32:01 by moait-la          #+#    #+#             */
/*   Updated: 2024/08/29 22:30:59 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT 600
# define WIDTH 600
# define MAX_ITER 35

typedef struct s_fractol
{
	//mlx stuff
	void	*mlx;
	void	*wind;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*frac_name;
	//values
	double	max_iter;
	int		color_factor;
	int		mybool;
	//events values
	double	shift_x;
	double	shift_y;
	double	zoom;//zoom_factor
	//julia povided parameters
	double	r_point;
	double	i_point;
	double	shiftzoom_x;
	double	shiftzoom_y;
}			t_fractol;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct {
    uint8_t r, g, b;
} t_color;

// Events
void	listen_for_events(t_fractol *fractol);
int		keys_input(int keycode, void *param);
int		mouse_input(int button, int x, int y, void *param);

// fractals
void	render_mandelbrot(t_fractol *fractol);
void	render_julia(t_fractol *fractol);
void	render_burningship(t_fractol *fractol);

// render utils
t_color	get_color(int iter_nbr, t_fractol *fractol);
double	scale(double unscaled, double new_min, double new_max, double old_max);
void	init_mlx(t_fractol *fractol);
void	set_starting_values(t_fractol *fractol, char *name, char **av, int ac);
void	set_starting_values_bonus(t_fractol *fractol, char *name);
void	redraw_pixels(t_fractol fractol);

// string utils
int		check_if_valid(char **av);
int		ft_strcmp(char *s1, char *s2);
double	ft_atod(const char *str);

// Error
void	print_valid_commands(void);
void	ft_error(void);

#endif