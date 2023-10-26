#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define M 3



int count=0,cost=0;
typedef struct _node {
int n;
int keys[M - 1];
struct _node *p[M];
} node;



node *root = NULL;



typedef enum KeyStatus { Duplicate, SearchFailure, Success, InsertIt, LessKeys,



} KeyStatus;




void insert(int key);



void display(node *root, int);
KeyStatus ins(node *r, int x, int* y, node** u);



void amortized();
void eatline(void);



void inorder(node *ptr);



int main() {
int key;
int choice;
haa
printf("Name- Rajat Jain\n");
printf("Roll No- 200913010\n");
printf("\nCreation of B tree for M=%d\n", M);
printf("Number of keys %d\n",M-1);
while (1) {
printf("1.Insert\n2.Display\n3.Quit\nEnter your choice: ");
scanf("%d", &choice); eatline();
switch (choice) {
case 1:
printf("Enter the key: ");
scanf("%d", &key); eatline();
insert(key);
break;
case 2:
printf("Btree is :\n");
display(root, 0);
amortized();
break;
case 3:
exit(1);
default:
printf("Wrong choice\n");
break;
}
}
return 0;
}



void insert(int key) {
count++;
cost++;
node *newnode;
int upKey;
KeyStatus value;
value = ins(root, key, &upKey, &newnode);
if (value == Duplicate)
printf("Key already available\n");
if (value == InsertIt) {
node *uproot = root;
root = (node*)malloc(sizeof(node));
root->n = 1;
root->keys[0] = upKey;
root->p[0] = uproot;
root->p[1] = newnode;
}}
KeyStatus ins(node *ptr, int key, int *upKey, node **newnode) {
node *newPtr, *lastPtr;
int pos, i, n, splitPos;
int newKey, lastKey;
KeyStatus value;
if (ptr == NULL) {
*newnode = NULL;
*upKey = key;
return InsertIt;
}
n = ptr->n;
pos = searchPos(key, ptr->keys, n);
if (pos < n && key == ptr->keys[pos])
return Duplicate;
value = ins(ptr->p[pos], key, &newKey, &newPtr);
if (value != InsertIt)
return value;



if (n < M - 1) {
pos = searchPos(newKey, ptr->keys, n);



for (i = n; i>pos; i--) {
ptr->keys[i] = ptr->keys[i - 1];
ptr->p[i + 1] = ptr->p[i];
}




ptr->keys[pos] = newKey;
ptr->p[pos + 1] = newPtr;
++ptr->n;
return Success;
}



if (pos == M - 1) {
lastKey = newKey;
lastPtr = newPtr;
}
else {
lastKey = ptr->keys[M - 2];
lastPtr = ptr->p[M - 1];
for (i = M - 2; i>pos; i--) {
ptr->keys[i] = ptr->keys[i - 1];
ptr->p[i + 1] = ptr->p[i];
}
ptr->keys[pos] = newKey;
ptr->p[pos + 1] = newPtr;
}
splitPos = (M - 1) / 2;
(*upKey) = ptr->keys[splitPos];
(*newnode) = (node*)malloc(sizeof(node));
ptr->n = splitPos;
(*newnode)->n = M - 1 - splitPos;
for (i = 0; i < (*newnode)->n; i++) {
(*newnode)->p[i] = ptr->p[i + splitPos + 1];
if (i < (*newnode)->n - 1)
(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
else
(*newnode)->keys[i] = lastKey;
}
(*newnode)->p[(*newnode)->n] = lastPtr;
return InsertIt;
}



void display(node *ptr, int blanks) {
if (ptr) {
int i;
for (i = 1; i <= blanks; i++)
printf(" ");
for (i = 0; i < ptr->n; i++)
printf("%d ", ptr->keys[i]);
printf("\n");
for (i = 0; i <= ptr->n; i++)
display(ptr->p[i], blanks + 10);
}
}



void amortized()
{

printf("The amortized cost is %d\n",(cost/count));
}
int searchPos(int key, int *key_arr, int n) {
int pos = 0;
while (pos < n && key > key_arr[pos])
pos++;
return pos;
}



void eatline(void) {
char c;
while ((c = getchar()) != '\n');
}



void inorder(node *ptr) {
if (ptr) {
if (ptr->n >= 1) {
inorder(ptr->p[0]);
printf("%d ", ptr->keys[0]);
inorder(ptr->p[1]);
if (ptr->n == 2) {
printf("%d ", ptr->keys[1]);
inorder(ptr->p[2]);
}}}}
