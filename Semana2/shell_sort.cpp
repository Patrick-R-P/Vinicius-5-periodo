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

//Gera inteiros aleatorios
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

//Complexidade: aprox O(n log^2 n) com a sequencia usada
//Generalizacao do Insertion Sort que compara elementos distantes, reduzindo o gap progressivamente ate 1.

void shellSort(vector<int>& arr) {
    int n = arr.size();
    //Começa com gap grande e reduz pela metade a cada iteracao
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            //Desloca elementos anteriores ate encontrar posicao correta
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
