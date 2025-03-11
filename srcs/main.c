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
    int fd;
    int bytes_read;
    char buffer[MAX_SIZE * MAX_SIZE] = {0};  // Buffer tamamen sıfırlandı
    char *ptr;
    int size, i, j;

    fd = open(filename, O_RDONLY);
    if (fd == -1) return -1;

    // Fazladan 1 byte bırakıp sonuna '\0' ekle
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    if (bytes_read <= 0) return -1;
    buffer[bytes_read] = '\0';  // Buffer'ı güvenli hale getir

    size = atoi(buffer);
    if (size <= 0 || size > MAX_SIZE) return -1;  // Geçersiz boyut kontrolü

    ptr = buffer;
    while (*ptr != '\n' && *ptr != '\0') ptr++;
    if (*ptr == '\n') ptr++;

    i = 0;
    j = 0;
    while (*ptr != '\0' && i < size) {
        if (*ptr == '\n') {
            i++;
            j = 0;
        } else {
            if (*ptr == '.' || *ptr == 'o') {
                map[i][j] = *ptr;
                j++;
            } else {
                return -1;  // Geçersiz karakter varsa hata ver
            }
        }
        ptr++;
    }

    return size;
}
    int read_map_from_stdin(char map[MAX_SIZE][MAX_SIZE]) {
        char buffer[1024];  // Buffer büyütüldü
        int size, i, j;
        char *ptr;

     // İlk satırı oku (boyut + karakterler)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            return -1;

     size = atoi(buffer);
        if (size <= 0 || size > MAX_SIZE) return -1;

    i = 0;
    while (i < size) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) // Satır satır oku
            return -1;

        j = 0;
        ptr = buffer;
        while (*ptr != '\n' && j < size) {
            if (*ptr == '.' || *ptr == 'o') {
                map[i][j] = *ptr;
                j++;
            } else {
                return -1;  // Geçersiz karakter hatası
            }
            ptr++;
        }
        i++;
    }

    return size;
}


int main(int argc, char **argv) {
    char map[MAX_SIZE][MAX_SIZE];
    int size;
    int i;

    // Eğer hiç argüman girilmezse, stdin'den harita bekle
    if (argc == 1) {
        size = read_map_from_stdin(map);
        if (size == -1) {
            write(2, "map error\n", 10);
            return 1;
        }
        find_largest_square_brute(map, size);
        print_map(map, size);
        return 0;
    }

    // Eğer birden fazla dosya girilmişse, her birini işle
    i = 1;
    while (i < argc) {
        size = read_map_from_file(argv[i], map);
        if (size == -1) {
            write(2, "map error\n", 10);
        } else {
            find_largest_square_brute(map, size);
            print_map(map, size);
        }
        if (i < argc - 1)
            write(1, "\n", 1);
        i++;
    }

    return 0;
}