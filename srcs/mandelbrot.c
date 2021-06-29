/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 14:32:43 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_mandelbrot_loop(t_env *env)
{
	ft_key_event(env);
	return (0);
}

int	ft_init_mandelbrot(t_env *env)
{
	env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
						env->screen_h, "fractol: Mandelbrot");
	env->img->img_ptr = mlx_new_image(env->mlx->mlx_ptr, env->screen_w,
						env->screen_h);
	env->img->addr = (int *)mlx_get_data_addr(env->img->img_ptr,
					&env->img->bpp, &env->img->size_l, &env->img->endian);
	return (0);
}

int	ft_mandelbrot(t_env *env)
{
	ft_init_mandelbrot(env);
	mlx_loop_hook(env->mlx->mlx_ptr, &ft_mandelbrot_loop, env);
	mlx_hook(env->mlx->win, KEY_PRESS, 0, &ft_key_press, env);
	mlx_hook(env->mlx->win, KEY_RELEASE, 0, &ft_key_release, env);
	mlx_hook(env->mlx->win, 17, 0, &ft_exit, env);
	mlx_loop(env->mlx->mlx_ptr);
	return (0);
}
