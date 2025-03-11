/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:32:11 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:42:28 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	read_map_from_file(char *filename, char map[MAX_SIZE][MAX_SIZE])
{
	char	buffer[MAX_SIZE * MAX_SIZE];
	char	*ptr;
	int		size;

	size = open_and_read_file(filename, buffer);
	if (size <= 0 || size > MAX_SIZE)
		return (-1);
	ptr = buffer;
	while (*ptr != '\n' && *ptr)
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (parse_map_content(ptr, map, size));
}
int	read_map_from_stdin(char map[MAX_SIZE][MAX_SIZE])
{
	char buffer[1024];
	char *ptr;
	int size, i, j;

	size = get_map_size_from_stdin();
	if (size <= 0 || size > MAX_SIZE)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
			return (-1);
		ptr = buffer;
		j = 0;
		while (*ptr != '\n' && *ptr)
		{
			if (*ptr == '.' || *ptr == 'o')
				map[i][j++] = *ptr++;
			else
				return (-1);
		}
		i++;
	}
	return (size);
}
