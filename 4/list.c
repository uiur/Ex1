#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *next;
} List;

void insert(List *l, int n);
void delete(List **l, int n);
List* newList(int n);
void showList(List *l);

int main(void) {
  List *l = newList(1);
  insert(l, 10);
  insert(l, 2);
  insert(l, 9);
  insert(l, 3);
  insert(l, 9);
  showList(l);

  delete(&l, 9);
  showList(l);

  delete(&l, 1);
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
  List *prev = NULL, *current = l, *nl;
  nl = (List *)malloc(sizeof(List));
  nl->data = n;


  while (current != NULL) {
    if (current->data >= n) {
      if (prev != NULL) 
        prev->next = nl;
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
