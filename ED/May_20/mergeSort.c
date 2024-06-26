#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void imprimirArray(int A[], int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
  int arr[] = {10,  7,  8,    9,   1,  5,  22,  4,   55,  67,  91, 1, 89,
               100, 95, 2109, 782, 78, 61, 278, 567, 892, 567, 21, 73};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Array dado é \n");
  imprimirArray(arr, arr_size);

  mergeSort(arr, 0, arr_size - 1);

  printf("\nArray ordenado é \n");
  imprimirArray(arr, arr_size);
  return 0;
}
