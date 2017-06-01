/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamoure <mlamoure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:54:40 by mlamoure          #+#    #+#             */
/*   Updated: 2017/05/16 18:34:06 by mlamoure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	ft_segment(void *mlx, void *win, int xi, int yi, int xf, int yf)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	cumul = dx / 2;
	for (x = xi + 1 ; x <= xf; x++)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y += 1;
		}
	mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	}
	mlx_loop(mlx);
}

int		main()
{
	void *mlx;
	void *win;
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;

	x1 = 100;
	y1 = 100;
	x2 = 300;
	y2 = 300;
	x3 = 100;
	y3 = 300;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Bonjour je fais un trait");
	ft_segment(mlx, win, x1, y1, x2, y2);
	ft_segment(mlx, win, x1, y1, x3, y3);
	ft_segment(mlx, win, x2, y2, x3, y3);
}
