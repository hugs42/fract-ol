/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:42:59 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/20 21:53:39 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_get_size_screen(t_env *env)
{
	int		max_width;
	int		max_height;

	max_width = 0;
	max_height = 0;
	mlx_get_screen_size(env->mlx->mlx_ptr, &max_width, &max_height);
	if (env->screen_w > max_width)
		env->screen_w = max_width;
	if (env->screen_h > max_height)
		env->screen_h = max_height;
	return (0);
}

int	ft_fractol(t_env *env, int fract)
{
	if (fract == 1)
		ft_julia(env);
	else if (fract == 2)
		ft_mandelbrot(env);
	ft_exit(env);
	return (0);
}

int	ft_check_arg(char *arg)
{
	if (((ft_strncmp(arg, "Julia", 5) == 0) && (ft_strlen(arg) == 5)) ||
		((ft_strncmp(arg, "julia", 5) == 0) && (ft_strlen(arg) == 5)))
		return (1);
	else if (((ft_strncmp(arg, "Mandelbrot", 10) == 0) && (ft_strlen(arg) ==
	10)) || ((ft_strncmp(arg, "mandelbrot", 10) == 0) && (ft_strlen(arg) == 10)))
		return (2);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fract;
	t_env	env;

	fract = 0;
	if (argc != 2)
		ft_exit_arg();
	else
	{
		fract = ft_check_arg(argv[1]);
		if (fract != 1 && fract != 2)
			ft_exit_arg();
		else
		{
			ft_init_fractol(&env, fract);
			ft_fractol(&env, fract);
		}
	}
	return (0);
}
