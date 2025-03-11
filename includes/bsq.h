/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceyildir <ceyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:10:48 by ceyildir          #+#    #+#             */
/*   Updated: 2025/03/11 20:45:29 by ceyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MAX_SIZE 1000

typedef struct s_data
{
	int	x;
	int	y;
	int	size;
}				t_data;

typedef struct s_square
{
    int size;
    int x;
    int y;
}   t_square;


int is_valid_square(char map[MAX_SIZE][MAX_SIZE], t_data squ, int max_size);
void	update_max_square(int x, int y, int current_size, t_square *max_squ);
void find_largest_square_brute(char map[MAX_SIZE][MAX_SIZE], int size);
void print_map(char map[MAX_SIZE][MAX_SIZE], int size);
int open_and_read_file(char *filename, char *buffer);
int read_map_from_file(char *filename, char map[MAX_SIZE][MAX_SIZE]);
int get_map_size_from_stdin(void);
int read_map_from_stdin(char map[MAX_SIZE][MAX_SIZE]);
void process_map(char map[MAX_SIZE][MAX_SIZE], int size);
int main(int argc, char **argv);
void mark_largest_square(char map[MAX_SIZE][MAX_SIZE], int max_x, 
	int max_y, int max_size);
t_data check_and_update_square(char map[MAX_SIZE][MAX_SIZE],
		t_data squ, t_data max_squ, int size);
int	parse_map_content(char *ptr, char map[MAX_SIZE][MAX_SIZE], int size);

#endif /* BSQ_H */
