/*
 * iamback.c
 *
 *  Created on: Dec 19, 2020
 *      Author: abnerjcorreajr
 */

#include <stdio.h>
#include <stdlib.h>

void show_array(int a[], int n) {
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}

void swap(int *a, int i1, int i2) {
	if (i1 == i2) return;

	a[i1] ^= a[i2];
	a[i2] ^= a[i1];
	a[i1] ^= a[i2];
}

/**
 * Two-way partitioning
 */
void quicksort(int *a, int s, int e) {
	if (s >= e) return;

	int pivot = a[s], i = s + 1, j = e;

	do {
		for (; a[i] < pivot && i < e; i++);
		for (; a[j] > pivot; j--);
		if (i < j) swap(a, i++, j--);
	}
	while (i < j);

	swap(a, s, j);

	quicksort(a, s, j - 1);
	quicksort(a, j + 1, e);
}

int main() {
	int n = 30;
	int *v = (int*) malloc(sizeof(int) * n);

	for (int i = 0, j = n; i < n; i++, j--) v[i] = j * j;

	show_array(v, n);

	quicksort(v, 0, n - 1);

	show_array(v, n);

	return 0;
}
