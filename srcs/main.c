#include "filem.h"
#include <stdio.h>

int main(int ac, char **av) {
    char **map;
    int size;

    if (ac < 2) {
        printf("Kullanım: ./bsq [harita_dosyası]\n");
        return (1);
    }

    map = read_map(av[1], &size);
    if (!map) {
        printf("Hata: Harita okunamadı!\n");
        return (1);
    }

    printf("Harita boyutu: %d x %d\n", size, size);
    print_map(map, size);

    free_map(map, size);
    return (0);
}
