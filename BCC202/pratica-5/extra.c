//
// Created by pedro on 05/07/2021.
//

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int key;
} TItem;

typedef struct cell {
    TItem item;
    struct cell *prox;
    struct cell *prev;
} TCell;

typedef struct list {
    TCell *head;
    TCell *tail;
    int size;
} TList;


/* Start a list */
void TListStart(TList *list) {
    list->head = (TCell*) calloc(1,sizeof(TCell));
    list->tail = (TCell*) calloc(1,sizeof(TCell));
    list->head->prox = list->tail;
    list->tail->prev = list->head;
    list->size = 0;
}

/* Return 1 if a list is empty and 0 otherwise */
int TListIsEmpty(TList *list) {
    return list->size == 0;
}

/* Insert an element x in a list */
int TListInsertBeginning(TList *list, TItem item) {
    TCell * newCell = (TCell*)calloc(1,sizeof(TCell));
    if (newCell == NULL) {
        return 0;
    }
    newCell->item = item;

    TCell *prox = list->head->prox;
    TCell *prev = prox->prev;

    newCell->prox = prox;
    newCell->prev = prev;
    prev->prox = newCell;
    prox->prev = newCell;

    list->size++;
    return 1;

}

/* Remove an element from the ending of the list and return through the pX parameter
 * the function returns 0 if there is not an element in position p in the list, 1 otherwise */
int TListRemoveEnding(TList *list, TItem *item) {
    if(list->size == 0)
        return 0;
    TCell *removedCell = list->tail->prev;

    TCell *prox = removedCell->prox;
    TCell *prev = removedCell->prev;
    prox->prev = prev;
    prev->prox = prox;
    *item = removedCell->item;
    free(removedCell);
    removedCell = NULL;
    list->size--;
    return 1;
}

/* return the list size */
int TListSize(TList *list) {
    return list->size;
}

void TListPrint(TList *list) {
    TCell *currentCell = list->head->prox;
    printf("IN-ORDER [");
    while(currentCell != list->tail) {
        printf("%d ", currentCell->item.key);
        currentCell = currentCell->prox;
    }
    printf("]\n");
}

void TListPrintInv(TList *list) {
    TCell *currentCell = list->tail->prev;
    printf("INVERSE [");
    while(currentCell != list->head) {
        printf("%d ", currentCell->item.key);
        currentCell = currentCell->prev;
    }
    printf("]\n");
}

void TListTest() {
    TList list;
    TListStart(&list);

    if (TListIsEmpty(&list) == 1)
        printf("The list is empty.\n");

    TItem item;
    item.key = 9;
    printf("Initial list\n");
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);
    printf("Adding item: %d\n", item.key);
    TListInsertBeginning(&list, item);
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);
    item.key = 8;
    printf("Adding item: %d\n", item.key);
    TListInsertBeginning(&list, item);
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);

    TItem removedItem;
    if (TListRemoveEnding(&list, &removedItem) == 1)
        printf("Removed item: %d\n", removedItem.key);
    else
        printf("Impossible to remove an item!!!\n");
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);

    item.key = 7;
    printf("Adding item: %d\n", item.key);
    TListInsertBeginning(&list, item);
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);

    item.key = 6;
    printf("Adding item: %d\n", item.key);
    TListInsertBeginning(&list, item);
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);

    if (TListRemoveEnding(&list, &removedItem) == 1)
        printf("Removed item: %d\n", removedItem.key);
    else
        printf("Impossible to remove an item!!!\n");
    printf("\tTList >> "); TListPrint(&list);
    printf("\tTList >> "); TListPrintInv(&list);

    printf("The list size is %d.\n", TListSize(&list));

}

int main() {
    TListTest();
}