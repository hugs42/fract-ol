/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/29 11:20:35 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_calcul_fractol(t_env *env)
{
	env->row = 0;
	while (env->row < env->screen_h)
	{
		env->col = 0;
		while (env->col < env->screen_w)
		{
			ft_iter(env);
			if (env->iter < env->iter_max)
				env->img->addr[env->row * env->img->size_l / 4 + env->col]
					= env->color * env->iter;
			else if (env->color_cardioid == 1)
				env->img->addr[env->row * env->img->size_l / 4 + env->col]
					= 0xffff * env->iter;
			env->col++;
		}
		env->row++;
	}
	return (0);
}

int	ft_fractol_loop(t_env *env)
{
	ft_refresh_screen(env);
	ft_calcul_fractol(env);
	mlx_put_image_to_window(env->mlx->mlx_ptr, env->mlx->win,
		env->img->img_ptr, 0, 0);
	return (0);
}

int	ft_init_fractol(t_env *env)
{
	if (env->fract == JULIA)
	{
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Julia");
		ft_init_julia(env);
	}
	else if (env->fract == MANDEL)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Mandelbrot");
	else if (env->fract == BURNING)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Burning ship");
	else if (env->fract == MULTI)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Multibrot");
	env->img->img_ptr = mlx_new_image(env->mlx->mlx_ptr, env->screen_w,
			env->screen_h);
	env->img->addr = (int *)mlx_get_data_addr(env->img->img_ptr,
			&env->img->bpp, &env->img->size_l, &env->img->endian);
	return (0);
}

int	ft_fractol(t_env *env)
{
	ft_init_fractol(env);
	mlx_loop_hook(env->mlx->mlx_ptr, &ft_fractol_loop, env);
	if (env->fract == JULIA)
	{
//		mlx_hook(env->mlx->win, KEY_PRESS, 1L << 0, &ft_jul_key_press, env);
		mlx_hook(env->mlx->win, KEY_PRESS, 0, &ft_jul_key_press, env);
		mlx_hook(env->mlx->win, 6, 0, ft_mouse_julia, env);
		mlx_mouse_hook(env->mlx->win, ft_jul_mouse_hook, env);
	}
	else
	{
		mlx_hook(env->mlx->win, KEY_PRESS, 1L << 0, &ft_key_press, env);
		mlx_mouse_hook(env->mlx->win, ft_mouse_hook, env);
	}
//	mlx_hook(env->mlx->win, 33, 1L << 17, &ft_exit, env);
	mlx_hook(env->mlx->win, 17, 0, &ft_exit, env);
	mlx_loop(env->mlx->mlx_ptr);
	return (0);
}
