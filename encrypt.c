#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int encoding (int, int);
int encoding (int holder, int key){
if (islower(holder)) {
holder = (holder-'a' +key) % 26 +'a';
holder += (holder < 'a') ? 26 : 0;
}
else if (isupper(holder)) {
holder = tolower((holder - 'A' +key) %26 +'A');
holder += tolower((holder < 'A') ? 26 :0);
}
return holder;
}
int main (void) {
FILE *fileIn;
FILE *fileOut;
char holder;
char words[300];
int key;
fileIn = fopen("/home/saleemuddin1/JuliaSS/message1.txt", "r");
if (fileIn == NULL) {
perror ("ERROR!");
exit (EXIT_FAILURE);
}
printf("\n The file contents are: \n");
while ((holder = fgetc(fileIn)) != EOF)
{

printf("%c",holder);
}
rewind(fileIn);
fileOut = fopen("/home/saleemuddin1/JuliaSS/output.txt", "w");
printf("\n Enter key: ");
scanf("%d", &key);
while ((holder = fgetc(fileIn)) != EOF)
{
printf ("%c", holder);
holder = encoding(holder, key);
fprintf(fileOut, "%c", holder);

}
printf("The file is encoded! Please check output.txt for encrypted version! \n");
fclose(fileOut);
fclose(fileIn);
return 0;

}
