/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/30 13:37:47 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_calcul_fractol(t_env *env)
{
	env->row = 0;
	while (env->row < env->screen_h)
	{
		env->col = -1;
		while (env->col < env->screen_w)
		{
			if (env->iter < env->iter_max)
				env->img->addr[env->row * env->img->size_l / 4 + env->col]
					= env->color * ft_iter(env);
			else
				env->img->addr[env->row * env->img->size_l / 4 + env->col]
					= 0 * ft_iter(env);
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
	env->iter = 0;
	env->zoom = 1;
	if (env->fract == 1)
	{
		env->z_re = -0.7;
		env->z_im = 0.27015;
	}
	if (env->fract == 1)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Julia");
	else if (env->fract == 2)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Mandelbrot");
	else if (env->fract == 3)
		env->mlx->win = mlx_new_window(env->mlx->mlx_ptr, env->screen_w,
				env->screen_h, "fractol: Burning ship");
	else if (env->fract == 4)
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
	if (env->fract == 1)
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
