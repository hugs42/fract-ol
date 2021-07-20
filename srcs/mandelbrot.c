/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/20 11:47:55 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_calcul_points(t_env *env)
{
	double	x;
	double	y;
	double x_new;

	x = 0.0;
	y = 0.0;
	x_new = 0.0;
	env->iter = 0;
	int i = 0;
	env->z_re = (env->col - env->screen_w / 2.0) * 4.0 / env->screen_w;
	env->z_im = (env->row - env->screen_h / 2.0) * 4.0 / env->screen_w;
	while (env->iter < ITER_MAX && x * x + y * y <= 4)
	{
		x_new = x * x - y * y + env->z_re;
		y = 2 * x * y + env->z_im;
		x = x_new;
		env->iter++;
		i++;
	}
	return (env->iter);
}

int	ft_calcul_mandelbrot(t_env *env)
{
	int color = 0;
	env->row = 0;
	while (env->row < env->screen_h)
	{
		env->col = 0;
		while (env->col < env->screen_w)
		{
			if (env->iter < ITER_MAX)
				env->img->addr[env->row * env->img->size_l / 4 + env->col] =
					env->color * ft_calcul_points(env);
			else
				env->img->addr[env->row * env->img->size_l / 4 + env->col] =
					env->color * ft_calcul_points(env);
			env->col++;
		}
		env->row++;
	}
	return (0);
}

int	ft_mandelbrot_loop(t_env *env)
{
	ft_key_event(env);
	ft_calcul_mandelbrot(env);
	mlx_put_image_to_window(env->mlx->mlx_ptr, env->mlx->win, env->img->img_ptr, 0, 0);
	return (0);
}

int	ft_init_mandelbrot(t_env *env)
{
	env->x_center = env->screen_w / 2;
	env->y_center = env->screen_h / 2;
	env->color = 0x00003F;
	env->row = 0;
	env->col = 0;
	env->z_re = 0;
	env->z_im = 0;
	env->iter = 150;
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
	t_mandel	mandel;

	ft_init_mandelbrot(env);
	mlx_loop_hook(env->mlx->mlx_ptr, &ft_mandelbrot_loop, env);
	mlx_hook(env->mlx->win, KEY_PRESS, 0, &ft_key_press, env);
	mlx_hook(env->mlx->win, KEY_RELEASE, 0, &ft_key_release, env);
	mlx_mouse_hook(env->mlx->win, ft_mouse_hook, env);
	mlx_hook(env->mlx->win, 17, 0, &ft_exit, env);
	mlx_loop(env->mlx->mlx_ptr);
	return (0);
}
