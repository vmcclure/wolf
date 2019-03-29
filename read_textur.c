/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:21:51 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/29 15:25:22 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
#include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

void				skip_bit(unsigned short bit, int *fd)
{
	int				i;
	unsigned char	info;

	i = 0;
	while (i < bit)
	{
		read(*fd, &info, 1);
		i++;
	}
}

t_texture			readbmp(char *filename)
{
	t_texture		texture;
	int				fd;

	fd = open(filename, O_RDONLY);
	read(fd, &texture.hdbmp, 54);
	texture.width = *(int *)&texture.hdbmp.a[6];
	texture.height = *(int *)&texture.hdbmp.a[10];
	texture.bpp = texture.hdbmp.a[16];
	close(fd);
	fd = open(filename, O_RDONLY);
	skip_bit(texture.hdbmp.bfOffBits, &fd);
	if (!(texture.pixels = (unsigned char *)malloc(texture.hdbmp.a[16] *
	texture.width * texture.height)))
	{
		texture.fail = 0;
		return (texture);
	}
	read(fd, texture.pixels, texture.hdbmp.a[16] * texture.width *
	texture.height);
	close(fd);
	//printf ("%d\n", texture.hdbmp.bfSize);
	texture.fail = 1;
	return (texture);
}
