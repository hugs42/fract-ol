/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:22:26 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/28 16:26:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_julia_setting(t_env *env)
{
	env->x = (env->row - env->screen_w / 2.0) / (0.5 * env->zoom
			* env->screen_w) + env->move_x;
	env->y = (env->col - env->screen_w / 2.0) / (0.5 * env->zoom
			* env->screen_w) + env->move_y;
	env->z_re = env->y;
	env->z_im = env->x;
	return (0);
}

int	ft_setting(t_env *env)
{
	env->x = 0.0;
	env->y = 0.0;
	env->c_re = (env->col - env->screen_w / 2.0) * 4.0 / env->screen_w
		* env->zoom + env->move_x;
	env->c_im = (env->row - env->screen_h / 2.0) * 4.0 / env->screen_w
		* env->zoom + env->move_y;
	env->z_re = env->y;
	env->z_im = env->x;
	return (0);
}

int	ft_define_complex(t_env *env)
{
	env->iter = 0;
	if (env->fract == 1)
		ft_julia_setting(env);
	else if (env->fract == 2 || env->fract == 3 || env->fract == 4)
		ft_setting(env);
	return (0);
}

int	ft_iter(t_env *env)
{
	env->new_z_re = 0.0;
	env->new_z_im = 0.0;
	ft_define_complex(env);
	while (env->iter < env->iter_max && (env->z_re * env->z_re
			+ env->z_im * env->z_im) < 4)
	{
		if (env->fract == MULTI)
			env->new_z_re = (env->z_re * env->z_re * env->z_re) - 3
				* (env->z_re * env->z_im * env->z_im) + env->c_re;
		else
			env->new_z_re = (env->z_re * env->z_re) - (env->z_im * env->z_im)
				+ env->c_re;
		if (env->fract == BURNING)
			env->new_z_im = fabs(2 * env->z_re * env->z_im) + env->c_im;
		else if (env->fract == MULTI)
			env->new_z_im = (3 * env->z_re * env->z_re) * env->z_im
				- (env->z_im * env->z_im * env->z_im) + env->c_im;
		else
			env->new_z_im = (2 * env->z_re * env->z_im) + env->c_im;
		env->z_re = env->new_z_re;
		env->z_im = env->new_z_im;
		env->iter++;
	}
	return (env->iter);
}
