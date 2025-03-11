/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:59:55 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:43:39 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	is_valid_square(char map[MAX_SIZE][MAX_SIZE], t_data squ, int max_size)
{
	int	i;
	int	j;

	if (squ.x + squ.size > max_size || squ.y + squ.size > max_size)
		return (0);
	i = squ.x;
	while (i < squ.x + squ.size)
	{
		j = squ.y;
		while (j < squ.y + squ.size)
		{
			if (map[i][j] == 'o')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	update_max_square(int x, int y, int current_size, t_square *max_squ)
{
	if (current_size > max_squ->size)
	{
		max_squ->size = current_size;
		max_squ->x = x;
		max_squ->y = y;
	}
}
void	print_map(char map[MAX_SIZE][MAX_SIZE], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
int	get_map_size_from_stdin(void)
{
	char	buffer[1024];

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		return (-1);
	return (atoi(buffer));
}
void	process_map(char map[MAX_SIZE][MAX_SIZE], int size)
{
	if (size == -1)
		write(2, "map error\n", 10);
	else
	{
		find_largest_square_brute(map, size);
		print_map(map, size);
	}
}
int	main(int argc, char **argv)
{
	char map[MAX_SIZE][MAX_SIZE];
	int i;

	if (argc == 1)
		process_map(map, read_map_from_stdin(map));
	else
	{
		i = 1;
		while (i < argc)
		{
			process_map(map, read_map_from_file(argv[i], map));
			if (i++ < argc - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
