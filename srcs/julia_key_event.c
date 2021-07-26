/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_key_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:29:30 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/26 10:08:54 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_jul_key_press(int key, t_env *env)
{
	if (key == KEY_EXIT)
		env->event->exit = 1;
	else if (key == NEXT_COLOR || key == LAST_COLOR)
		ft_color_scheme(env, key);
	else if (key == ARROW_UP)
		env->move_y -= 0.05 * env->zoom;
	else if (key == ARROW_DOWN)
		env->move_y += 0.05 * env->zoom;
	else if (key == ARROW_RIGHT)
		env->move_x += 0.05 * env->zoom;
	else if (key == ARROW_LEFT)
		env->move_x -= 0.05 * env->zoom;
	return (0);
}

int ft_mouse_julia(int x, int y, t_env *env)
{
	if (x > 0 && x < env->screen_w && y > 0 && y < env->screen_h)
	{
		env->z_re = (double)x / env->screen_w * 2 - 1;
		env->z_im = (double)y / env->screen_h * 2 - 1;
	}
	return (0);
}

int	ft_jul_mouse_hook(int key, int x, int y, t_env *env)
{
	if (key == 4)
	{
		env->zoom *= 0.9;
		if (x == 1000)
			env->x = 100;
		else if (y == 1000)
			env->y = 100;
	}
	if (key == 5)
		env->zoom /=  0.9;
	if (key == 1)
	{
		env->z_re = -0.7;
		env->z_im = 0.27015;
	}
	return (0);
}

