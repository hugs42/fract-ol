/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:40 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/29 11:26:49 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "./../libft/libft.h"

# define ERROR -1
# define WIN_W 400
# define WIN_H 400
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 53
# define NEXT_COLOR 13
# define LAST_COLOR 1
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define SPACE 49
//# define ARROW_UP 119
//# define ARROW_DOWN 115
//# define ARROW_LEFT 97
//# define ARROW_RIGHT 100
# define JULIA 1
# define MANDEL 2
# define BURNING 3
# define MULTI 4

typedef struct s_img
{
	int				*addr;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	void			*img_ptr;
}					t_img;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win;
}					t_mlx;

typedef struct s_env
{
	t_mlx			*mlx;
	t_img			*img;
	double			x;
	double			y;
	int				row;
	int				col;
	int				iter;
	int				iter_max;
	int				color;
	int				color_cardioid;
	int				screen_w;
	int				screen_h;
	double			z_re;
	double			z_im;
	double			c_re;
	double			c_im;
	double			new_z_re;
	double			new_z_im;
	double			move_x;
	double			move_y;
	double			zoom;
	int				fract;
}					t_env;

int		ft_init(t_env *env);
int		ft_init_fractol(t_env *env);
int		ft_init_env(t_env *env);
int		ft_launch_fractol(t_env *env, int fract);
void	ft_init_mlx(t_env *env);
void	ft_init_img(t_env *env);
int		ft_init_julia(t_env *env);
int		ft_check_arg(char *arg);
int		ft_calcul_fractol(t_env *env);
int		ft_key_press(int key, t_env *env);
int		ft_mouse_hook(int key, int x, int y, t_env *env);
int		ft_mouse_julia(int x, int y, t_env *env);
int		ft_jul_mouse_hook(int key, int x, int y, t_env *env);
int		ft_jul_key_press(int key, t_env *env);
int		ft_setting(t_env *env);
int		ft_julia_setting(t_env *env);
int		ft_fractol(t_env *env);
int		ft_iter(t_env *env);
void	ft_refresh_screen(t_env *env);
int		ft_color_scheme(t_env *env, int key);
int		ft_color(t_env *env);
int		ft_exit_arg(void);
int		ft_exit(t_env *env);

#endif
