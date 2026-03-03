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
//Complexidade: O(n^2) no pior caso, O(n) no melhor caso
//Constroi o array ordenado um elemento por vez, inserindo cada novo elemento na posicao correta.

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; //Elemento a ser inserido
        int j = i - 1;
        //Desloca os elementos maiores que 'key' uma posicao a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; //Insere o elemento na posicao correta
    }
}
//Complexidade: O(n log n) em media, O(n^2) no pior caso
//Divide o array em particoes usando um pivo e ordena recursivamente cada particao (dividir para conquistar).
//Reorganiza o array em torno do pivo (ultimo elemento). Retorna o indice final do pivo apos o particionamento
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
//Complexidade: aprox O(n log^2 n) com a sequencia usada
//Generalizacao do Insertion Sort que compara elementos distantes, reduzindo o gap progressivamente ate 1.

void shellSort(vector<int>& arr) {
    int n = arr.size();
    //Comeca com gap grande e reduz pela metade a cada iteracao
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

//Executa todos os algoritmos com o mesmo array original para comparacao justa
void runAllAlgorithms(const vector<int>& originalArray, int size) {
    string names[6] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort", "Shell Sort"};

    cout << "\n--------------------------------------------------" << endl;
    cout << "  Comparacao de todos os algoritmos" << endl;
    cout << "  Tamanho do array: " << size << " elementos" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 1; i <= 6; i++) {
        //Cada algoritmo recebe uma copia identica do array original
        vector<int> testArray = copyArray(originalArray);

        if (size <= 50) {
            cout << "\nArray original: ";
            printArray(testArray);
        }

        //Inicia medicao de tempo
        clock_t start = clock();

        switch (i) {
            case 1: bubbleSort(testArray);    break;
            case 2: selectionSort(testArray); break;
            case 3: insertionSort(testArray); break;
            case 4: quickSort(testArray);     break;
            case 5: mergeSort(testArray);     break;
            case 6: shellSort(testArray);     break;
        }

        //Finaliza medicao de tempo
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        if (size <= 50) {
            cout << "Array ordenado: ";
            printArray(testArray);
        }

        cout << names[i - 1] << ": " << fixed << duration << " segundos." << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Funcao Principal - Menu Interativo
int main() {
    srand(time(0)); //Semente baseada no tempo para aleatoriedade
    int size;

    cout << "==================================================" << endl;
    cout << "   Sistema de Teste de Algoritmos de Ordenacao   " << endl;
    cout << "==================================================" << endl;
    cout << "Digite o tamanho do array para o teste: ";
    cin >> size;

    //Gera o array original (reutilizado em todos os testes)
    vector<int> originalArray = generateRandomArray(size);
    vector<int> testArray;

    int choice;
    do {
        cout << "\nSelecione o algoritmo para testar:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Merge Sort" << endl;
        cout << "6. Shell Sort" << endl;
        cout << "7. Comparar todos os algoritmos" << endl;
        cout << "8. Sair" << endl;
        cout << "Escolha: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            //Copia o array original para garantir comparacao justa entre algoritmos
            testArray = copyArray(originalArray);

            //Exibe array apenas para tamanhos pequenos 
            if (size <= 50) {
                cout << "\nArray original: ";
                printArray(testArray);
            }

            //Inicia medicao de tempo
            clock_t start = clock();

            switch (choice) {
                case 1: bubbleSort(testArray);    break;
                case 2: selectionSort(testArray); break;
                case 3: insertionSort(testArray); break;
                case 4: quickSort(testArray);     break;
                case 5: mergeSort(testArray);     break;
                case 6: shellSort(testArray);     break;
            }

            //Finaliza medicao de tempo
            clock_t end = clock();
            double duration = double(end - start) / CLOCKS_PER_SEC;

            if (size <= 50) {
                cout << "Array ordenado: ";
                printArray(testArray);
            }

            cout << "Tempo de execucao: " << fixed << duration << " segundos." << endl;

        } else if (choice == 7) {
            //Executa todos os algoritmos com o mesmo array para comparacao justa
            runAllAlgorithms(originalArray, size);

        } else if (choice != 8) {
            cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (choice != 8);

    cout << "\nPrograma encerrado." << endl;
    return 0;
}
