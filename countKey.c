#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int counter[UCHAR_MAX + 1] = { 0 };
    int otVals, sum;
    int k;
    const char *r;
    FILE *fileIn = fopen("/home/saleemuddin1/JuliaSS/ceaser1.txt", "r");

    
    sum = 0;
    while ((k = getc(fileIn)) != EOF) {
        counter[tolower(k)] += 1;
        sum++;
    }

    printf("Character occurences in %s\n", argv[1]);
    printf("Character   Counts\n");
    otVals = sum;
    for (r = "abcdefghijklmnopqrstuvwxyz"; *r; r++) {
        printf("%c:\t%9d\n", *r, counter[(unsigned char)*r]);
        otVals -= counter[(unsigned char)*r];
    }
    printf("others:\t%9d\n", otVals);
    fclose(fileIn);
    return 0;
}
