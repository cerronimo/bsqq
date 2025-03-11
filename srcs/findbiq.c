/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbiq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:33:18 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:33:59 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	find_largest_square_brute(char map[MAX_SIZE][MAX_SIZE], int size)
{
	int		x;
	int		y;
	t_data	squ;
	t_data	max_squ;

	max_squ = (t_data){0, 0, 0};
	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			if (map[x][y] == '.')
			{
				squ = (t_data){x, y, 1};
				while (is_valid_square(map, squ, size))
				{
					if (squ.size > max_squ.size)
						max_squ = squ;
					squ.size++;
				}
			}
		}
	}
	mark_largest_square(map, max_squ.x, max_squ.y, max_squ.size);
}
