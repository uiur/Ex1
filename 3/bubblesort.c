#include <stdio.h> 
#include <stdlib.h>
#define MAX_N 9999
#define MAX_INPUT 50
#define MAX_OUTPUT 10

void bubblesort(int array[], int n);
void swap(int *a, int *b);
int input(int *array);
void output(int *array, int n);
// Test
int sorted(int array[], int n);
void assert(int t);
void showArray(int array[], int n);
void test_all(void);

int main(void) {
  int array[MAX_N];
  int n = input(array);
  bubblesort(array, n);
  output(array, n);

  return 0;
}

// 入力行数を返す
int input(int *array) {
  char buf[100];
  int i = 0;

  while(fgets(buf, MAX_N, stdin) != NULL) {
    sscanf(buf, "%d\n", &array[i]);
    if (!(1 <= array[i] && array[i] <= MAX_N)) {
      printf("おいおい、入力エラーしとるやんけ: %d\n", array[i]);
      exit(1);
    }
    i++;
  }

  if (MAX_INPUT < i) {
    printf("おいおい、入力数がおおすぎるぞ: %dコもあるやんけ\n", i);
    exit(1);
  }

  return i;
}

void output(int *array, int n) {
  int i;
  for(i = 0; i < n; i++) {
    if ((i+1) % MAX_OUTPUT == 0) {
      printf("%d\n", array[i]);
    } else {
      printf("%d ", array[i]);
    }
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(int array[], int n) {
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1; j++) 
      if (array[j] > array[j+1])
        swap(&array[j], &array[j+1]);

}

// Test
void assert(int t) {
  if (!t) {
    printf("Test Failed!\n");
  }
}

int sorted(int array[], int n) {
  int i;
  for (i = 0; i < n - 1; i++)
    if (array[i] > array[i+1])
      return 0;

  return 1;
}

void showArray(int array[], int n) {
  int i;

  for (i = 0; i < n - 1; i++) 
    printf("%d ", array[i]);

  printf("%d\n", array[n-1]);
}

void test_all(void) {
  int array[] = {5,3,2,7,9};

  bubblesort(array, 5);
  assert(sorted(array, 5));
}

