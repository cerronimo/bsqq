/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_largest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:34:49 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:35:18 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	mark_largest_square(char map[MAX_SIZE][MAX_SIZE], int max_x,
	int max_y, int max_size)
{
	int	i;
	int	j;

	i = max_x;
	while (i < max_x + max_size)
	{
		j = max_y;
		while (j < max_y + max_size)
		{
			map[i][j] = 'x';
			j++;
		}
		i++;
	}
}
