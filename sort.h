#ifndef SORT_H
#define SORT_H

// Função Auxiliar
void swap(int* a, int* b);

// Algoritmos de Ordenação
void selectionSort(int* vet, int tam);
void insertionSort(int* vet, int tam);
void bubbleSort(int* vet, int tam);
void mergeSort(int* v, int i, int f);
void heapySort(int* v, int n);
void quickSort(int* v, int p, int r);
void countingSort(int* v, int n, int k);
void radixSort(int* v, int n);

#endif
