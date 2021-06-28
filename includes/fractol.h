/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:40 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/28 12:08:50 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "./../libft/libft.h"

# define ERROR -1

typedef struct		s_event
{
	int				exit;
}					t_event;

typedef struct		s_img
{
	int				*addr;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	void			*img_ptr;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			*mlx;
	t_img			*img;
	t_event			*event;
}					t_env;

int		ft_init_fractol(t_env *env, int fract);
int		ft_init_env(t_env *env, int fract);
void	ft_init_mlx(t_env *env);
void	ft_init_img(t_env *env);
void	ft_init_event(t_env *env);
int		check_arg(char *arg);
int		exit_arg(void);

#endif
