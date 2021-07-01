/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:40:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/01 13:58:58 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_render_point(t_env *env)
{
	int x;
	int y;
	int ray = 10;

	int xcenter = env->screen_w / 2;
	int	ycenter = env->screen_h / 2;
	x = xcenter + 4;
	y = ycenter + 4;
	env->img->addr[y * env->img->size_l / 4 + x] = 0xFFF;
	mlx_put_image_to_window(env->mlx->mlx_ptr, env->mlx->win, env->img->img_ptr, 0, 0);
	return (0);
}

int	ft_render_axis(t_env *env)
{
	int			x;
	int			y;
	int			color;
//	t_complex	z;


	x = env->screen_w / 2;
	y = 0;
	while (y < env->screen_w)
	{
		env->img->addr[y * env->img->size_l / 4 + x] = 0xFFFFF;
		y++;
	}
	x = 0;
	y = env->screen_w / 2;
	while (x < env->screen_h)
	{
		env->img->addr[y * env->img->size_l / 4 + x] = 0xFFFFF;
		x++;
	}
	mlx_put_image_to_window(env->mlx->mlx_ptr, env->mlx->win, env->img->img_ptr, 0, 0);
	return (0);
}

int	ft_render_mandelbrot(t_env *env)
{

	ft_render_axis(env);
	return (0);
}

double	*ft_mult_complex(t_env *env, double *z2)
{
	double *res;
	double res_r;
	double res_i;

	res_r = env->z->r * z2[0] - env->z->i * z2[1];
	res_i = env->z->i * z2[0] + env->z->r * z2[1];
	res = ft_calloc(2, sizeof(double));
	res[0] = res_r;
	res[1] = res_i;
	free(res);
	return (res);
}


double	*ft_add_complex(t_env *env, double *z2)
{
	double *res;
	double res_r;
	double res_i;

	res_i = env->z->i + z2[1];
	res_r = env->z->r + z2[0];
	res = ft_calloc(2, sizeof(double));
	res[0] = res_r;
	res[1] = res_i;
	free(res);
	return (res);
}

int	ft_calcul_mandelbrot(t_env *env)
{
	double *z2;
	double *new;

	z2 = ft_calloc(2, sizeof(double));
	new = ft_calloc(2, sizeof(double));
	z2[0] = 5;
	z2[1] = 3;
	env->z = ft_calloc(1, sizeof(t_complex));
	env->z->r = 4;
	env->z->i = -2;
//	new = ft_add_complex(env, z2);
	new = ft_mult_complex(env, z2);
	ft_putnbr_fd(new[0], 1);
	ft_putstr_fd("+",1);
	ft_putnbr_fd(new[1], 1);
	ft_putstr_fd("\n",1);
	ft_render_mandelbrot(env);
	return (0);
}

int	ft_mandelbrot_loop(t_env *env)
{
	ft_key_event(env);
	ft_calcul_mandelbrot(env);
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
