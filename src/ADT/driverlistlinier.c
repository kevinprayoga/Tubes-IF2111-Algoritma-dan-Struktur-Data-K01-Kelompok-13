#include "listlinier.h"
#include <stdio.h>

int main () {
    // KAMUS
    List test;
    infotypeLinked pt, pt2, pt3, cari;
    addressLinked add, add2, add3;

    // ALGORITMA
    CreateEmpty(&test);
    printf("Cek empty list (0 jika salah, 1 jika benar): %d; Jml elmt: %d\n", IsEmptyListLinier(test), NbElmt(test));
    printf("Isi list: "); PrintInfo(test); printf("\n");

    printf("\nCek InsertFirstList\n");
    printf("Sebelum InsertFirstList: "); PrintInfo(test); printf("\n");
    CreatePoint(&pt, 1, 2);
    add = Alokasi(pt);
    InsertFirstList(&test, add);
    printf("point2: "); displayPoint(pt); printf("\n");
    CreatePoint(&pt2, 3, 4);
    add2 = Alokasi(pt2);
    InsertFirstList(&test, add2);
    printf("point1: "); displayPoint(pt2); printf("\n");
    printf("Setelah InsertFirstList: "); PrintInfo(test);
    printf(";Jml elmt: %d \n", NbElmt(test));

    printf("\nCek InsertLastList\n");
    printf("Sebelum InsertLastList: "); PrintInfo(test); printf("\n");
    CreatePoint(&pt, 5, 6);
    add = Alokasi(pt);
    InsertLastList(&test, add);
    printf("Point yang ditambahkan: \n"); displayPoint(pt);
    printf("\nSetelah InsertLastList: "); PrintInfo(test);
    printf("; Jml elmt: %d \n", NbElmt(test));

    printf("\nCek InsertAfter\n");
    printf("Sebelum InsertAfter: "); PrintInfo(test); printf("\n");
    CreatePoint(&pt3, 7, 8);
    printf("Point yang ditambahkan: "); displayPoint(pt3); printf("\n");
    printf("Point tsb ditambahkan setelah point: "); displayPoint(pt); printf("\n");
    add3 = Alokasi(pt3);
    InsertAfter(&test, add3, add);
    printf("Setelah InsertAfter: "); PrintInfo(test);
    printf("; Jml elmt: %d \n", NbElmt(test));

    printf("\nCek DelFirst\n");
    printf("Sebelum DelFirst: "); PrintInfo(test); printf("\n");
    DelFirst(&test, &add);
    printf("Setelah DelFirst: "); PrintInfo(test); 
    printf("; Jml elmt: %d \n", NbElmt(test)); printf("\n");
    
    printf("\nCek InsVFirst dan InsVLast\n");
    printf("Sebelum InsVFirst & InsVLast: "); PrintInfo(test); printf("\n");
    InsVLast(&test, pt2);
    printf("point InsVLast: "); displayPoint(pt2); printf("\n");
    InsVFirst(&test, pt);
    printf("point InsVFirst: "); displayPoint(pt); printf("\n");
    printf("Setelah InsVFirst & InsVLast: "); PrintInfo(test);
    printf(";Jml elmt: %d \n", NbElmt(test));
    
    printf("\nCek DelP\n");
    printf("Sebelum DelP: "); PrintInfo(test); printf("\n");
    printf("Point yang akan dihapus: "); displayPoint(pt2); printf("\n");
    DelP(&test, pt2);
    printf("Setelah DelP: "); PrintInfo(test);
    printf(";Jml elmt: %d \n", NbElmt(test));

    printf("\nCek DelLast\n");
    printf("Sebelum DelLast: "); PrintInfo(test); printf("\n");
    printf("Point yang akan dihapus: "); displayPoint(Info(add)); printf("\n");
    DelLast(&test, &add);
    printf("\nSetelah DelLast: ");PrintInfo(test);
    printf("; Jml elmt: %d \n", NbElmt(test));

    printf("\nCek DelAfter\n");  
    InsertLastList(&test, add); printf("Menambahkan point: "); displayPoint(Info(add)); printf("\n");
    InsertLastList(&test, add2); printf("Menambahkan point: "); displayPoint(Info(add2)); printf("\n");
    printf("Sebelum DelAfter: "); PrintInfo(test); printf("\n");
    printf("Menghapus point setelah point: "); displayPoint(Info(add)); printf("\n");
    printf("Point yang akan dihapus: "); displayPoint(Info(add2)); printf("\n");
    DelAfter(&test, &add2, add);
    printf("Setelah DelAfter: "); PrintInfo(test);
    printf(";Jml elmt: %d \n", NbElmt(test));

    printf("\nList sekarang: "); PrintInfo(test); printf("\n");
    printf("Cek Search\n");
    printf("NULL: %p \n", NULL);
    printf("\nPoint yang dicari: "); displayPoint(pt3);
    printf("\nHasil search, menampilkan alamatnya jika ada, jika tidak ditemukan maka menampilkan NULL: %p\n", Search(test, pt3));
    printf("\nPoint yang dicari: "); CreatePoint(&cari, 1, 1); displayPoint(cari);
    printf("\nHasil search, menampilkan alamatnya jika ada, jika tidak ditemukan maka menampilkan NULL: %p\n", Search(test, cari));
    return 0;
}