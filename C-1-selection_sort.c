#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void selection_sort(int array[]);
void escreve_vetor(int array[], char *msg);

int main(){
    int A[TAM] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    escreve_vetor(A, "VETOR DESORDENADO");
    selection_sort(A);
    escreve_vetor(A, "VETOR ORDENADO");

    return 0;
}

void escreve_vetor(int array[], char *msg){
    printf("\n--------- %s ---------\n", msg);
    for (int i = 0; i < TAM; i++){
        printf("%d\t", array[i]);
    }
}

void selection_sort(int array[]){
    int i, j, k, menor, aux;
    k = 0;
    for(i = 0; i < TAM; i++){
        menor = i;
        for (j = (i + 1); j < TAM; j++){
            if(array[menor] > array[j]){
                menor = j;
            }
            aux = array[menor];
            array[menor] = array[i];
            array[i] = aux;
            printf("\n%d---", k);
            escreve_vetor(array, "Selection Sort");
            printf("\n");
            k++;
        }
    }
}