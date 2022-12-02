#include "point.h"
#include <stdio.h>

int main () 
{
    point pt;
    point pt2;

    CreatePoint(&pt, 1, 2);
    CreatePoint(&pt2, 3, 4);
    printf("Cek CreatePoint pt: "); displayPoint(pt); printf("\n");
    printf("Cek CreatePoint pt2: "); displayPoint(pt2); printf("\n");

    printf("\nCek isOrigin\n");
    printf("Point yang dicek: "); displayPoint(pt); printf("\n");
    printf("Cek (0 jika salah, 1 jika betul): %d\n", isOrigin(pt)); 

    printf("\nCek CreatePointNil\n");
    printf("Point yang di-nil-kan: "); displayPoint(pt); printf("\n");
    CreatePointNil(&pt);
    printf("Hasil: "); displayPoint(pt); printf("\n");

    printf("\nCek isPointEq\n");
    printf("Point yang dicek: "); displayPoint(pt); printf("\n");
    printf("Point yang dicek: "); displayPoint(pt2); printf("\n");
    printf("Cek (0 jika salah, 1 jika betul): %d\n", isPointEq(pt, pt2));

    printf("\nCek isPointEq\n");
    printf("Point yang dicek: "); displayPoint(pt); printf("\n");
    printf("Point yang dicek: "); displayPoint(pt); printf("\n");
    printf("Cek (0 jika salah, 1 jika betul): %d\n", isPointEq(pt, pt));

    return 0;
}