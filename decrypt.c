#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int decode (int, int);

int decode(int holder, int keyHolder) {
    if (islower(holder)) {
        holder = (holder-'a' + keyHolder) % 26 + 'a';
        holder += (holder < 'a') ? 26 : 0;
    }
    else if (isupper(holder)) {
        holder = (holder-'A' + keyHolder) % 26 + 'A';
        holder += (holder < 'A') ? 26 : 0;
    }
    return holder;
}
int main (void)
{
    FILE *fileIn;
    FILE *fileOuter;
    char holder;
    char texter[300];
    int keyHolder;
    fileIn = fopen("/home/saleemuddin1/JuliaSS/ceaser2.txt", "r");
 if( fileIn == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n The contents of the file are : \n");

    while( ( holder = fgetc(fileIn) ) != EOF )
    {
        printf("%c",holder);
    }

    rewind(fileIn);
fileOuter = fopen("/home/saleemuddin1/JuliaSS/dc.txt","w");

    printf("\n Please Enter the Key:");
    scanf("%d", &keyHolder);

    while( ( holder = fgetc(fileIn) ) != EOF )
    {
        //printf("%c", holder);
        holder=decode(holder, keyHolder);
        fprintf(fileOuter, "%c", holder);
    }
    printf("File is encoded. Please check dc.txt for decrypted file!\n");
    fclose(fileOuter);
    fclose(fileIn);

    return 0;
}
