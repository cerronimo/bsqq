#ifndef BSQ_H
# define BSQ_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct s_data
{
	int	x;
	int	y;
	int	size;
}				t_data;


int		is_valid_square(char map[MAX_SIZE][MAX_SIZE], int x, int y, int size, int max_size);
void	find_largest_square_brute(char map[MAX_SIZE][MAX_SIZE], int size);
void	print_map(char map[MAX_SIZE][MAX_SIZE], int size);
int		read_map_from_file(char *filename, char map[MAX_SIZE][MAX_SIZE]);
#endif
 