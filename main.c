#include <stdio.h>
#include "simple/Title643.c"


int main() {

    int a[5] = {0,4,0,3,2};
    double avn = findMaxAverage(a, 5, 1);
    printf("%f",avn);

    return 0;
}
