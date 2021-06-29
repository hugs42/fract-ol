/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:40:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 13:02:57 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_key_press(int key, t_env *env)
{
	if (key == KEY_EXIT)
		env->event->exit = 1;
	return (0);
}

int	ft_key_release(int key, t_env *env)
{

	return (0);
}

int	ft_key_event(t_env *env)
{
	if (env->event->exit == 1)
		ft_exit(env);
	return (0);
}
