#include "filem.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char **allocate_map(int size) {
    char **map;
    int i;

    map = (char **)malloc(size * sizeof(char *));
    if (!map)
        return NULL;

    for (i = 0; i < size; i++) {
        map[i] = (char *)malloc(size * sizeof(char));
        if (!map[i])
            return NULL;
    }
    return map;
}

char **read_map(char *filename, int *size) {
    int fd, i = 0, x = 0, y = 0;
    char c;
    char buf[10];  // Harita boyutunu almak için küçük bir buffer
    char **map;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Hata: Dosya açılamadı -> %s\n", filename);
        return NULL;
    }

    // İlk satırdan harita boyutunu oku
    read(fd, buf, 10);
    *size = atoi(buf);

    // 2D array için bellek tahsis et
    map = allocate_map(*size);
    if (!map)
        return NULL;

    // İlk satırın kalan kısmını (karakterleri) atla
    while (buf[i] != '\n')
        i++;
    
    // Harita içeriğini 2D array'e aktar
    while (read(fd, &c, 1) > 0) {
        if (c != '\n') {
            map[x][y++] = c;
        } else {
            x++;
            y = 0;
        }
    }
    close(fd);
    return map;
}

void print_map(char **map, int size) {
    int x, y;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            write(1, &map[x][y], 1);
        }
        write(1, "\n", 1);
    }
}

void free_map(char **map, int size) {
    int i;
    for (i = 0; i < size; i++)
        free(map[i]);
    free(map);
}
