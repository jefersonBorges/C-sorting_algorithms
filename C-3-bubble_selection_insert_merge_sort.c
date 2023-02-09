//Implementar com 50, 100, 150 e 200K registros e verificar o tempo

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

#define TAM 50000
//#define TAM 100000
//#define TAM 150000
//#define TAM 200000

//#define TAM 10
#define RAND 10

/**
 * @brief Cria os valores aleatórios para inserir no array de tamanho pré-definido
 * 
 * @param A Array a ser preenchido de valores aleatórios
 */
void montar_vetor(int A[]){//ok
    int i,k;
    k = 0;
    
    srand(time(NULL));
    for(i = 0; i < TAM; i++){
        A[i] = rand()%(RAND + 1);
        //printf("\nPos %d, valor %d",k, A[i]); //verificar o valor e local
        k++;
    }
}

/**
 * @brief Função que escreve os valores de um array
 * 
 * @param A Array que se deseja escrever
 * @param msg Mensagem a ser exibida
 */
void escreve_vetor(int A[], char *msg){//ok
    printf("\n*** INICIO %s ***\n", msg);
    for(int i = 0; i < TAM; i++){
        if(i == 0){
            printf("%d", A[i]);
        } else { printf(", %d", A[i]); }
    }
    printf("\n*** FIM %s *** \n\n", msg);
}

/**
 * @brief Função que executa ordenação Bubble sort em um array e imprime o tempo de execução em ms
 * 
 * @param array Array a ser ordenado
 */
void bubble_sort(int array[]){ //ok
    int i, j, aux;
    double diferenca;
    clock_t inicio, final;
    inicio = clock();
    for(i = 1; i < TAM; i++){

        for(j = 0; j < (TAM - i); j++){
            if(array[j] > array[(j + 1)]){
                aux = array[j];
                array[j] = array[(j + 1)];
                array[(j + 1)] = aux;
            }
        }
    }
    final = clock();
    diferenca = final - inicio;
    printf("\n\n*** VIEW Bubble Sort - Tempo de Execucao ***");
    printf("\n\t*** Registros: %d", TAM);
    printf("\n\t*** Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    printf("\n*** DONE Bubble Sort - Tempo de Execucao ***");
}

/**
 * @brief Função que ordena um array utilizando Selection sort e imprime o tempo de execução em ms
 * 
 * @param array Array a ser ordenado
 */
void selection_sort(int array[]){ //ok
    clock_t inicio, final;
    double diferenca;

    inicio = clock();
    int i, j, menor, aux;
    for(i = 0; i < TAM; i++){
        menor = i;
        for(j = (i + 1); j < TAM; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
            aux = array[menor];
            array[menor] = array[i];
            array[i] = aux;
        }
    }
    final = clock();

    diferenca = final - inicio;
    printf("\n\n*** VIEW Selection Sort - Tempo de Execucao ***");
    printf("\n\t*** Registros: %d", TAM);
    printf("\n\t*** Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    printf("\n*** DONE Selection Sort - Tempo de Execucao ***\n\n");
}

/**
 * @brief  Função que ordena um array utilizando Insertion sort e imprime o tempo de execução em ms
 * 
 * @param array Array a ser ordenado
 */
void insertion_sort(int array[]){
    clock_t inicio, final;
    double diferenca;

    inicio = clock();
    int i, j, key;
    for (j = 1; j < TAM; j++){
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key){
            array[(i + 1)] = array[i];
            i = i - 1;
        }
        array[(i + 1)] = key;
    }
    final = clock();

    diferenca = final - inicio;
    printf("\n\n*** VIEW Insertion Sort - Tempo de Execucao ***");
    printf("\n\t*** Registros: %d", TAM);
    printf("\n\t*** Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    printf("\n*** DONE Insertion Sort - Tempo de Execucao ***\n\n");
}

/**
 * @brief Algoritmo que utiliza a estratégia do merge para ordenar o vetor.
 * 
 * @param array Array a ser ordenado
 * @param inicio Posicao inicial do array
 * @param meio Posicao do meio do array
 * @param fim Posicao do fim do array
 */
void merge(int array[], int inicio, int meio, int fim){
    int i, j, k, n1, n2;

    n1 = (meio - inicio + 1);
    n2 = (fim - meio);

    int E[(n1 + 1)];
    int D[(n2 + 1)];

    for(i = 0; i < n1; i++){ E[i] = array[(inicio + i)]; }

    for(j = 0; j < n2; j++){ D[j] = array[(meio + j + 1)]; }

    E[n1] = INT_MAX;
    D[n2] = INT_MAX;

    i = 0; j = 0;

    for(k = inicio; k <= fim; k++){
        if(E[i] <= D[j]){
            array[k] = E[i];
            i++;
        } else {
            array[k] = D[j];
            j++;
        }
    }
}

/**
 * @brief Função que faz as chamadas recursivas para a função merge_sort e aplica a função merge quando necessário. Aponta o tempo de execução em ms.
 * 
 * @param array Array a ser ordenado
 * @param inicio Posicao do inicio do array
 * @param fim Posicao do final do array
 */
void merge_sort(int array[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim) / 2);
        merge_sort(array, inicio, meio);
        merge_sort(array, (meio + 1), fim);
        merge(array, inicio, meio, fim);
    }
}

int main(){

    int A[TAM];

    montar_vetor(A);
    //escreve_vetor(A, "vetor sem ordenacao");

    bubble_sort(A);
    //escreve_vetor(A, "vetor ordenado bubble-sort");

    /*selection_sort(A);
    //escreve_vetor(A, "vetor ordenado selection-sort");*/

    /*insertion_sort(A);
    //escreve_vetor(A, "vetor ordenado com insertion-sort");*/

    /*clock_t t_inicio, t_final; //merge-sort
    double diferenca;

    t_inicio = clock();
    merge_sort(A, 0, (TAM - 1));
    t_final = clock();

    diferenca = t_final - t_inicio;
    printf("\n*** VIEW Merge Sort - Tempo de Execucao ***");
    printf("\n\t*** Registros: %d", TAM);
    printf("\n\t*** Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    printf("\n*** DONE Merge Sort - Tempo de Execucao ***\n\n");
    //escreve_vetor(A, "vetor ordenado com merge-sort");*/
    
    return 0;
}