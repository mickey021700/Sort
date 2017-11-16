#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"sort.h"
void PrintArray(int* base,int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", base[i]);
	}
}
void InitRandomArray(int* base, int n) {
	for (int i = 0; i < n; i++) {
		base[i] = rand() % n;
	}
}
bool isSorted(int* base, int n) {
	for (int i = 1; i < n; i++) {
		if (base[i-1] > base[i]) {
			return false;
		}
	}
	return true;
}
int IntCompare(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}
int main() {
	srand((unsigned)time(NULL));
	int n = 10000;
	int* arr=(int*)calloc(n,sizeof(int));
	InitRandomArray(arr, n);
	//qsort(arr, n, sizeof(int), IntCompare);
	BubbleSort(arr, n);
	bool b=isSorted(arr, n);
	if(b==true){
		puts("sorted");
	}
	else {
		puts("unsorted");
	}
	//PrintArray(arr, n);
	return 0;
}