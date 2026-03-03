#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


//Funcoes Auxiliares 
void printArray(const vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Retorna uma copia identica do array original, garante que todos os algoritmos sejam testados com os mesmos dados
vector<int> copyArray(const vector<int>& original) {
    return original;
}

//Gera inteiros aleatorios entre 0 e 9999
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}



//Complexidade: O(n^2) em todos os casos
//Encontra o menor elemento da parte nao ordenada e o coloca na posicao correta a cada iteracao.
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; //Assume que o menor e o primeiro da parte nao ordenada
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; //Atualiza o indice do menor elemento encontrado
            }
        }
        swap(arr[i], arr[min_idx]); //Coloca o menor na posicao correta
    }
}