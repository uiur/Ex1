#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} List;

void insert(List *l, int n);
List* newList(int n);
void showList(List *l);

int main(void) {
  List *l = newList(1);
  insert(l, 10);
  insert(l, 2);
  insert(l, 9);
  insert(l, 3);

  showList(l);

  return 0;
}

List* newList(int n) {
  List *l = (List *)malloc(sizeof(List));
  l->data = n;
  l->next = NULL;

  return l;
}

void insert(List *l, int n) {
  List *current = l, *next = l->next, *nl;
  nl = (List *)malloc(sizeof(List));
  nl->data = n;

  while (next != NULL) {
    if (next->data >= n) {
      current->next = nl;
      nl->next = next;
      return;
    }

    current = next;
    next = current->next;
  }

  current->next = nl;
  nl->next = NULL;
}

void showList(List *l) {
  List *current = l;
  while (1) {
    if (current->next == NULL) {
      printf("%d\n", current->data);
      break;
    }
    printf("%d ", current->data);
    current = current->next;
  }
}
