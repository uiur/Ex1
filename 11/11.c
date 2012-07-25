#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000
#define MAX_OUTPUT 10
#define FUNC_N 2

void swap(int *a, int *b);
void bubblesort(int *array, int n);
void qsort2(int *array, int p, int q);
void w_qsort2(int *array, int n);
void input(int *array, int *n);
void output(int *array, int n);


int main(int argc, char *argv[]) {
  char buf[1000];
  int array[MAX_N];
  int n, func_i;

  void (*func[FUNC_N])(int *, int) = { bubblesort, w_qsort2 };

  // batch mode
  if (argc >= 2) {
    sscanf(argv[1], "%d", &func_i);
  } else {
    fgets(buf, 1000, stdin);
    sscanf(buf, "%d", &func_i);
  }

  if (!(0 <= func_i && func_i < FUNC_N)) {
    fprintf(stderr, "そのソーティングモジュール番号は不正です: %d\n", func_i);
    exit(1);
  }

  input(array, &n);
  func[func_i](array, n);
  output(array, n);

  return 0;
}

// 入力行数を返す
void input(int *array, int *n) {
  char buf[MAX_N];
  int i = 0, start_i, read_i;

  while(fgets(buf, MAX_N, stdin) != NULL) {
    start_i = read_i = 0;
    while (sscanf(buf + start_i, "%d %n", &array[i++], &read_i) != EOF) {
      start_i += read_i;
    }
  }

  *n = i;
}

void output(int *array, int n) {
  int i;
  for(i = 0; i < n; i++) {
    if ((i+1) % MAX_OUTPUT == 0) {
      printf("%8d\n", array[i]);
    } else {
      printf("%8d", array[i]);
    }
  }
  printf("\n");
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

void w_qsort2(int *array, int n) {
  qsort2(array, 0, n - 1);
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


