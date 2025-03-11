/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:49:05 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:49:11 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	parse_map_content(char *ptr, char map[MAX_SIZE][MAX_SIZE], int size)
{
	int	i;
	int	j;

	i = 0;
	while (*ptr && i < size)
	{
		j = 0;
		while (*ptr != '\n' && j < size)
		{
			if (*ptr != '.' && *ptr != 'o')
				return (-1);
			map[i][j] = *ptr;
			j++;
			ptr++;
		}
		i++;
		ptr++;
	}
	return (size);
}
