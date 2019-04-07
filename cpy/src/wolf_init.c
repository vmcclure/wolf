/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:36:04 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/07 20:55:29 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

static	void	mnogo_strok(int x, int y, t_texture *text, t_mlx *mlx)
{
	int			k;

	if (mlx->anim > 4 || mlx->anim < 0)
		mlx->anim = 0;
	k = mlx->anim;
	if (text[mlx->anim].pixels[x / 2 * 4 + (text[k].height - y / 2 - 1)
		* text[k].width * 4 + 0] == 255 && text[k].pixels[x / 2 * 4
		+ (text[k].height - y / 2 - 1) * text[k].width * 4 + 1] == 255
		&& text[k].pixels[x / 2 * 4 + (text[k].height - y / 2 - 1)
		* text[k].width * 4 + 2] == 255)
		x++;
	else
	{
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 0] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 0];
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 1] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 1];
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 2] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 2];
		x++;
	}
}

static	void	put_pistol(t_mlx *mlx)
{
	t_texture	text[5];
	int			x;
	int			y;

	text[0] = readbmp("./text/0/shotgun1.bmp");
	text[1] = readbmp("./text/0/shotgun2.bmp");
	text[2] = readbmp("./text/0/shotgun3.bmp");
	text[3] = readbmp("./text/0/shotgun4.bmp");
	text[4] = readbmp("./text/0/shotgun5.bmp");
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			mnogo_strok(x, y, text, mlx);
			x++;
		}
		y++;
	}
}

static void		floor_ceiling(t_mlx *mlx)
{
	int	y;
	int x;

	y = -1;
	while (++y < mlx->y / 2)
	{
		x = -1;
		while (++x < mlx->x)
		{
			set_pxl(mlx->img_data, x * 4,
					y * mlx->size_line, 0x61c3ff);
		}
	}
	y = mlx->y / 2;
	while (++y < mlx->y)
	{
		x = -1;
		while (++x < mlx->x)
		{
			set_pxl(mlx->img_data, x * 4,
					y * mlx->size_line, 0x808080);
		}
	}
}

void			wolf_init(t_mlx *mlx)
{
	pthread_t	threads[10];
	t_thredsct	sct[10];
	int			i;

	clear_image(mlx);
	floor_ceiling(mlx);
	i = -1;
	while (++i < 10)
	{
		sct[i].mlx = mlx;
		sct[i].startx = -1 + 100 * i;
		sct[i].maxx = sct[i].startx + 101;
		pthread_create(&threads[i], 0, (void *)distance_init,
				(void *)&sct[i]);
	}
	i = -1;
	while (++i < 10)
		pthread_join(threads[i], 0);
	put_textur(mlx);
	put_pistol(mlx);
	minimap(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
