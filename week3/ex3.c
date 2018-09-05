#include <printf.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    long value;
};
typedef struct Node Node;

struct List_Int {
    int size;
    Node *head;
}List_Int_Default  = {0, NULL};
typedef struct List_Int List;


int insert_node(List *list, long value, int index) {
    if (index > list->size) return 1;
    if (list->head == NULL) {
        list->head = malloc(sizeof(Node));
        list->head->value = value;
        list->size++;
        return 0;
    }
    Node *new = malloc(sizeof(Node));
    new->value = value;

    if (index == 0) {
        Node *temp = malloc(sizeof(Node));
        temp->next = list->head->next;
        temp->value = list->head->value;
        new->next = temp;
        list->head = new;
        list->size++;
        return 0;
    }

    Node *toInsertAfter = list->head;
    for (int i = 1; i < index - 1; ++i) {
        toInsertAfter = toInsertAfter->next;
    }

    new->next = toInsertAfter->next;
    toInsertAfter->next = new;

    list->size++;
    return 0;
}

int delete_node(List *list, int index) {
    if (index > list->size - 1) return 1;
    if (list->head->next == NULL) {
        free(list->head);
        list->size--;
        return 0;
    }
    if (index == 0) {
        list->head = list->head->next;
        list->size--;
        return 0;
    }
    Node *temp = list->head;
    for (int i = 1; i < index; ++i) {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    list->size--;
    return 0;
}

long *print_list(List *list) {

    if (list->head == NULL) {
        return NULL;
    }
    long *print = malloc((list->size + 1) * sizeof(long));
    Node *temp = list->head;
    for (int i = 0; i < list->size; ++i) {
        print[i] = temp->value;
        temp = temp->next;
    }
    return print;
}

int main() {
    List *list = &List_Int_Default;
    insert_node(list, 1, 0);
    insert_node(list, 2, 0);
    insert_node(list, 3, 0);
    delete_node(list, 0);
    long *print = print_list(list);
    for (int i = 0; i < list->size; ++i) {
        printf("%li ", print[i]);
    }
    return 0;
}