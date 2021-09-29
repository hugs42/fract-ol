/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:40:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/29 11:30:35 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_select_color(t_env *env, int i)
{
	if (i == 0)
		env->color = 0xeec;
	else if (i == 1)
		env->color = 0xccc;
	else if (i == 2)
		env->color = 0x3aall;
	else if (i == 3)
		env->color = 0x00003f;
	else if (i == 4)
		env->color = 0x42ff;
	else if (i == 5)
		env->color = 0x42fdddf;
	else if (i == 6)
		env->color = 0x800080;
	else if (i == 7)
		env->color = 0xcba03;
	else if (i == 8)
		env->color = 0xc3d03;
	else if (i == 9)
		env->color = 0xacc29;
	return (0);
}

int	ft_color_scheme(t_env *env, int key)
{
	static int	i = 0;

	if (key == NEXT_COLOR)
	{
		if (i == 9)
			i = -1;
		i++;
		ft_select_color(env, i);
	}
	else if (key == LAST_COLOR)
	{
		i--;
		if (i == -1)
			i = 9;
		ft_select_color(env, i);
	}
	return (0);
}

int	ft_key_press(int key, t_env *env)
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
		env->move_y -= 0.09 * env->zoom;
	else if (key == ARROW_DOWN)
		env->move_y += 0.09 * env->zoom;
	else if (key == ARROW_RIGHT)
		env->move_x += 0.09 * env->zoom;
	else if (key == ARROW_LEFT)
		env->move_x -= 0.09 * env->zoom;
	return (0);
}

int	ft_mouse_hook(int key, int x, int y, t_env *env)
{
	if (key == 4)
	{
		env->zoom *= 0.9;
		env->iter_max += 1;
	}
	if (key == 5)
	{
		if (env->zoom < 1)
			env->zoom /= 0.9;
	}
	return (0);
}
