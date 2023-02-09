#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

void ler_array(int array[], char *msg){
    printf("\n\n****** INICIO - %s ******", msg);
    for(int i = 0; i < TAM; i++){
        printf("\n\tPosicao: %d - Valor: %d", i, array[i]);
    }
    printf("\n****** FIM - %s ******", msg);
}

void trocar(int array[], int i, int j){
    int aux;
    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

int particionar(int array[], int inicio, int final){
    int pivo, i, j;

    pivo = array[((inicio + final) / 2)];
    printf("Pivo: %d", pivo);
    i = inicio - 1;
    j = final + 1;

    while(i < j){
        do{ j--; } while(array[j] > pivo);

        do{ i++; } while(array[i] < pivo);

        if(i < j){ trocar(array, i, j);}
    }
    return j;
}

void quickSort(int array[], int inicio, int final){
    int meio;
    printf("I: %d, F: %d", inicio, final);
    if(inicio < final){
        meio = particionar(array, inicio, final);
        quickSort(array, inicio, meio);
        quickSort(array, (meio + 1), final);
    }
}

int main(){

    int Array[TAM] = {5, 8, 3, 1, 6, 2, 4, 9, 7, 5};
    ler_array(Array, "Array desordenado");

    /*Teste troca 
    trocar(Array, 0, 8);
    ler_array(Array, "Array trocado");*/

    quickSort(Array, 0, (TAM - 1));
    ler_array(Array, "Array Ordenado Quick Sort");

    return 0;
}