#include "help.h"

void help()
{
    printf("\n============ HELP ============\n");
    printf("1. CREATE GAME - Menambahkan game baru pada daftar game\n");
    printf("\n2. LIST GAME - Menampilkan daftar game yang tersedia pada sistem\n");
    printf("\n3. DELETE GAME - Menghapus game yang dibuat secara custom oleh pengguna\n");
    printf("\n4. QUEUE GAME - Mendaftarkan permainan ke dalam list game\n");
    printf("\n5. PLAY GAME - Memainkan sebuah permainan yang tersedia pada sistem\n");
    printf("\n6. SKIP GAME <n> - Melewatkan permainan sebanyak n\n");
    printf("\n7. SCOREBOARD - Menampilkan scoreboard dari semua permainan\n");
    printf("\n8. RESET SCOREBOARD - Menghapus data permainan yang tersimpan\n");
    printf("\n9. HISTORY <n> - Menampilkan daftar permainan yang telah dimainkan dengan sejumlah n\n");
    printf("\n10. RESET HISTORY - Menghapus semua permainan yang telah dimainkan\n");
    printf("\n11. SAVE <filename> - Menyimpan permainan ke dalam sebuah file\n");
    printf("\n12. HELP - Memberikan petunjuk fungsi masing-masing fitur\n");
    printf("\n13. QUIT - Keluar dari program\n");
}