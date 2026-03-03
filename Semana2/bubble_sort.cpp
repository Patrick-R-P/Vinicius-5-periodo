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

//Complexidade: O(n^2) no pior caso
//Compara pares adjacentes e troca se necessario, "borbulhando" o maior elemento para o final a cada passagem.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        //Cada iteracao garante que a posicao (n-1-i) esta correta
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //Troca elementos fora de ordem
            }
        }
    }
}