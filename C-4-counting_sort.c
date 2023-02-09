/**
 * @file counting-sort.c
 * @authors Jeferson Borges
 * @brief Implementação do algorismo counting sort com 10 registros para a disciplina de estrutura de dados.
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright free (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define RANGE 10

#define TAM_10 10

/**
 * @brief Cria os valores aleatórios para inserir no array de tamanho pré-definido
 * 
 * @param A Array a ser preenchido com valores aleatórios
 * @param tamanho_vetor Tamanho do vetor a ser criado
 * @param range lcance dos numeros ( 0 a 9 = 10, 10 a 99 = 100 ....)
 * 
 */
void montar_vetor(int A[], int tamanho_vetor, int range){
    int i,k, valor_aleatorio;
    k = 0;
    
    srand(time(NULL));
    for(i = 0; i < tamanho_vetor; i++){
        valor_aleatorio = rand()%(range + 1); 
        //garante que o valor "Aleatório" fique dentro do range
        A[i] = (valor_aleatorio == range) ? (range - 1): valor_aleatorio;
        k++;
    }
}

/**
 * @brief Le o array informado
 * 
 * @param array Array de inteiros que se deseja realizar a leitura
 * @param tamanho_array Tamanho do array a ser lido
 * @param msg Mensagem que se deseja exibir
 */
void ler_array(int array[], int tamanho_array, char *msg){
    printf("\n********* INICIO LEITURA ARRAY *********");
    //Exibe mensagem com formatação
    printf("\n\t------> %s <------", msg);

    //Para cada linha do array, imprime os valores formatados
    for(int i = 0; i < tamanho_array; i++){
        printf("\n\t Posicao: %d - Numero: %d", i, array[i]);
    }

    //Finaliza a impressão dos valores
    printf("\n\t------> %s <------", msg);
    printf("\n********* FINAL LEITURA ARRAY *********\n\n");
}

/**
 * @brief Algorismo Counting Sort - Ordenação crescente de inteiros
 * 
 * @param array Array a ser ordenado
 * @param tamanho_array Tamanho do array a ser ordenado
 * @param range_numeros Alcance dos numeros ( 0 a 9 = 10, 10 a 99 = 100 ....)
 */
void counting_sort(int array[], int tamanho_array, int range_numeros){

    //O array ordenado da função
    int ordenado[tamanho_array];

    //O array que armazena a contagem de numeros
    int contagem[range_numeros];

    //Inicializa o array de contagem com 0 em todas as posições
    memset(contagem, 0, sizeof(contagem));

    //Armazena a contagem de cada numero do array recebido
    for(int i = 0; i < tamanho_array; i++){ contagem[array[i]]++; }

    //Modifica o array de contagem de forma que contenha a posição do numero no array recebido
    for(int i = 1; i < range_numeros; i++){ contagem[i] += contagem[(i - 1)]; }
    
    //Monta o array de saída ordenado
    int numero_array, posicao_ordenada;
    for(int i = 0; i < tamanho_array ; i++){
        //Procura o valor
        numero_array = array[i];

        //Define a posição no array de contagem, decrementando em um
        posicao_ordenada = contagem[numero_array] - 1;

        //Decrementa o valor no array de contagem
        contagem[numero_array] = posicao_ordenada;

        //coloca o valor em um array ordenado
        ordenado[posicao_ordenada] = numero_array;
    }
    
    //copia o array ordenado para o array de entrada
    for(int i = 0; i < tamanho_array; ++i){ array[i] = ordenado[i]; }
}

int main(){

    //Ordenação valores diáticos
    int vetor[TAM_10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ler_array(vetor,TAM_10, "Vetor Desordenado");
    counting_sort(vetor, TAM_10, RANGE);
    ler_array(vetor, TAM_10, "Vetor Ordenado com Counting Sort");

    return 0;
}