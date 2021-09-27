/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:22:26 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/27 12:24:45 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_julia_setting(t_env *env)
{
	env->y = 1.5 * (env->row - env->screen_h / 2.0) / (0.5 * env->zoom
			* env->screen_h) + env->move_x;
	env->x = (env->col - env->screen_h / 2.0) / (0.5 * env->zoom
			* env->screen_h) + env->move_y;
	return (0);
}

int	ft_setting(t_env *env)
{
	env->x = 0.0;
	env->y = 0.0;
	env->z_re = (env->col - env->screen_w / 2.0) * 4.0 / env->screen_w
		* env->zoom + env->move_x;
	env->z_im = (env->row - env->screen_h / 2.0) * 4.0 / env->screen_w
		* env->zoom + env->move_y;
	return (0);
}

int	ft_define_complex(t_env *env)
{
	double	x_new;

	x_new = 0.0;
	env->iter = 0;
	if (env->fract == 1)
		ft_julia_setting(env);
	else if (env->fract == 2 || env->fract == 3 || env->fract == 4)
		ft_setting(env);
	env->c_re = env->x;
	env->c_im = env->y;
	return (0);
}

int	ft_iter(t_env *env)
{
	env->new_c_re = 0.0;
	env->new_c_im = 0.0;
	ft_define_complex(env);
	while (env->iter < env->iter_max && (env->c_re * env->c_re
			+ env->c_im * env->c_im) < 4)
	{
		if (env->fract == MULTI)
			env->new_c_re = (env->c_re * env->c_re * env->c_re) - 3
				* (env->c_re * env->c_im * env->c_im) + env->z_re;
		else
			env->new_c_re = (env->c_re * env->c_re) - (env->c_im * env->c_im)
				+ env->z_re;
		if (env->fract == BURNING)
			env->new_c_im = fabs(2 * env->c_re * env->c_im) + env->z_im;
		else if (env->fract == MULTI)
			env->new_c_im = (3 * env->c_re * env->c_re) * env->c_im
				- (env->c_im * env->c_im * env->c_im) + env->z_im;
		else
			env->new_c_im = (2 * env->c_re * env->c_im) + env->z_im;
		env->c_im = env->new_c_im;
		env->c_re = env->new_c_re;
		env->iter++;
	}
	return (env->iter);
}
