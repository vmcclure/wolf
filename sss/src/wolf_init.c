/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:36:04 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/30 19:24:19 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdio.h"
static void		put_ray(t_mlx *mlx, float dist, int x, char c)
{
	t_line	line;
	int	height;

	if (dist < 0)
		dist *= -1;
	line.x0 = x;
	line.x1 = x;
	height = (float)mlx->y / (dist * 0.01);
	if (height > mlx->y)
		height = mlx->y;
	line.y0 = (mlx->y - height) / 2;
	line.y1 = line.y0 + height;
//	printf("%f\n", height);///////////////////////////////////////////////////
	if (dist > 230)
		dist = 230;
	if (c == '2')
	{
		line.clr0 = 0xFF - (0x01 * (int) dist);
		line.clr1 = 0xff - (0x01 * (int) dist);
	}
	else if (c == '3')
    {
        line.clr0 = 0xFF0000 - (0x010000 * (int)dist);
        line.clr1 = 0xff0000 - (0x010000 * (int)dist);
    }
	else
    {
	    line.clr0 = 0xFFFFFF - (0x010101 * (int)dist);
	    line.clr1 = 0xffffff - (0x010101 * (int)dist);
    }

	put_line(mlx, line);
}

static void		*distance_init(t_thredsct *sct)
{
	float	start_rad;
	float	radpp;
	int		x_map;
	int		y_map;
	float		step;

	start_rad = -(30 * M_PI / 180);
	radpp = (50 * M_PI / 180) / sct->mlx->x;
	while (++sct->startx < sct->maxx)
	{
		step = 0;
		x_map = sct->mlx->player.x + step *
				cos(sct->mlx->player.angle + start_rad + (sct->startx * radpp));
		y_map = sct->mlx->player.y + step *
				sin(sct->mlx->player.angle + start_rad + (sct->startx * radpp));
		while (sct->mlx->map[y_map / SIZE][x_map / SIZE] == ' ' ||
                sct->mlx->map[y_map / SIZE][x_map / SIZE] == 'p')
		{
			step += 0.1;
			x_map = sct->mlx->player.x + step * cos(sct->mlx->player.angle
					+ start_rad + (sct->startx * radpp));
			y_map = sct->mlx->player.y + step * sin(sct->mlx->player.angle
					+ start_rad + (sct->startx * radpp));
		}
		put_ray(sct->mlx, step * cos(start_rad + (sct->startx * radpp)),
				sct->startx, sct->mlx->map[y_map / SIZE][x_map / SIZE]);
	}
	return (0);
}

static void		set_aim(t_mlx *mlx)
{
	t_line line;

	line.x0 = 498;
	line.x1 = 498;
	line.y0 = 397;
	line.y1 = 402;
	line.clr0 = 0xff00;
	line.clr1 = 0xff00;
	put_line(mlx, line);
	line.x0 = 499;
	line.x1 = 499;
	line.y0 = 397;
	line.y1 = 402;
	line.clr0 = 0xff00;
	line.clr1 = 0xff00;
	put_line(mlx, line);
	line.x0 = 496;
	line.x1 = 501;
	line.y0 = 399;
	line.y1 = 399;
	line.clr0 = 0xff00;
	line.clr1 = 0xff00;
	put_line(mlx, line);
	line.x0 = 496;
	line.x1 = 501;
	line.y0 = 400;
	line.y1 = 400;
	line.clr0 = 0xff00;
	line.clr1 = 0xff00;
	put_line(mlx, line);
}

void			wolf_init(t_mlx *mlx)
{
    pthread_t	threads[10];
    t_thredsct	sct[10];
    int			i;

	clear_image(mlx);

    i = -1;
	while (++i < 10)
	{
		sct[i].mlx = mlx;
		sct[i].startx = -1 + 100 * i;
		sct[i].maxx = sct[i].startx + 101;
		pthread_create(&threads[i], 0, (void *)distance_init, (void *)&sct[i]);
	}
	i = -1;
	while (++i < 10)
		pthread_join(threads[i], 0);



	set_aim(mlx);



	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
