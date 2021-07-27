/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:53:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/27 13:02:23 by hugsbord         ###   ########.fr       */
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
