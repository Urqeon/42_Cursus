/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulut <abulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:46 by abulut            #+#    #+#             */
/*   Updated: 2023/10/22 01:58:17 by abulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "./libft/libft.h"

void	ber_control(char *map_name)
{
	int	arg_len;

	arg_len = ft_strlen(map_name);
	if (map_name[arg_len - 1] != 'r' || map_name[arg_len - 2] != 'e'
		|| map_name[arg_len - 3] != 'b' || map_name[arg_len - 4] != '.')
		err_msg("Map must have .ber extension!");
}

void	img_control(void)
{
	gate_control();
	player_control();
	road_control();
	sea_control();
	worm_control();
}

void	tmp_control(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		err_msg("Map not found!");
	close(fd);
}

void	map_control(char *map_name, t_game *data)
{
	ber_control(map_name);
	data->maplocation = ft_strjoin("map/", map_name);
	tmp_control(data->maplocation);
	img_control();
}
