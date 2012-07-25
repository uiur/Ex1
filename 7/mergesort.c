#include <stdio.h>
#include <stdlib.h>
#define MAX_N 9999
#define MAX_INPUT 50
#define MAX_OUTPUT 10

void msort(int array[], int left, int right);
void merge(int array[], int left, int right);
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
  msort(array, 0, n-1);
  output(array, n);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void msort(int array[], int left, int right) {
  if (left + 1 == right) {
    if (array[left] > array[right])
      swap(&array[left], &array[right]);
    return;
  } else if (left == right) {
    return;
  }
  msort(array, left, (left + right) / 2);
  msort(array, (left + right) / 2 + 1, right);
  merge(array, left, right);
}

void merge(int array[], int left, int right) {
  int tempArray[right - left + 1];
  int i, m = (left + right) / 2, l = left, r = m + 1;

  for (i = 0; i < right - left + 1; i++) {
    if (l > m) {
      while (r <= right) {
        tempArray[i++] = array[r++];
      }
      break;
    }

    if (r > right) {
      while (l <= m) {
        tempArray[i++] = array[l++];
      }
      break;
    }

    if (array[l] < array[r]) {
      tempArray[i] = array[l++];
    } else {
      tempArray[i] = array[r++];
    }
  }

  for (i = 0; i < right - left + 1; i++) {
    array[left + i] = tempArray[i];
  }
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

  msort(a1, 0, 4);
  assert(sorted(a1, 5));
  showArray(a1, 5);

  msort(a2, 0, 0);
  assert(sorted(a2, 1));
  showArray(a2, 1);

  msort(a3, 0, 3);
  assert(sorted(a3, 4));
  showArray(a3, 4);

  msort(a4, 0, 5);
  assert(sorted(a4, 6));
  showArray(a4, 6);

}

