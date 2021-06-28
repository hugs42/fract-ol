/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:42:59 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/28 12:11:00 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int		ft_fractol(t_env env, int fract)
{

	return (0);
}

int		check_arg(char *arg)
{
	if ((ft_strncmp(arg, "Julia", 5) == 0) && (ft_strlen(arg) == 5))
		return (1);
	else if ((ft_strncmp(arg, "Mandelbrot", 10) == 0) && (ft_strlen(arg) == 10))
		return (2);
	return (0);
}

int		main(int argc, char **argv)
{
	int fract;
	t_env	env;

	fract = 0;
	if (argc != 2)
		exit_arg();
	else
	{
		fract = check_arg(argv[1]);
		if (fract != 1 && fract != 2)
			exit_arg();
		else
		{
			ft_init_fractol(&env, fract);
			ft_fractol(env, fract);
		}
	}
	return (0);
}
