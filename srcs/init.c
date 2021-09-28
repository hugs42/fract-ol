/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:09:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/28 14:41:19 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_init_julia(t_env *env)
{
	if (env->fract == JULIA)
	{
		env->c_re = 0.285;
		env->c_im = 0.01;
		env->zoom = 0.9;
		env->iter_max = 250;
	}
	return (0);
}

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

int	ft_init_env(t_env *env)
{
	env->x = 0.0;
	env->y = 0.0;
	env->col = 0;
	env->row = 0;
	env->c_re = 0.0;
	env->c_im = 0.0;
	env->z_re = 0.0;
	env->z_im = 0.0;
	env->new_z_re = 0.0;
	env->new_z_im = 0.0;
	env->iter = 0;
	env->iter_max = 150;
	env->zoom = 1;
	env->color = 0xeec;
	env->move_x = 0.0;
	env->move_y = 0.0;
	env->fract = 0;
	env->screen_w = WIN_W;
	env->screen_h = WIN_H;
	ft_init_mlx(env);
	ft_init_img(env);
	return (0);
}

int	ft_init(t_env *env)
{
	ft_init_env(env);
	env->mlx->mlx_ptr = mlx_init();
	return (0);
}
