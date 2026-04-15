#include <stdio.h>
#include "sort.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//-------------- Selection Sort ----------------------
void selectionSort(int* vet, int tam){
    int i, j, menor, aux;

    for(i = 0;i < tam;i++){
        menor = i;
        for(j = i+1;j < tam;j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        aux = vet[menor];
        vet[menor] = vet[i];
        vet[i] = aux;
    }
}
//-------------- Selection Sort ----------------------


//-------------- Insertion Sort ----------------------
void insertionSort(int* vet, int tam){
    int i, j, aux;
    for(i = 1;i < tam;i++){
        aux = vet[i];
        for(j = i-1;j >= 0 && aux < vet[j];j--){
            vet[j+1] = vet[j];
        }
        vet[j+1] = aux;
    }
}
//-------------- Insertion Sort ----------------------


//-------------- Bubble Sort ----------------------
void bubbleSort(int* vet, int tam){
    int i,j, aux, condicao;
    for(i = 0;i < tam-1;i++){
        condicao = 1;
        while(condicao){
            for(j = 0;j < tam-1-i;j++){
                if(vet[j] > vet[j+1]){
                    aux = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux;
                    condicao = 1;
                }else{
                    condicao = 0;
                }
            }
        }
    }
}
//-------------- Bubble Sort ----------------------


//-------------- Merge Sort ----------------------
void merge(int* v, int ini, int m, int f){
	int a[f-ini+1], i, j, k;
	for(i=ini, j=m+1, k=0;i <= m && j <= f;k++){
		if(v[i] <= v[j]){
			a[k] = v[i];
			i++;
		}else{
			a[k] = v[j];
			j++;
		}
	}
	for(;j <= f;j++, k++){
		a[k] = v[j];
	}
	for(;i <= m;i++, k++){
		a[k] = v[i];
	}
	for(k=0, i=ini;i <= f;i++, k++){
		v[i] = a[k];
	}
}

void mergeSort(int* v, int i, int f){
	if(i < f){
		int m;
		m = (i+f)/2;
		mergeSort(v, i, m);
		mergeSort(v, m+1, f);
		merge(v, i, m, f);
	}
}
//-------------- Merge Sort ----------------------


//-------------- Heapy Sort ----------------------
void heapify(int* v, int n, int i){
	int r, l, maior;
	l = 2*i+1;
	r = 2*i+2;
	if(l < n && v[l] > v[i]){
		maior = l;
	}else{
		maior = i;
	}
	if(r < n && v[r] > v[maior]){
		maior = r;
	}
	if(maior != i){
		swap(&v[i], &v[maior]);
		heapify(v, n, maior);
	}
}

void buildHeap(int* v, int n){
	for(int i=(n-2)/2;i >= 0;i--){
		heapify(v, n, i);
	}
}

void heapySort(int* v, int n){
	buildHeap(v, n);
	while(n){
		swap(&v[0], &v[n-1]);
		n--;
		heapify(v, n, 0);
	}
}
//-------------- Heapy Sort ----------------------


//-------------- Quick Sort ----------------------
int particion(int* v, int p, int r){
	int i, j, x;
	x = v[p];
	i = p-1;
	j = r+1;
	while(1){
		do{
			j--;
		}while(v[j] > x);
		do{
			i++;
		}while(v[i] < x);
		if(i < j){
			swap(&v[i], &v[j]);
		}else{
			return j;
		}
	}
}

void quickSort(int* v, int p, int r){
	if(p < r){
		int q;
		q = particion(v, p, r);
		quickSort(v, p, q);
		quickSort(v, q+1, r);
	}
}
//-------------- Quick Sort ----------------------


//-------------- Counting Sort ----------------------
void countingSort(int* v, int n, int k){
	int c[k+1];
	for(int i=0;i < k+1;i++){
		c[i] = 0;
	}
	int a[n];
	for(int i=0;i < n;i++){
		c[v[i]]++;
	}
	for(int i=1;i <= k;i++){
		c[i] = c[i-1]+c[i];
	}
	for(int i=n-1;i >= 0;i--){
		a[c[v[i]]-1] = v[i];
		c[v[i]]--;
	}
	for(int i=0;i < n;i++){
		v[i] = a[i];
	}
}
//-------------- Counting Sort ----------------------


//-------------- Radix Sort ----------------------
int getMax(int* v, int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

void countingSortRadix(int* v, int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 
    int i;

    for (i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        v[i] = output[i];
}

void radixSort(int* v, int n){
	int m = getMax(v, n);
	
	for(int exp = 1; m / exp > 0; exp *= 10){
		countingSortRadix(v, n, exp);
	}
}
//-------------- Radix Sort ----------------------
