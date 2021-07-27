/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:42:59 by hugsbord          #+#    #+#             */
/*   Updated: 2021/07/27 13:03:55 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_launch_fractol(t_env *env, int fract)
{
	if (fract == 1)
		env->fract = 1;
	else if (fract == 2)
		env->fract = 2;
	else if (fract == 3)
		env->fract = 3;
	ft_fractol(env);
	return (0);
}

int	ft_check_arg(char *arg)
{
	if (((ft_strncmp(arg, "Julia", 5) == 0) && (ft_strlen(arg) == 5))
		|| ((ft_strncmp(arg, "julia", 5) == 0) && (ft_strlen(arg) == 5)))
		return (1);
	else if (((ft_strncmp(arg, "Mandelbrot", 10) == 0) && (ft_strlen(arg)
				== 10)) || ((ft_strncmp(arg, "mandelbrot", 10) == 0)
			&& (ft_strlen(arg) == 10)))
		return (2);
	else if (((ft_strncmp(arg, "Burning_ship", 12) == 0) && (ft_strlen(arg)
				== 12)) || ((ft_strncmp(arg, "burning_ship", 12) == 0)
			&& (ft_strlen(arg) == 12)))
		return (3);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fract;
	t_env	env;

	fract = 0;
	if (argc != 2)
		ft_exit_arg();
	else
	{
		fract = ft_check_arg(argv[1]);
		if (fract != 1 && fract != 2 && fract != 3)
			ft_exit_arg();
		else
		{
			ft_init(&env, fract);
			ft_launch_fractol(&env, fract);
		}
	}
	return (0);
}
