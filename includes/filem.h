#ifndef FILEM_H
# define FILEM_H


typedef struct s_pivot {
	int	x;
	int	y;
	int	size;
}	t_pivot;


char	**read_map(char *filename, int *size);
void	print_map(char **map, int size);
void	free_map(char **map, int size);
t_pivot	find_largest_square(char **map, int size);
char	**draw_square(char **map, t_pivot pvt);

#endif
