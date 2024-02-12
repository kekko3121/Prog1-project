/*Agenda
Si vuole simulare la gestione di un’agenda elettronica contenente appuntamenti.
L’agenda è suddivisa in giorni, per 12 mesi complessivi. Ogni giorno è identificato da 24 ore. 
Dato un mese, un giorno e un’ora permettere all’utente di:
• Inserire un appuntamento
• Disdire un appuntamento
Inoltre permettere all’utente di
• Data un’ora visualizzare tutti gli appuntamenti in un mese
Provvedere all’implementazione dell’algoritmo per la simulazione dell’agenda. 
Effettuare almeno un test per ognuna delle opzioni dell’utente.
*/

//includo le librerie;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creo una struttura e aggiungo i vari dati per un'agenda;
typedef struct{
    int  anno; //variabile per inserire l'anno;
    char mese[10]; //array per inserire il mese;
    int giorno; //variabile per inserire il giorno;
    int ora; //variabile per inserire l'ora;
    int minuti; //variabile per inserire minuti;
    char agenda [100]; //variabile per inserire il contenuto dell'agenda;
} Agenda;

void Ins_app(Agenda [], Agenda, int); //prototipo per inserire gli appuntamenti;
void Dis_app(Agenda [], Agenda, int *); //prototipo per disdire gli appuntamenti;
int Vis_app(Agenda, int); //prototipo per visualizzare gli appuntamenti;

void main(){
    Agenda contenuto; //variabile contenuto per inserire i dati dell'utente e passarli al prototipo Ins_app;
    Agenda impegni[100]; //array per salvare tutti i dati inseriti dall'utente;
    int scelta = 0, n = 0, tora = 0; //variabile scelta per offrire opzioni, n per la dimensione dell'array, tora per visualizzare gli appuntamenti di un determinato orario;
    printf("Ciao Benvenuto nell'Agenda.\n");
    printf("Cosa vuoi fare?\n");
    do{
        printf("Premere 1 per inserire un appuntamento.\n");
        printf("Premere 2 per disdire un appuntamento.\n");
        printf("Premere 3 per visualizzare un appuntamento.\n");
        scanf("%d", &scelta); //prende in input la scelta dell'utente;
        switch (scelta){
            case 1: //1) sceglie di inserire un appuntamento;   
                do{
                    printf("inserisci anno\n");
                    scanf("%d", &contenuto.anno); //inserisce l'anno;
                    printf("inserisci mese\n");
                    scanf("%s", &contenuto.mese); //inserisce il mese;
                    printf("Inserisci numero giorno\n");
                    scanf("%d", &contenuto.giorno); //inserisce il giorno;
                    printf("Inserisci ora\n");
                    scanf("%d", &contenuto.ora); //inserisce l'ora;
                    printf("Inserisci minuti\n");
                    scanf("%d", &contenuto.minuti); //inserisce i minuti;
                    getchar();
                    printf("inserisci appunto\n");
                    gets(contenuto.agenda);
                    //controllo per non superare i valori minimi e massimi di anno, mese, ora e minuti;
                }while(contenuto.anno < 2000 ||contenuto.giorno <= 0 ||contenuto.giorno > 31 || contenuto.ora < 0 || contenuto.ora > 23 || contenuto.minuti < 0 || contenuto.minuti > 59 );
                n++; //viene incrementato ogni volta che viene inserito un appuntamento;
                //richiama il prototipo ins_app e passa l'array impegni, la variabile contenuto e n;
                Ins_app(impegni, contenuto, n); //richiamo prototipo per inserire i dati dell'utente nel vettore;
                break;
            case 2:
                do{
                    printf("inserisci mese\n");
                    scanf("%s", &contenuto.mese); //inserisce il mese;
                    printf("Inserisci numero giorno\n");
                    scanf("%d", &contenuto.giorno); //inserisce il giorno;
                    printf("Inserisci ora\n");
                    scanf("%d", &contenuto.ora); //inserisce l'ora;
                    printf("Inserisci minuti\n");
                    scanf("%d", &contenuto.minuti); //inserisce i minuti;
                    //controllo per non superare i valori minimi e massimi di mese, ora e minuti;
                }while(contenuto.giorno <= 0 ||contenuto.giorno > 31 || contenuto.ora < 0 || contenuto.ora > 23 || contenuto.minuti < 0 || contenuto.minuti > 59 );
                Dis_app(impegni, contenuto, &n);
                break;
            case 3: //3)sceglie di visualizzare un appuntamento;
                do{
                    printf("Inserisci orario da visualizzare\n");
                    scanf("%d", &tora); //inserisce l'orario da visualizzare;
                }while (tora < 0 || tora > 23); //verifico il max range di un ora;
                for(int i = 0; i < n; i++){ //for per scorrere l'array;
                    if(Vis_app(impegni[i], tora)) //richiama il prototipo e passa la posizione del vettore e tora;
                    //stampa l'appuntamento dell'orario scelto dall'utente;
                    printf(" anno: %d;\n mese: %s;\n giorno: %d;\n ora: %d;\n minuti: %d;\n appunto: %s.\n", impegni[i].anno, impegni[i].mese, impegni[i].giorno, impegni[i].ora ,impegni[i].minuti, impegni[i].agenda);
                }
                break;
            default:
                break;
        }
    }while (scelta == 1 || scelta == 2 || scelta == 3);
}

/* prototipo per assegnare le impostazioni inserite dall'utente nell'array, come parametri passo un array, 
   variabile agenda e la dimensione dell'array. */
void Ins_app(Agenda impegni [], Agenda contenuto, int n){
    for(int i = 0; i < n; i++){ //ciclo for per scorrere l'array
        if(impegni[i].ora == 0 && strcmp(impegni[i].agenda, "\0") == 0) //verifica se il contenuto di impegni è vuoto
            impegni[i] = contenuto; //assegno il valore di contenuto all'array
    }
}

/* prototipo  per eliminare il contenuto dell'array scelto dall'utente, come parametri passo un array, 
   variabile agenda e la dimensione dell'array. */
void Dis_app(Agenda impegni[], Agenda contenuto, int *n){
    int m = *n; //dichiaro variabile di appoggio e gli assegno il contenuto di n
    for (int i = 0; i < m; i++){ //ciclo for per scorrere l'array
        // verifico se il contenuto dell'array è uguale a quello scelto dall'utente
        if(strcmp(impegni[i].mese, contenuto.mese) == 0 && impegni[i].giorno == contenuto.giorno && impegni[i].ora == contenuto.ora && impegni[i].minuti == contenuto.minuti){
            for(int j = i; j < m - 1; j++) //for per scorrere dall'array dal punto del for precedente
                impegni[j] = impegni[j + 1]; //assegno all'array la posizione successivo
            impegni[m - 1].ora = 0; //viene assegnato all'array un valore 0.
            strcpy(impegni[m - 1].agenda, "\0"); //viene assegnato all'array la fine della stringa vuota.
            m--; //decremento m
        }
    }
    n = &m; //assegno il contenuto di m a n
}
/* prototipo per visualizzare il contenuto dell'array scelto dall'utente, come parametri passo una variabile
   agenda e un intero. */
int Vis_app(Agenda impegni, int ora){
    if(impegni.ora == ora) //verifica se l'ora inserita dall'utente è uguale a quella dell'array
        return 1; // se è vero ritorna 1
    else
        return 0; // altrimenti 0
}