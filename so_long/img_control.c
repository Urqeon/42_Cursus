/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulut <abulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:38:01 by abulut            #+#    #+#             */
/*   Updated: 2023/10/22 01:50:27 by abulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "stdio.h"

void	gate_control(void)
{
	int	fd;

	fd = open("images/gate.xpm", O_RDONLY);
	if (fd < 0)
		err_msg("xpm not found!");
	close(fd);
}

void	player_control(void)
{
	int	fd;

	fd = open("images/player.xpm", O_RDONLY);
	if (fd < 0)
		err_msg("xpm not found!");
	close(fd);
}

void	road_control(void)
{
	int	fd;

	fd = open("images/road.xpm", O_RDONLY);
	if (fd < 0)
		err_msg("xpm not found!");
	close(fd);
}

void	sea_control(void)
{
	int	fd;

	fd = open("images/sea.xpm", O_RDONLY);
	if (fd < 0)
		err_msg("xpm not found!");
	close(fd);
}

void	worm_control(void)
{
	int	fd;

	fd = open("images/worm.xpm", O_RDONLY);
	if (fd < 0)
		err_msg("xpm not found!");
	close(fd);
}
