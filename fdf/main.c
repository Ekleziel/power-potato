/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skherif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:41:23 by skherif           #+#    #+#             */
/*   Updated: 2017/05/29 11:50:59 by mlamoure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

void				ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (n > 0)
	{
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
}

void                ft_line(void *mlx, void *win , int x, int y, int x_b, int y_b);

int		main(int ac, char **av)
{
	int		fd;
	int		nb_word;
	int		nb_lign;
	char	c;
	int		flag;
	int		flag2;
	int		flag3;
	int		**map;
	int		i;
	char *tmp;
	int		x;
	int		y;
	int		flag4;

	flag4 = 0;
	x = 0;
	y = 0;
	i = 0;
	flag2 = 0;
	flag = 0;
	fd = open(av[1], O_RDONLY);
	while (read(fd, &c, 1) != 0)
	{
		if (flag == 0 && flag2 == 0 && c != ' ' && c != '-')
		{
			nb_word++;
			flag2 = 1;
		}
		if (c == ' ')
			flag2 = 0;
		if (c == '\n')
		{
			nb_lign++;
			flag = 1;
			flag2 = 0;
		}
	}
	printf("word ==== %d lign ==== %d", nb_word, nb_lign);
	map = malloc(sizeof(int *) * (nb_lign + 1));
	while (i != nb_lign + 1)
	{
		map[i] = malloc(sizeof(int) * nb_word + 1);
		map[i][nb_word + 1] = 897654;
		i++;
	}
//	map[nb_lign + 1] = NULL;
	close(fd);
	fd = open(av[1], O_RDONLY);
	tmp = malloc(4096);
	while (read(fd, &c, 1))
	{
		if (c != ' ')
		{
			if (flag4 == 0)
			{
				flag4 = 1;
				printf("x ==== %d    y ==== %d\n", x, y);
				y++;
			}
			flag3 = 0;
			tmp[i++] = c;
		}
		if (c == '\n')
			{
				y = 0;
				x++;
			}
		if ((c == ' ' || c == '\n') && flag3 == 0)
		{
			flag4 = 0;
			map[x][y] = atoi(tmp);
			printf("tmp === %s\n", tmp);
			flag3 = 1;
			ft_bzero(tmp, 50);
			i = 0;
				}
	}
	x = 0;
	y = 0;

	void	*mlx;
	void	*win;
	int		tmx;
	int		tmy;

	tmx = 0;
	tmy = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 1200, "42");
	while(y != nb_lign)
	{
		while(x != nb_word)
		{
			if (x != 0)
				ft_line(mlx, win, 50 + x * 20 + y * 20,
						500 + y * 10 - x * 10 - map[y][x] * 10, tmx, tmy);
			if (y != 0)
				ft_line(mlx, win, 50 + x * 20 + y * 20, 500 + y * 10 - x * 10 - map[y][x] * 10, 50 + x * 20 + (y - 1) * 20, 500 + (y - 1) * 10 - x * 10 - map[y - 1][x] * 10);
			tmx = 50 + x * 20 + y * 20;
			tmy = 500 + y * 10 - x * 10 - map[y][x] * 10;
			//mlx_pixel_put(mlx, win, 50 + x * 20 + y * 20, 500 + y * 10 - x * 10, 0xFFFFFF);
			x++;
		}
		x = 0;
		y++;
		}
	mlx_loop(mlx);
}


void                ft_line(void *mlx, void *win , int x, int y, int x_b, int y_b)
{
	int dh;
	int dl;
	int c;
	int m;

	dh = x_b - x;
	dl = y_b - y;
	c = -1;
	m = abs(dh) > abs(dl) ? abs(dh) : abs(dl);
	while (++c < m)
		mlx_pixel_put(mlx, win,  x + c * dh / m, y + c * dl / m, 0xffffff);
}

















