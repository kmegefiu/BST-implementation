// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *left;
struct node *right;
};

typedef struct node node;

typedef struct BST {
node *root;
}BST;


node* new_node(int data) {
node *n = malloc(sizeof(node));
n->data = data;
n->left = NULL;
n->right = NULL;

return n;
}

BST* new_BST() {
BST *t = malloc(sizeof(BST));
t->root = NULL;

return t;
}

void insert(BST *t, node *n) {
struct node *parent = NULL;
node *y = NULL;
node *x = t->root;
while(x!= NULL) {
  y = x;
  if(n->data < x->data)
    x = x->left;
  else
    x = x->right;
}
parent = y;

if(y == NULL) 
  t->root = n; //if root is empty
  
else if(n->data < y->data)
  y->left = n;
else
  y->right = n;
}

void inorder(BST *t, node *n) {
if(n != NULL) {
  inorder(t, n->left);
  printf("%d\n", n->data);
  inorder(t, n->right);
}
}

int main() {
    BST *t = new_BST();

//user input

int number, count = 1;    
printf("how many insertion will you make? ");
scanf("%d",&number);

while(count<= number)
{

  printf("insertion number: %d\n",count);

  int inserted;
  scanf("%d",&inserted); //insetion to the tree
  insert(t, new_node(inserted));//calling the insert function

count++;
}

printf("\ninorder tree\n");
inorder(t, t->root);
    return 0;
}





