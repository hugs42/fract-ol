/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:14:14 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/27 22:19:40 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int		exit_arg(void)
{
	ft_putstr_fd("Usage: ./fractol [fractal]\n", 1);
	ft_putstr_fd("Available fractals :\n - Julia\n - Mandelbrot\n", 1);
	exit(0);
}
