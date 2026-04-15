#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

// -------- Funções gerais --------
	void criaVet(int* vet, int tam) {
	    int i;
	    for (i = 0; i < tam; i++) {
	        vet[i] = rand() % (tam + 1000);
	    }
	}
	
	void printVet(int* vet, int tam) {
	    int i;
	    for (i = 0; i < tam; i++) {
	        printf("%d ", vet[i]);
	    }
	    printf("\n");
	}
	
	void copiaVet(int* orig, int* copia, int tam) {
	    int i;
	    for (i = 0; i < tam; i++) {
	        copia[i] = orig[i];
	    }
	}
	
	double tempoGasto(clock_t inicio, clock_t fim){
		return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
	}
// -------- Funções gerais --------


int main(){
	// Garantindo que toda vez que o programa executar a geracão dos números será diferente
	srand(time(NULL));
	
	//Criando vetores desordenados
	int *vetA = (int*) malloc(1000 * sizeof(int));
    int *vetB = (int*) malloc(10000 * sizeof(int));
    int *vetC = (int*) malloc(100000 * sizeof(int));
	criaVet(vetA, 1000);
	criaVet(vetB, 10000);
	criaVet(vetC, 100000);
	
	//Criando cópia dos vetores para ordernar
	int *copiaA = (int*) malloc(1000 * sizeof(int));
    int *copiaB = (int*) malloc(10000 * sizeof(int));
    int *copiaC = (int*) malloc(100000 * sizeof(int));
	copiaVet(vetA, copiaA, 1000);
	copiaVet(vetB, copiaB, 10000);
	copiaVet(vetC, copiaC, 100000);
	
	// Verificação de segurança (caso falte memória no PC)
    if (vetA == NULL || vetB == NULL || vetC == NULL) {
        printf("[Erro ao alocar memoria] ARMAZENAMENTO INSUFICIENTE!\n");
        return 1;
    }
	
	//Criando variáveis para calcular o tempo em segundos
	clock_t inicio, fim;
	
	//--------------- Calculando tempo do insertion sort -------------------
		printf("Rodando Insertion Sort...\n");
	
		double insertionA, insertionB, insertionC;
		
		inicio = clock();
		insertionSort(copiaA, 1000);
		fim = clock();
		insertionA = tempoGasto(inicio, fim);
		
		inicio = clock();
		insertionSort(copiaB, 10000);
		fim = clock();
		insertionB = tempoGasto(inicio, fim);
		
		inicio = clock();
		insertionSort(copiaC, 100000);
		fim = clock();
		insertionC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do insertion sort -------------------
	
		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do selection sort -------------------
		printf("Rodando Selection Sort...\n");
	
		double selectionA, selectionB, selectionC;
		
		inicio = clock();
		selectionSort(copiaA, 1000);
		fim = clock();
		selectionA = tempoGasto(inicio, fim);
		
		inicio = clock();
		selectionSort(copiaB, 10000);
		fim = clock();
		selectionB = tempoGasto(inicio, fim);
		
		inicio = clock();
		selectionSort(copiaC, 100000);
		fim = clock();
		selectionC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do selection sort -------------------
	
		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do bubble sort -------------------
		printf("Rodando Bubble Sort...\n");
	
		double bubbleA, bubbleB, bubbleC;
		
		inicio = clock();
		bubbleSort(copiaA, 1000);
		fim = clock();
		bubbleA = tempoGasto(inicio, fim);
		
		inicio = clock();
		bubbleSort(copiaB, 10000);
		fim = clock();
		bubbleB = tempoGasto(inicio, fim);
		
		inicio = clock();
		bubbleSort(copiaC, 100000);
		fim = clock();
		bubbleC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do bubble sort -------------------

		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do merge sort -------------------
		printf("Rodando Merge Sort...\n");
	
		double mergeA, mergeB, mergeC;
		
		inicio = clock();
		mergeSort(copiaA, 0, 999);
		fim = clock();
		mergeA = tempoGasto(inicio, fim);
		
		inicio = clock();
		mergeSort(copiaB, 0, 9999);
		fim = clock();
		mergeB = tempoGasto(inicio, fim);
		
		inicio = clock();
		mergeSort(copiaC, 0, 99999);
		fim = clock();
		mergeC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do merge sort -------------------

		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do heapy sort -------------------
		printf("Rodando Heapy Sort...\n");
	
		double heapyA, heapyB, heapyC;
		
		inicio = clock();
		heapySort(copiaA, 1000);
		fim = clock();
		heapyA = tempoGasto(inicio, fim);
		
		inicio = clock();
		heapySort(copiaB, 10000);
		fim = clock();
		heapyB = tempoGasto(inicio, fim);
		
		inicio = clock();
		heapySort(copiaC, 100000);
		fim = clock();
		heapyC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do heapy sort -------------------

		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do quick sort -------------------
		printf("Rodando Quick Sort...\n");
	
		double quickA, quickB, quickC;
		
		inicio = clock();
		quickSort(copiaA, 0, 999);
		fim = clock();
		quickA = tempoGasto(inicio, fim);
		
		inicio = clock();
		quickSort(copiaB, 0, 9999);
		fim = clock();
		quickB = tempoGasto(inicio, fim);
		
		inicio = clock();
		quickSort(copiaC, 0, 99999);
		fim = clock();
		quickC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do quick sort -------------------
	
		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do counting sort -------------------
		printf("Rodando Counting Sort...\n");
	
		double countingA, countingB, countingC;
		
		inicio = clock();
		countingSort(copiaA, 1000, 2000);
		fim = clock();
		countingA = tempoGasto(inicio, fim);
		
		inicio = clock();
		countingSort(copiaB, 10000, 20000);
		fim = clock();
		countingB = tempoGasto(inicio, fim);
		
		inicio = clock();
		countingSort(copiaC, 100000, 200000);
		fim = clock();
		countingC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do counting sort -------------------

		//Desordenando o vetor
		copiaVet(vetA, copiaA, 1000);
		copiaVet(vetB, copiaB, 10000);
		copiaVet(vetC, copiaC, 100000);
		//Desordenando o vetor
	
	//--------------- Calculando tempo do radix sort -------------------
		printf("Rodando Radix Sort...\n");
	
		double radixA, radixB, radixC;
		
		inicio = clock();
		radixSort(copiaA, 1000);
		fim = clock();
		radixA = tempoGasto(inicio, fim);
		
		inicio = clock();
		radixSort(copiaB, 10000);
		fim = clock();
		radixB = tempoGasto(inicio, fim);
		
		inicio = clock();
		radixSort(copiaC, 100000);
		fim = clock();
		radixC = tempoGasto(inicio, fim);
	//--------------- Calculando tempo do radix sort -------------------
	
	// ----------- Criando a tabela e exibindo resultados -----------
		printf("...\n");
		printf("--------------------------------------------------\n");
	
		printf("Sort\t\tVetor 1k\tVetor 10k\tVetor 100k\n");
	    printf("Insertion\t%lf s\t%lf s\t%lf s\n", insertionA, insertionB, insertionC);
	    printf("Selection\t%lf s\t%lf s\t%lf s\n", selectionA, selectionB, selectionC);
	    printf("Bubble   \t%lf s\t%lf s\t%lf s\n", bubbleA, bubbleB, bubbleC); 
	    printf("Merge    \t%lf s\t%lf s\t%lf s\n", mergeA, mergeB, mergeC);   
	    printf("Heap     \t%lf s\t%lf s\t%lf s\n", heapyA, heapyB, heapyC);   
	    printf("Quick    \t%lf s\t%lf s\t%lf s\n", quickA, quickB, quickC);   
	    printf("Counting \t%lf s\t%lf s\t%lf s\n", countingA, countingB, countingC); 
	    printf("Radix    \t%lf s\t%lf s\t%lf s\n", radixA, radixB, radixC);  
	    
	    printf("--------------------------------------------------\n");
	// ----------- Criando a tabela e exibindo resultados ----------- 
    
    // ----------- Limpando a memória -----------
	    free(vetA); 
		free(vetB); 
		free(vetC);
	    free(copiaA); 
		free(copiaB); 
		free(copiaC);
	// ----------- Limpando a memória -----------
}
