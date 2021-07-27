/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:40:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/27 16:41:57 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_select_color(t_env *env, int i)
{
	if (i == 0)
		env->color = 0x00003f;
	if (i == 1)
		env->color = 0x08cc0;
	else if (i == 2)
		env->color = 0xbb32f;
	else if (i == 3)
		env->color = 0x800080;
	else if (i == 4)
		env->color = 0x42fdddf;
	else if (i == 5)
		env->color = 0xccc;
	else if (i == 6)
		env->color = 0x42ff;
	else if (i == 7)
		env->color = 0xcccc29;
	else if (i == 8)
		env->color = 0xc09ff9;
	else if (i == 9)
		env->color = 0x23fff;
	return (0);
}

int	ft_color_scheme(t_env *env, int key)
{
	static int	i = 0;

	if (i == 9)
		i = -1;
	if (key == NEXT_COLOR)
	{
		i++;
		ft_select_color(env, i);
	}
	else if (key == LAST_COLOR && i != 0)
	{
		i--;
		ft_select_color(env, i);
	}
	return (0);
}

int	ft_key_press(int key, t_env *env)
{
	if (key == KEY_EXIT)
		ft_exit(env);
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

int	ft_mouse_hook(int key, int x, int y, t_env *env)
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
		env->zoom /= 0.9;
	return (0);
}
