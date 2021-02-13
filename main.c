#include <stdio.h>
#include "simple/Title448.c"


int main() {

    int a[8] = {4,3,2,7,8,2,3,1};
    int n ;
    int *avn = findDisappearedNumbers(a,8,&n);

    printf("%d",avn);

    return 0;
}
