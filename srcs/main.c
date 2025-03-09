#include "../includes/bsq.h"



// Kare içinde 'o' olup olmadığını kontrol eden fonksiyon
int is_valid_square(char map[MAX_SIZE][MAX_SIZE], int x, int y, int size, int max_size) {
    if (x + size > max_size || y + size > max_size)
        return 0;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (map[i][j] == 'o') return 0; // Engel varsa kare geçersiz
        }
    }
    return 1;
}

// En büyük kareyi bulan brute-force algoritması
void find_largest_square_brute(char map[MAX_SIZE][MAX_SIZE], int size) {
    int max_size = 0, max_x = 0, max_y = 0;

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (map[x][y] == '.') {
                int current_size = 1;
                while (is_valid_square(map, x, y, current_size, size)) {
                    if (current_size > max_size) {
                        max_size = current_size;
                        max_x = x;
                        max_y = y;
                    }
                    current_size++;
                }
            }
        }
    }

    // En büyük kareyi 'x' ile işaretle
    for (int i = max_x; i < max_x + max_size; i++) {
        for (int j = max_y; j < max_y + max_size; j++) {
            map[i][j] = 'x';
        }
    }
}

// Haritayı ekrana yazdır
void print_map(char map[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Haritayı dosyadan okuma fonksiyonu
int read_map_from_file(char *filename, char map[MAX_SIZE][MAX_SIZE]) {
    int fd, i = 0, j = 0, size;
    char buffer[MAX_SIZE * MAX_SIZE]; // Dosya içeriğini tutacak buffer

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Hata: Dosya açılamadı -> %s\n", filename);
        return -1;
    }

    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        printf("Hata: Dosya okunamadı -> %s\n", filename);
        close(fd);
        return -1;
    }
    buffer[bytes_read] = '\0'; // String sonlandırma

    close(fd);

    // İlk satırdan haritanın boyutunu al
    size = atoi(buffer);

    // İlk satırın sonunu bul ve harita verisine geç
    char *ptr = buffer;
    while (*ptr != '\n' && *ptr != '\0') ptr++;
    if (*ptr == '\n') ptr++; // Satır sonunu geç

    // Harita verisini 2D diziye aktar
    while (*ptr != '\0' && i < size) {
        if (*ptr == '\n') {
            i++; j = 0; // Yeni satıra geç
        } else {
            map[i][j++] = *ptr;
        }
        ptr++;
    }

    return size;
}

// Ana program
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Kullanım: %s maps/grid1.txt\n", argv[0]);
        return 1;
    }

    char map[MAX_SIZE][MAX_SIZE];
    int size = read_map_from_file(argv[1], map);

    if (size == -1) {
        return 1;
    }

    find_largest_square_brute(map, size);
    printf("\nSonuç:\n");
    print_map(map, size);

    return 0;
}
