#include <stdio.h>
#include <stdlib.h>
/* struktura element listy */
typedef struct node {
   int value;
   struct node *edge;
} node;
/*
typedef struct list {
   node *head=NULL;
   node *tail=NULL;
   int size;
   } list;
*/ 
int main (){

/* funkcja drukująca elementy listy */
void print_list(node *head) {
   node *temp= head;
   while (temp!= NULL) {
      printf("%d  ", temp->value);
      temp= temp->edge;
   }
   printf("\n");
}
/* funkcja tworząca nowy element listy */
node *create_new_node(int val) {
   node *temp = malloc(sizeof(node));
   temp->value = val;
   temp->edge= NULL;
   return temp;
}
/* funkcja dodająca nowy element na początek listy */
void add_to_front(node **head, node *n) {
  n->edge = *head;
  *head = n;
}
/* funkcja dodająca nowy element na koniec listy */
void add_to_end(node *head, node *n) {
   node *temp = head;
   while (temp->edge != NULL) {
   temp = temp->edge;
   }
   temp->edge = n;
}
/* funkcja dodająca nowy element listy za elementem instniejącym */
void add_after_node(node *previous, node *n) {
   n->edge = previous->edge;
   previous->edge = n;
}
/* funkcja usuwająca element listy za podanym elementem */
void remove_next_node(node *n) {
   node *temp = n->edge;
   n->edge = temp->edge;
   free(temp);
}


int main() {
   node *head = NULL;
   node *n1 = create_new_node(8);
/*** linkowanie ***/

   add_to_front(&head, create_new_node(5));
   for (int i = 0; i < 10; i++) {
      add_to_end(head, create_new_node(i));
   }
   add_to_end(head, n1);
   add_to_end(head, create_new_node(69));
   add_after_node(n1, create_new_node(400));
   print_list(head);
   remove_next_node(n1);
   print_list(head);

   return 0;
}

