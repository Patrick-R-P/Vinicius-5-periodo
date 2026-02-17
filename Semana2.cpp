#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void VetorDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}
void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    *comparacoes = 0;
    *movimentacoes = 0;
    int temp;
    
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*movimentacoes) += 3;
            }
        }
    }
}
void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    *comparacoes = 0;
    *movimentacoes = 0;
    int min_idx, temp;
    
    for (int i = 0; i < tamanho - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = vetor[i];
            vetor[i] = vetor[min_idx];
            vetor[min_idx] = temp;
            (*movimentacoes) += 3;
        }
    }
}