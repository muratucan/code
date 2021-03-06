#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

typedef int (*ti_comp)(int, int);
int i_comp (int a, int b);
void insert_sort(int *data, int size, ti_comp comp);
void swap(int* data, int a, int b);

int main (int argc, char **argv) {
  int i;
  int* data = (int*)malloc((argc - 1) * sizeof(int));
  for (i = 1; i < argc; i++)
    data[i-1] = atoi(argv[i]);
    
  insert_sort(data, argc - 1, &i_comp);
  
  for (i = 0; i < argc - 1; i++)
    printf("%d ", data[i]);
}

int i_comp (int a, int b) {
  return a - b;
}

void insert_sort (int *arr, int size, ti_comp comp) {
  if ((arr != NULL) & (size > 1) && (comp != NULL)) {
    int i, j;
    for (i = 1; i < size; i++) 
      for (j = i; (j > 0) && ((*comp)(arr[j], arr[j-i]) < 0); j--) 
	swap(arr, j, j-1);
  }
}

void swap (int* data, int a, int b) {
  int t = data[a];
  data[a] = data[b];
  data[b] = t;
}

