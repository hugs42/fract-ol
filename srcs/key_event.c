/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:40:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/20 11:59:28 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_color_scheme(t_env *env, int key)
{
	static	int	i;

	i = 0;
	if (key == NEXT_COLOR)
		env->color += 0xfff;
	else if (key == LAST_COLOR)
		env->color -= 0xfff;
	i++;
	if (i == 13)
	{
		env->color = 0x00003F;
		i = 0;
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


int	ft_mouse_hook(t_env *env)
{

	return (0);
}

int	ft_key_event(t_env *env)
{
	if (env->event->exit == 1)
		ft_exit(env);
	return (0);
}
