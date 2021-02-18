#include <stdio.h>
#include "difficult/Title995.c"


int main() {

    int a[8] = {0,0,0,1,0,1,1,0};
    int n ;
    int avn = minKBitFlips(a,8,3);

    printf("%d",avn);

    return 0;
}
