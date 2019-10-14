#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* struktura element listy */
typedef struct node {
   int value;
   struct node *next;
} node;

typedef struct {
   node *head;
   node *tail;
} list;

/* funkcja tworząca nowy element listy */
node *create_new_node(int val) {
   node *temp = malloc(sizeof(node));
   temp->value = val;
   temp->next= NULL;
   return temp;
}

/* funkcja dodająca nowy element na początek listy */
void add(list *l, node *n) {
    if (l->head == NULL) {
	l->head = n;
	l->tail = n;
	}
    else {
    	l->tail->next = n;
	l->tail = n;
    }
}

/* funkcja sprawdzająca czy w liscie znajduje się dana wartość */
bool contains(list l, int search) {
    node *temp = l.head;
    while (temp != NULL) {
	if (temp->value == search)
	    return true;
	temp = temp->next;
    }
    return false;
}

/* funkcja usuwająca element z listy */
bool rm(list *l, int search) {
    if (l->head == NULL) // (1)
	return false;
    if (l->head->value == search) { // (2)
	if (l->head == l->tail) {
	    l->head = NULL;
	    l->tail = NULL;
	}
	else { // (3)
	    l->head = l->head->next;
	}
	return true;
    }
    if (l->head->next == NULL) { // wyjątek jak jest tylko 1 node i nie zgadza
	return false;		 // sie z elementem szukanym i nie mozna szukac
    }
    node *temp = l->head;
    while (temp != NULL && temp->next->value != search) {
	temp = temp->next;
    }
    if (temp->next != NULL) { // (6)
	if (temp->next == l->tail) { // (4)
	    l->tail = temp;
	}
	temp->next = temp->next->next; // (5)
	return true;
    }
    return false; // (6)
}

/* funkcja przemierzająca liste (print) */
void traverse(list l) {
    node *temp = l.head;
    while (temp != NULL) {
	printf("%d  ", temp->value);
	temp = temp->next;
    }
    printf("\n");
}

/* funkcja przemierzająca liste od tyłu (print) */
void reverse_traverse(list l) {
    if (l.tail != NULL) {
	node *curr = l.tail;
	node *prev = l.head;
	while (curr != l.head) {
	    prev = l.head;
	    while (prev->next != curr) {
		prev = prev->next;
	    }
	    printf("%d  ", curr->value);
	    curr = prev;
	}
	printf("%d  ", curr->value);
    }
    printf("\n");
}


int main() {
    list l1;
    l1.head = NULL;
    l1.tail = NULL;

    add(&l1, create_new_node(45));
    add(&l1, create_new_node(60));
    add(&l1, create_new_node(12));
    add(&l1, create_new_node(10));
    add(&l1, create_new_node(36));
    add(&l1, create_new_node(69));
    traverse(l1);
    reverse_traverse(l1);
    contains(l1, 36) ? printf("True\n") : printf("False\n");
    printf("remove_node: ");
    rm(&l1, 60) ? printf("True\n") : printf("False\n");
    traverse(l1);
    return 0;
}

