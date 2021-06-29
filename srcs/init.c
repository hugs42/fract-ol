/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:09:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 13:12:32 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_init_mlx(t_env *env)
{
	env->mlx = ft_calloc(1, sizeof(t_mlx));
	env->mlx->mlx_ptr = NULL;
	env->mlx->win = NULL;
}

void	ft_init_img(t_env *env)
{
	env->img = ft_calloc(1, sizeof(t_img));
	env->img->img_ptr = NULL;
	env->img->addr = NULL;
	env->img->size_l = 0;
	env->img->bpp = 0;
	env->img->width = 0;
	env->img->height = 0;
}

void	ft_init_event(t_env *env)
{
	env->event = ft_calloc(1, sizeof(t_env));
	env->event->exit = 0;
}

int	ft_init_env(t_env *env, int fract)
{
	ft_init_mlx(env);
	ft_init_img(env);
	ft_init_event(env);
	env->screen_w = WIN_W;
	env->screen_h = WIN_H;
	return (0);
}

int	ft_init_fractol(t_env *env, int fract)
{
	ft_init_env(env, fract);
	env->mlx->mlx_ptr = mlx_init();
	ft_get_size_screen(env);
	return (0);
}
