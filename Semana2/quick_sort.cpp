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

//Complexidade: O(n log n) em media, O(n^2) no pior caso
//Divide o array em particoes usando um pivo e ordena recursivamente cada particao (dividir para conquistar). Reorganiza o array em torno do pivo (ultimo elemento) Retorna o indice final do pivo apos o particionamento
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; //Pivo escolhido como ultimo elemento
    int i = (low - 1);     //Indice do menor elemento
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); //Move elemento menor para a esquerda do pivo
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
}

//Funcao recursiva auxiliar do Quick Sort
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); //Indice do pivo apos particionar
        quickSortHelper(arr, low, pi - 1);  //Particao esquerda
        quickSortHelper(arr, pi + 1, high); //Particao direita
    }
}

//Funcao principal do Quick Sort
void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}