/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:14:14 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/28 16:28:37 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_exit(t_env *env)
{
	mlx_destroy_window(env->mlx->mlx_ptr, env->mlx->win);
	if (env->img)
		free(env->img);
	if (env->mlx)
		free(env->mlx);
	exit(0);
}

int	ft_exit_arg(void)
{
	ft_putstr_fd("Usage: ./fractol [fractal]\n", 1);
	ft_putstr_fd("Available fractals :\n", 1);
	ft_putstr_fd(" - Julia\n - Mandelbrot\n - Burning_ship\n - Multibrot\n", 1);
	exit(0);
}
