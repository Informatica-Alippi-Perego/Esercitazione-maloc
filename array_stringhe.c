#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampa(char **stringa, int i);
char** inserisci(char **stringa, int *n);
void stampaParola(char *parola);

int main(int argc, const char * argv[]) {
    char **stringhe;
    int num;
    
    stringhe = inserisci(stringhe, &num);
    stampa(stringhe, num);

    return 0;
}


char** inserisci(char **stringa, int *n){
    *n = 0;
    int len;
    char str[20];
    
    printf("Quante strighe vuoi inserire? ");
    scanf("%d",&len);
    stringa = (char**)malloc(sizeof(char*)*len);
    do{
        printf("Insersici la stringa: ");
        scanf(" %s",str);
        stringa[*n] = (char*)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(stringa[*n],str);
        (*n)++;
    }while (*n<len);
    return stringa;
}

void stampa(char **stringa, int i){
    for (i=i-1; i>=0; i--)
        stampaParola(stringa[i]);
}


void stampaParola(char *parola){
    char *i;
    int len = 0;
    
    for (i=parola; (*i)!='\0'; i++)
        len++;
    
    for (i=parola+len-1; i>=parola; i--)
        printf("%c",*i);
    printf("\n");
    
}

void stampaParolaInt(char *parola){
    int len = 0;
    
    for (len=0; parola[len]!='\0'; len++);
    
    for (len = len-1; len>=0; len--)
        printf("%c",parola[len]);
    printf("\n");
    
}
