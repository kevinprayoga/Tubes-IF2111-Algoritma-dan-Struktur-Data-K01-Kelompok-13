#include "help.h"

void help()
{
    printf("\n============ HELP ============\n");
    printf("1. CREATE GAME - Menambahkan game baru pada daftar game\n");
    printf("2. LIST GAME - Menampilkan daftar game yang tersedia pada sistem\n");
    printf("3. DELETE GAME - Menghapus game yang dibuat secara custom oleh pengguna\n");
    printf("4. QUEUE GAME - Mendaftarkan permainan ke dalam list game\n");
    printf("5. PLAY GAME - Memainkan sebuah permainan yang tersedia pada sistem\n");
    printf("6. SKIP GAME <n> - Melewatkan permainan sebanyak n\n");
    printf("7. SCOREBOARD - Menampilkan scoreboard dari semua permainan\n");
    printf("8. RESET SCOREBOARD - Menghapus data permainan yang tersimpan\n");
    printf("9. HISTORY <n> - Menampilkan daftar permainan yang telah dimainkan dengan sejumlah n\n");
    printf("10. RESET HISTORY - Menghapus semua permainan yang telah dimainkan\n");
    printf("11. SAVE <filename> - Menyimpan permainan ke dalam sebuah file\n");
    printf("12. HELP - Memberikan petunjuk fungsi masing-masing fitur\n");
    printf("13. QUIT - Keluar dari program\n");
}