#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi variabel
    char nama_pelanggan[50];
    int pilihan_layanan;
    float berat_cucian;
    float total_harga, diskon, total_bayar;
    char jenis_layanan[30];
    char lanjut;

    printf("==========================================\n");
    printf("     SISTEM OPERASIONAL LAUNDRY DEL\n");
    printf("==========================================\n");

    do {
        // Reset nilai untuk setiap pelanggan baru
        total_harga = 0.0;
        diskon = 0.0;
        total_bayar = 0.0;

        printf("\n--- INPUT DATA PELANGGAN ---\n");
        printf("Masukkan Nama Pelanggan : ");
        // Spasi sebelum % memastikan sisa 'enter' dari input sebelumnya dibersihkan
        scanf(" %[^\n]", nama_pelanggan); 

        printf("\n--- DAFTAR LAYANAN ---\n");
        printf("1. Cuci Kering Reguler (Rp 6.000 / kg)\n");
        printf("2. Cuci Kering Kilat   (Rp 10.000 / kg)\n");
        printf("3. Setrika Saja        (Rp 5.000 / kg)\n");
        printf("4. Cuci Komplit VIP    (Rp 15.000 / kg)\n");
        
        printf("Pilih Layanan (1-4)     : ");
        scanf("%d", &pilihan_layanan);

        // Validasi pilihan layanan
        if (pilihan_layanan < 1 || pilihan_layanan > 4) {
            printf("\n[ERROR] Pilihan layanan tidak valid. Data tidak diproses.\n");
        } else {
            // Jika pilihan valid, baru minta input berat
            printf("Masukkan Berat (kg)     : ");
            scanf("%f", &berat_cucian);

            // PROSES: Menghitung harga dasar
            switch (pilihan_layanan) {
                case 1: strcpy(jenis_layanan, "Cuci Kering Reguler"); total_harga = berat_cucian * 6000; break;
                case 2: strcpy(jenis_layanan, "Cuci Kering Kilat"); total_harga = berat_cucian * 10000; break;
                case 3: strcpy(jenis_layanan, "Setrika Saja"); total_harga = berat_cucian * 5000; break;
                case 4: strcpy(jenis_layanan, "Cuci Komplit VIP"); total_harga = berat_cucian * 15000; break;
            }

            // PROSES: Logika Diskon (Diskon 10% jika berat > 5 kg)
            if (berat_cucian > 5.0) {
                diskon = total_harga * 0.10;
            }
            total_bayar = total_harga - diskon;

            // OUTPUT: Menampilkan Struk
            printf("\n==========================================\n");
            printf("          STRUK LAUNDRY DEL\n");
            printf("==========================================\n");
            printf("Nama Pelanggan : %s\n", nama_pelanggan);
            printf("Jenis Layanan  : %s\n", jenis_layanan);
            printf("Berat Cucian   : %.2f kg\n", berat_cucian);
            printf("------------------------------------------\n");
            printf("Subtotal       : Rp %.2f\n", total_harga);
            
            if (diskon > 0) {
                printf("Diskon Promo   : -Rp %.2f (10%%)\n", diskon);
            }
            
            printf("------------------------------------------\n");
            printf("TOTAL BAYAR    : Rp %.2f\n", total_bayar);
            printf("==========================================\n");
        }

        // Pertanyaan perulangan selalu dieksekusi, baik input valid maupun tidak
        printf("\nInput pelanggan selanjutnya? (y/n): ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y' || lanjut == 'Y');

    printf("\n==========================================\n");
    printf("  Sistem Ditutup. Terima Kasih!\n");
    printf("==========================================\n");

    return 0;
}