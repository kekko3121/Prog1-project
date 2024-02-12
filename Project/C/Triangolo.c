/* Triangolo di carte
Si vuole sviluppare un programma per verificare se da un array di 5 interi generati a caso 
([6, 14, 15, 3, 13]) è possibile costruire un triangolo. Si suppone di avere 15 numeri consecutivi da 1 a 15. 
Il gioco richiede che ogni carta sia la differenza tra le due carte che le stanno immediatamente sotto, a 
sinistra e a destra.
*/

//includo le librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void g_num(int [], int); //prototipo per generare numeri e inserirli nell'array
int dif_num(int, int); //prototipo per calcolare la differenza
int val_ass(int); //prototipo per calcolare il valore assoluto

void main(){
    int array[5], n = 5 ,dif, ns;
    srand(time(NULL)); //cambio il seed alla funzione rand
    g_num(array, n); // richiamo il prototipo g_num
    for (int i = 0; i < n; i++){
        printf("|%d|", array[i]); //stampo l'array
    }
    printf("\n");
    ns = n; //assegno il valore di n a ns
    for(int i = 0; i < n; i++){
        for (int j = 0; j < ns - 1; j++){ //for innestato per calcolare la differenza
            dif = dif_num(array[j], array[j + 1]); //richiamo il prototipo dif_num e passo il elementi dell'array
            array[j] = val_ass(dif); //assegno il valore della differenza all'array
        }
        for(int j = 0; j < ns - 1; j++){
            printf("|%d|", array[j]); //stampo l'array
        }
        printf("\n");
        ns--; //decremento ns
    }
}

/* il prototipo permette di generare numeri casuali e di inserirli nell'array, come parametri passo un array
 e una variabile intera per specificare la dimensione dell'array */
void g_num(int array[], int n){
    int temp; //dichiaro una variabile temporanea
    for(int i = 0; i < n; i++){
        temp = 1 + rand() % 15; //genero un numero casuale da 1 a 15
        for(int j = 0; j <= i; j++){
            if(array[j] == temp) //verifico se il numero generato non sia contenuto nell'array
                temp = 1 + rand() % 15; //genero un nuovo numero casuale da 1 a 15
        }
        array [i] = temp; //assegno il valore di temp all'array
    }
}

/* il prototipo permette di calcolare la differenza di due numeri, come parametri passo due variabili intere */
int dif_num(int a, int b){
    int dif = a - b; //calcolo la differenza tra a e b
    return dif; //ritorna il valore dif
}

/* il prototipo permette di calcolare il valore assoluto di un numero, come parametri passo una variabile intera */
int val_ass(int x){
    if(x >= 0) //controllo se y è minore di 0
        return x; //ritorna il valore assoluto di x
    else
        return -x; //ritorna il valore x
}