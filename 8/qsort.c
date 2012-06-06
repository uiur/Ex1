#include <stdio.h> 
#include <stdlib.h>
#define MAX_N 9999
#define MAX_INPUT 50
#define MAX_OUTPUT 10

void qsort2(int *array, int p, int q);
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
  qsort2(array, 0, n-1);
  output(array, n);
//  test_all();

  return 0;
}

// arrayを区間p,qでソートする
// p <= q
void qsort2(int *array, int p, int q) {
  int i, m, pivot = p;

  if (p >= q) 
    return;

  // 先頭から3つとってその中央値をピボットにする
  if (p - q >= 2) {
    for (i = 0; i < 3; i++) {
      if ((array[p+(i-1)%3] < array[i] && array[i] < array[p+(i+1)%3]) || (array[p+(i+1)%3] < array[i] && array[i] < array[p+(i-1)%3])) {
        pivot = p;
      }
    }
  }

  swap(&array[pivot], &array[p]);

  for (i = p+1, m = p; i <= q; i++) {
    if (array[i] < array[p]) {
      swap(&array[++m], &array[i]);
    }
  }

  swap(&array[m], &array[p]);

  swap(&array[pivot], &array[p]);

  qsort2(array, p, m-1);
  qsort2(array, m+1, q);
}

// 入力行数を返す
int input(int *array) {
  char buf[100];
  int i = 0;

  while(fgets(buf, MAX_N, stdin) != NULL) {
    sscanf(buf, "%d\n", &array[i]);
    if (!(1 <= array[i] && array[i] <= MAX_N)) {
      fprintf(stderr, "おいおい、入力エラーしとるやんけ: %d\n", array[i]);
      exit(1);
    }
    i++;
  }

  if (MAX_INPUT < i) {
    fprintf(stderr, "おいおい、入力数がおおすぎるぞ: %dコもあるやんけ\n", i);
    exit(1);
  }

  return i;
}

void output(int *array, int n) {
  int i;
  for(i = 0; i < n; i++) {
    if ((i+1) % MAX_OUTPUT == 0) {
      printf("%5d\n", array[i]);
    } else {
      printf("%5d", array[i]);
    }
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
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
  int a1[] = {5,3,2,7,9}, a2[] = {1}, a3[] = {5,4,3,2}, a4[] = {8,8,8,8,8,8};

  qsort2(a1, 0, 4);
  assert(sorted(a1, 5));
  showArray(a1, 5);

  qsort2(a2, 0, 0);
  assert(sorted(a2, 1));
  showArray(a2, 1);

  qsort2(a3, 0, 3);
  assert(sorted(a3, 4));
  showArray(a3, 4);

  qsort2(a4, 0, 5);
  assert(sorted(a4, 6));
  showArray(a4, 6);

}

