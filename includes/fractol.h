/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:40 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/30 16:39:33 by hugsbord         ###   ########.fr       */
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
# define WIN_W 600
# define WIN_H 600
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 53
# define ITER_MAX 150
	
typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_mandel
{
	int				old_x;
	int				old_y;
}					t_mandel;

typedef struct		s_julia
{
	int				old_x;
	int				old_y;
}					t_julia;

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
	t_complex		*z;
	int				x;
	int				y;
	int				iter;
	int				col;
	int				screen_w;
	int				screen_h;
	double			move_x;
	double			move_y;
	double			zoom;
}					t_env;

int		ft_init_fractol(t_env *env, int fract);
int		ft_init_env(t_env *env, int fract);
void	ft_init_mlx(t_env *env);
void	ft_init_img(t_env *env);
void	ft_init_event(t_env *env);
int		ft_check_arg(char *arg);
int		ft_get_size_screen(t_env *env);
int		ft_key_press(int key, t_env *env);
int		ft_key_release(int key, t_env *env);
int		ft_mouse_hook(t_env *env);
int		ft_key_event(t_env *env);
int		ft_julia(t_env *env);
int		ft_init_julia(t_env *env, t_julia *julia);
int		ft_julia_loop(t_env *env);
int		ft_mandelbrot(t_env *env);
int		ft_init_mandelbrot(t_env *env);
int		ft_mandelbrot_loop(t_env *env);
int		ft_exit_arg(void);
int		ft_exit(t_env *env);

#endif
