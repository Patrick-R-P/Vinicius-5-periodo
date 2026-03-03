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


//Complexidade: O(n log n) em todos os casos
//Divide o array ao meio recursivamente e mescla as partes ja ordenadas (dividir para conquistar).
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1; //Subarray esquerdo
    int n2 = r - m;     //Subarray direito

    vector<int> L(n1), R(n2); //Arrays temporarios

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    //Mescla os temporarios de volta em arr
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else               { arr[k] = R[j]; j++; }
        k++;
    }
    //Copia os elementos restantes 
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

//Funcao recursiva auxiliar do Merge Sort
void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l >= r) return; 
    int m = l + (r - l) / 2;   //Ponto medio 
    mergeSortHelper(arr, l, m);     //Metade esquerda
    mergeSortHelper(arr, m + 1, r); //Metade direita
    merge(arr, l, m, r);            //Mescla as duas metades
}

//Funcao principal do Merge Sort 
void mergeSort(vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}
