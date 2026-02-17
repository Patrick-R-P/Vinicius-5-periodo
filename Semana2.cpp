#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void VetorDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}