/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulut <abulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:42:30 by abulut            #+#    #+#             */
/*   Updated: 2023/10/22 01:56:35 by abulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"
#include <unistd.h>
#include "./printf/ft_printf.h"
#include "./minilibx/mlx.h"
#include "stdlib.h"

void	err_msg(char *err)
{
	ft_printf("%s", err);
	exit(0);
}

static void	*ftt_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = c;
		i++;
	}
	return (s);
}

int	exit_point(t_game *data)
{
	int	line;

	line = 0;
	if (data->winpointer)
		mlx_destroy_window(data->mlxpointer, data->winpointer);
	free(data->mlxpointer);
	while (line <= data->map_height - 1)
		free(data->map[line++]);
	free(data->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		err_msg("There should be 1 map!");
	ftt_memset(&data, 0, sizeof(t_game));
	map_control(argv[1], &data);
	map_reading(&data);
	map_processing(&data);
	wall_control(&data);
	data.mlxpointer = mlx_init();
	data.winpointer = mlx_new_window(data.mlxpointer, (data.map_width * 120),
			(data.map_height * 120), "solong");
	images_in_game(&data);
	adding_in_graphics(&data);
	map_bug(&data);
	placeholder(&data, data.x_axis, data.y_axis);
	mlx_key_hook(data.winpointer, controls_working, &data);
	mlx_hook(data.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(data.mlxpointer);
	return (0);
}
