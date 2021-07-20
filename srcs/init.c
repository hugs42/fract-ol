/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:09:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/20 11:38:50 by hugsbord         ###   ########.fr       */
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
	env->event->color = 0;
	env->event->exit = 0;
}

int	ft_init_env(t_env *env, int fract)
{
	env->x = 0;
	env->y = 0;
	env->screen_w = 0;
	env->screen_h = 0;
	env->screen_size = 0.0;
	env->iter = 0;
	env->color = 0;
	env->x_center = 0.0;
	env->y_center = 0.0;
	env->move_x = 0.0;
	env->move_y = 0.0;
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
