#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studente{
    char nome[20];
    char cognome[20];
    int codicePersona;
    int voto;
} studente;

studente* inserisci_studenti(int n);
int cerca_studente(studente *s, int n);
studente* elenco_rimandati(studente *s, int n, int *nr);
studente* elimina_studente(studente *s, int *n, int pos);
void stampa_elenco(studente *s, int n);

int main(int argc, const char * argv[]) {
    studente *studenti = NULL;
    studente *studentiRimandati = NULL;
    int n=0;
    int nr=0;
    int r;
    
    do{
        printf("MENU\n");
        printf("1) Inserisci studenti (cancellando quelli già inseriti)\n");
        printf("2) Cerca studente\n");
        printf("3) Crea elenco rimandati\n");
        printf("4) Elimina studente\n");
        printf("5) ESCI\n");
        printf (">> ");
        scanf("%d",&r);
        
        switch(r){
            case 1:
                printf("Quanti studenti vuoi inserire? ");
                scanf("%d",&n);
                studenti = inserisci_studenti(n);
                stampa_elenco(studenti,n);
                break;
            case 2:
                if (cerca_studente(studenti, n)<0)
                    printf("Non ho trovato lo studente cercato\n");
                else
                    printf("Lo studente è presente nell'elenco\n");
                break;
            case 3:
                studentiRimandati = elenco_rimandati(studenti, n, &nr);
                stampa_elenco(studentiRimandati,nr);
                break;
            case 4:
                studenti = elimina_studente(studenti, &n, cerca_studente(studenti, n));
                stampa_elenco(studenti, n);
                break;
        }
    }while(r!=5);
    return 0;
}

studente* inserisci_studenti(int n){
    int i;
    studente *stud;
    stud = (studente*)malloc(sizeof(studente)*n);
    
    for (i=0; i<n; i++){
        printf("Inserisco Cognome: ");
        scanf(" %s",stud[i].cognome);
        printf("Inserisco Nome: ");
        scanf(" %s",stud[i].nome);
        printf("Inserisco codice persona: ");
        scanf("%d",&stud[i].codicePersona);
        printf("Inserisco voto: ");
        scanf("%d",&stud[i].voto);
        printf("\n");
    }
    return stud;
}

int cerca_studente(studente *s, int n){
    char cognome[20];
    char nome[20];
    int i;
    
    if (n==0)
        return -1;
    
    printf("Inserisci cognome da cercare: ");
    scanf(" %s",cognome);
    printf("Inserisci nome da cercare: ");
    scanf(" %s",nome);
    
    for (i=0; i<n; i++){
        if ((strcmp(cognome,s[i].cognome)==0) && (strcmp(nome,s[i].nome)==0))
            return i;
    }
    return -1;
        
}
studente* elenco_rimandati(studente *s, int n, int *nr){
    studente *studRim = NULL;
    *nr = 0;
    int i;
    int contRimandati = 0;
    
    if (n==0){
        *nr = 0;
        return studRim;
    }
    //Conta quanti sono gli studenti con voto <18
    for(i=0; i<n; i++){
        if (s[i].voto<18)
            contRimandati++;
    }
    
    studRim = (studente*)malloc(sizeof(studente)*(*nr));
    contRimandati=0;
    
    for (i=0; i<n; i++){
        if (s[i].voto<18){
            studRim[contRimandati] = s[i];
            contRimandati++;
        }
    }
    *nr = contRimandati;
    return studRim;
}

studente* elimina_studente(studente *s, int *n, int pos){
    int len = *n;
    
    if ( (len==0) || (len<pos) || (pos==-1))
        return s;
    
    memcpy(&s[pos],&s[pos+1],sizeof(studente)*((len)-pos-1));
    (len)--;
    *n = len;
    if (len==0){
        free(s);
        return NULL;
    }
    else {
        s = realloc(s, sizeof(studente)*(len));
        return s;
    }
        
}

void stampa_elenco(studente *s, int n){
    int i;
    for (i=0; i<n; i++)
        printf("Cognome: %s\nNome: %s\nCodice persona: %d\nVoto: %d\n\n",s[i].cognome,s[i].nome,s[i].codicePersona,s[i].voto);
}
