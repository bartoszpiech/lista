#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int value;
   struct node *edge;
} node;

void print_list(node *head) {
   node *temp= head;
   while (temp!= NULL) {
      printf("%d - ", temp->value);
      temp= temp->edge;
   }
   printf("\n");
}

node *create_new_node(int val){
   node *temp = malloc(sizeof(node));
   temp->value = val;
   temp->edge= NULL;

   return temp;
}
int main(int argc, char *argv[]) {
   node n1, n2, n3;
   node *head;
   head = &n3;
   
/*** inicjalizacja ***/

   n1.value = 30;
   n2.value = 45;
   n3.value = 100;
   
/*** linkowanie ***/
   n1.edge = &n2;
   n2.edge = NULL;
   n3.edge = &n1;

   print_list(head);

   return 0;
}

