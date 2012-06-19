#include <stdio.h>
#include <stdlib.h>

#define MIN_N 1
#define MAX_N 9999

typedef struct list {
  int data;
  struct list *next;
} List;

void insert(List **l, int n);
void delete(List **l, int n);
void addTail(List **l, int n);
void removeTail(List **l);
void showList(List *l);

// Input
int readOne(void);

int main(void) {
  int i, n;
  List *l = NULL;

  for (i = 0; i < 10; i++) {
    n = readOne();
    addTail(&l, n);
  }
  showList(l);

  for (i = 0; i < 10; i++) {
    n = readOne();
    insert(&l, n);
    showList(l);
  }
 
  for (i = 0; i < 10; i++) {
    n = readOne();
    delete(&l, n);
    showList(l);
  }

  while (l != NULL) {
    removeTail(&l);
  }

  return 0;
}

void insert(List **l, int n) {
  List *prev = NULL, *current = *l, *nl;
  nl = (List *)malloc(sizeof(List));
  nl->data = n;

  while (current != NULL) {
    if (current->data >= n) {
      if (prev != NULL) {
        prev->next = nl;
      } else {
        *l = nl;
      }
      nl->next = current;
      return;
    }

    prev = current;
    current = current->next;
  }

  prev->next = nl;
  nl->next = NULL;
}

void delete(List **l, int n) {
  List *prev = NULL, *current = *l, *temp;
  while (current != NULL) {
    if (current->data == n) {
      if (prev != NULL) {
        prev->next = current->next; 
      } else {
        *l = current->next;
      }
      temp = current->next;
      free(current);
      current = temp;
      continue;
    }
    prev = current;
    current = current->next;
  }
}

void addTail(List **l, int n) {
  List *current = *l, *nl = (List *)malloc(sizeof(List));
  nl->data = n;
  nl->next = NULL;

  if (current == NULL) {
    *l = nl;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = nl;
}

void removeTail(List **l) {
  List *current = *l, *prev = NULL;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  if (prev != NULL) {
    prev->next = NULL;
    free(current);
  } else {
    free(current);
    *l = NULL;
  }

}

void showList(List *l) {
  List *current = l;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Input
int readOne(void) {
  int n;
  fscanf(stdin, "%d", &n);
  if (!(MIN_N <= n && n <= MAX_N)) {
    fprintf(stderr, "Invalid Input: %d\n", n);
    exit(1);
  }

  return n;
}
