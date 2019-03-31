/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:03:38 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/31 15:58:26 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main()
{
	int		i;
	t_mlx	mlx;
	int fd;

	fd = open("maps/map", O_RDONLY);
	i = get_map(fd, &mlx.map);
	close(fd);
	if (i <= 0)
	{
		if (i == 0)
			ft_putstr("error valid map file\n");
		else if (i == -1)
			ft_putstr("error malloc\n");
		else if (i == -2)
			ft_putstr("error read file\n");
		return (0);
	}
	wolf3d(&mlx);
	return (0);
}
