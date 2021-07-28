/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:22:26 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/28 16:15:20 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_julia_setting(t_env *env)
{
	env->x = 1.0 * (env->row - env->screen_w / 2.0) / (0.5 * env->zoom
			* env->screen_w) + env->move_x;
	env->y = 1.0 * (env->col - env->screen_h / 2.0) / (0.5 * env->zoom
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

	env->x = 0.0;
	env->y = 0.0;
	x_new = 0.0;
	env->iter = 0;
	if (env->fract == 1)
		ft_julia_setting(env);
	else if (env->fract == 2 || env->fract == 3 || env->fract == 4)
		ft_setting(env);
	return (0);
}

int	ft_iter(t_env *env)
{
	double	x_new;

	x_new = 0.0;
	ft_define_complex(env);
	while (env->iter < env->iter_max && env->x * env->x + env->y * env->y <= 4)
	{
		if (env->fract == MULTI)
			x_new = (env->x * env->x * env->x) - 3 * (env->x * env->y
				* env->y) + env->z_re;
		else
			x_new = (env->x * env->x) - (env->y * env->y) + env->z_re;
		if (env->fract == BURNING)
			env->y = fabs(2 * env->x * env->y) + env->z_im;
		else if (env->fract == MULTI)
			env->y = 3 * (env->x * env->x) * env->y - (env->y * env->y
					* env->y) + env->z_im;
		else
			env->y = 2 * (env->x * env->y) + env->z_im;
		env->x = x_new;
		env->iter++;
	}
	return (env->iter);
}
