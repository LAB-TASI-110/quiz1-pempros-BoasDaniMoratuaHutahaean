#include <stdio.h>

int main() {
    int N;
    
    // 1. Input Jumlah total data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    // Deklarasi array sesuai jumlah N
    int nilai[N];
    
    // 2. Input Deret nilai
    printf("Masukkan %d deret nilai (pisahkan dengan spasi): ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    int kode_kelompok;
    
    // 3. Input Kode kelompok (Asumsi: 1 atau 2)
    printf("Masukkan kode kelompok (1 atau 2): ");
    scanf("%d", &kode_kelompok);

    int total_nilai = 0;

    // ==============================================================
    // PENERAPAN RUMUS ARITMETIKA PADA INDEKS ARRAY
    // Indeks awal (a) = kode_kelompok - 1
    // Beda (b) = 2 (karena data berselang-seling untuk 2 kelompok)
    // ==============================================================
    
    int a = kode_kelompok - 1;
    int b = 2;

    // Perulangan ini melompat (step) sebanyak b=2
    for(int i = a; i < N; i += b) {
        total_nilai += nilai[i];
    }

    // 4. Output hasil
    printf("Total nilai untuk kelompok %d adalah: %d\n", kode_kelompok, total_nilai);

    return 0;
}