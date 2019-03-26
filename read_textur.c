/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:21:51 by vmcclure          #+#    #+#             */
/*   Updated: 2019/03/26 15:29:29 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/SDL2/SDL.h"
#include <stdio.h>
#include <fcntl.h>
#include "wolf.h"
#include <math.h>
#include "libft/libft.h"

t_texture	readbmp(char *filename)
{
	t_texture		texture;
	int				i;
	int				fd;
	unsigned char	info;

	i = 0;
	fd = open(filename, O_RDONLY);
	read(fd, &texture.hdbmp, 54);
	texture.width = *(int *)&texture.hdbmp.a[6];
	texture.height = *(int *)&texture.hdbmp.a[10];
	texture.bpp = texture.hdbmp.a[16];
	close(fd);
	fd = open(filename, O_RDONLY);
	while (i < texture.hdbmp.bfOffBits)
	{
		read(fd, &info, 1);
		i++;
	}
	texture.pixels = (unsigned char *)malloc(texture.hdbmp.a[16] *
	texture.width * texture.height);
	read(fd, texture.pixels, texture.hdbmp.a[16] * texture.width *
	texture.height);
	close(fd);
	return (texture);
}
