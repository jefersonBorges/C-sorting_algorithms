#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

void escreve_vetor(int array[],char *msg);
void bubble_sort(int array[]);
void bubble_sort_flag(int array[]);

int main(){
    int A[TAMANHO] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    escreve_vetor(A, "VETOR DESORDENADO");
    //bubble_sort_flag(A);
    bubble_sort(A);
    escreve_vetor(A, "VETOR ORDENADO");

    return 0;
}

void escreve_vetor(int array[],char *msg){
    printf("\n--------- %s ---------\n", msg);
    for (int i = 0; i < TAMANHO; i++){
        printf("%d\t", array[i]);
    }
}

void bubble_sort(int array[]){
    int i, j, k, aux;
    k = 0;
    for (i = 1; i < TAMANHO; i++){
        for (j = 0; j < (TAMANHO - i); j++){
            if(array[j] > array[j+1]){
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                escreve_vetor(array, "Bubble Sort");
                printf("\nI : %d, J: %d, K: %d\t", i, j, k);
                
            }
            k++;
        }
    }
}


void bubble_sort_flag(int array[]){
    int i, j, k, aux, flag;
    k = 0;
    for (i = 1; i < TAMANHO; i++){
        flag = 0;
        for (j = 0; j < (TAMANHO - i); j++){
            if(array[j] > array[j+1]){
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
                escreve_vetor(array, "Bubble Sort");
                printf("\nI : %d, J: %d, K: %d\t", i, j, k);
                flag = 1;
            }
            k++;
        }
        if(!flag) {return;}
    }
}