/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_key_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:29:30 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/29 11:30:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_jul_key_press(int key, t_env *env)
{
	if (key == KEY_EXIT)
		ft_exit(env);
	if (key == NEXT_COLOR || key == LAST_COLOR)
		ft_color_scheme(env, key);
	if (key == SPACE)
	{
		if (env->color_cardioid == 0)
			env->color_cardioid = 1;
		else if (env->color_cardioid == 1)
			env->color_cardioid = 0;
	}
	if (key == ARROW_UP)
		env->move_x -= 0.09 / env->zoom;
	else if (key == ARROW_DOWN)
		env->move_x += 0.09 / env->zoom;
	else if (key == ARROW_RIGHT)
		env->move_y += 0.09 / env->zoom;
	else if (key == ARROW_LEFT)
		env->move_y -= 0.09 / env->zoom;
	return (0);
}

int	ft_mouse_julia(int x, int y, t_env *env)
{
	if (x > 0 && x < env->screen_w && y > 0 && y < env->screen_h)
	{
		env->c_re = (double)x / env->screen_w * 2 - 1;
		env->c_im = (double)y / env->screen_h * 2 - 1;
	}
	return (0);
}

int	ft_jul_mouse_hook(int key, int x, int y, t_env *env)
{
	x = 0;
	y = 0;
	if (key == 4)
		env->zoom /= 0.9 ;
	if (key == 5)
	{
		if (env->zoom > 0.9)
			env->zoom *= 0.9;
	}
	if (key == 1)
	{
		env->c_re = 0.285;
		env->c_im = 0.01;
	}
	return (0);
}
