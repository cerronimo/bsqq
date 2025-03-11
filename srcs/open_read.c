/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:25:08 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:51:37 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	open_and_read_file(char *filename, char *buffer)
{
	int	fd;
	int	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buffer, MAX_SIZE * MAX_SIZE - 1);
	close(fd);
	if (bytes_read <= 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (atoi(buffer));
}
