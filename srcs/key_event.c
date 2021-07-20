/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:40:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/20 21:22:46 by hugsbord         ###   ########.fr       */
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
		env->color = 0x0fff909;
	else if (i == 9)
		env->color = 0x23fff;
	return (0);
}

int	ft_color_scheme(t_env *env, int key)
{
	static	int	i = 0;

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
		env->event->exit = 1;
	if (key == NEXT_COLOR || key == LAST_COLOR)
		ft_color_scheme(env, key);
	return (0);
}

int	ft_key_release(int key, t_env *env)
{

	return (0);
}


int	ft_mouse_hook(int key, int x, int y, t_env *env)
{
	if (key == 4)
	{
		env->zoom *= 0.5;
		if (x == 1000)
			env->x = 100;
		else if (y == 1000)
			env->y = 100;
	}
	if (key == 5)
		env->zoom /=  0.5;
	return (0);
}

int	ft_key_event(t_env *env)
{
	if (env->event->exit == 1)
		ft_exit(env);
	return (0);
}
