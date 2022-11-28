#include <stdio.h>
#include <stdlib.h>

int* inserisci(int len);
int somma(int val[], int len);

int main(int argc, const char * argv[]) {
    int *val = NULL;
    int num;
    
    printf("Quanti valori vuoi inserire: ");
    scanf("%d",&num);
    
    printf("Inserisci %d numeri: ",num);
    val = inserisci(num);
    printf("La somma dei numeri inseriti vale %d\n",somma(val,num));
    free(val);
    return 0;
}

int* inserisci(int len){
    int *val = (int *)malloc(sizeof(int)*len);
    int *start = val;
    while(val<start+len){
        scanf("%d",val);
        val++;
    }
    /*
    for (start = val; val<start+len; val++){
        scanf("%d",val);
    }
     */
    return start;
}

int somma(int val[], int len){
    int *start;
    int somma = 0;
    for (start = val; val<start+len; val++){
        somma = somma + *val;
    }
    return somma;
}
