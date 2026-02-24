#include <stdio.h>
#include <string.h>

// Fungsi untuk mendapatkan harga berdasarkan kode menu
int getHarga(char kode[]) {
    if (strcmp(kode, "NGS") == 0) return 15000;
    else if (strcmp(kode, "AP") == 0) return 20000;
    else if (strcmp(kode, "SA") == 0) return 25000;
    else if (strcmp(kode, "BU") == 0) return 18000;
    else if (strcmp(kode, "MAP") == 0) return 15000;
    else if (strcmp(kode, "GG") == 0) return 15000;
    else if (strcmp(kode, "SAM") == 0) return 17000;
    else if (strcmp(kode, "RD") == 0) return 25000;
    else if (strcmp(kode, "IB") == 0) return 35000;
    else if (strcmp(kode, "NUK") == 0) return 20000;
    else return 0; // Jika kode tidak ditemukan
}

// Fungsi untuk mendapatkan nama menu
const char* getNamaMenu(char kode[]) {
    if (strcmp(kode, "NGS") == 0) return "Nasi Goreng Spesial";
    else if (strcmp(kode, "AP") == 0) return "Ayam Penyet";
    else if (strcmp(kode, "SA") == 0) return "Sate Ayam";
    else if (strcmp(kode, "BU") == 0) return "Bakso Urat";
    else if (strcmp(kode, "MAP") == 0) return "Mie Ayam Pangsit";
    else if (strcmp(kode, "GG") == 0) return "Gado-Gado";
    else if (strcmp(kode, "SAM") == 0) return "Soto Ayam";
    else if (strcmp(kode, "RD") == 0) return "Rendang Daging";
    else if (strcmp(kode, "IB") == 0) return "Ikan Bakar";
    else if (strcmp(kode, "NUK") == 0) return "Nasi Uduk Komplit";
    else return "Unknown";
}

int main() {
    char kode[10];
    int porsiButet;
    
    char pesanan_kode[50][10];
    int pesanan_porsi[50];
    int pesanan_subtotal[50];
    int jumlah_pesanan = 0;
    
    float total_belanja = 0;
    
    // Looping input pesanan
    while (1) {
        scanf("%s", kode);
        
        if (strcmp(kode, "END") == 0) {
            break;
        }
        
        scanf("%d", &porsiButet);
        
        int harga = getHarga(kode);
        if (harga == 0) {
            continue; // Abaikan jika kode salah
        }
        
        // Porsi Ucok = 2x Porsi Butet, jadi total porsi = porsiButet * 3
        int totalPorsi = porsiButet + (porsiButet * 2); 
        int subtotal = totalPorsi * harga;
        
        strcpy(pesanan_kode[jumlah_pesanan], kode);
        pesanan_porsi[jumlah_pesanan] = totalPorsi;
        pesanan_subtotal[jumlah_pesanan] = subtotal;
        
        total_belanja += subtotal;
        jumlah_pesanan++;
    }
    
    // Menentukan Diskon
    float diskon_persen = 0.0;
    char warna_kupon[20] = "-";
    
    if (total_belanja >= 500000) {
        diskon_persen = 0.25;
        strcpy(warna_kupon, "Hitam");
    } else if (total_belanja >= 400000) {
        diskon_persen = 0.20;
        strcpy(warna_kupon, "Hijau");
    } else if (total_belanja >= 300000) {
        diskon_persen = 0.15;
        strcpy(warna_kupon, "Merah");
    } else if (total_belanja >= 200000) {
        diskon_persen = 0.10;
        strcpy(warna_kupon, "Kuning");
    } else if (total_belanja >= 100000) {
        diskon_persen = 0.05;
        strcpy(warna_kupon, "Biru");
    }
    
    float nominal_diskon = total_belanja * diskon_persen;
    float total_bayar = total_belanja - nominal_diskon;
    
    // Cetak Struk
    printf("\n===============================================\n");
    printf("              STRUK WARUNG MAK ROBY            \n");
    printf("           Transaksi Transparan & Aman         \n");
    printf("===============================================\n");
    printf("%-20s %-10s %-10s\n", "Item", "Porsi", "Subtotal");
    printf("-----------------------------------------------\n");
    
    for (int i = 0; i < jumlah_pesanan; i++) {
        printf("%-20s %-10d Rp %d\n", 
               getNamaMenu(pesanan_kode[i]), 
               pesanan_porsi[i], 
               pesanan_subtotal[i]);
    }
    
    printf("-----------------------------------------------\n");
    printf("%-31s Rp %.0f\n", "Total Belanja:", total_belanja);
    printf("%-31s %s (%.0f%%)\n", "Kupon Didapat:", warna_kupon, diskon_persen * 100);
    printf("%-31s Rp %.0f\n", "Potongan Harga:", nominal_diskon);
    printf("===============================================\n");
    printf("%-31s Rp %.0f\n", "TOTAL BAYAR:", total_bayar);
    printf("===============================================\n");
    
    return 0;
}