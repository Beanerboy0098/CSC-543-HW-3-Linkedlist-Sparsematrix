/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#include<iostream>

using namespace std;

/* Creating variables that can be changed in other functions */
class Node
{
public:
  int row;
  int col;
  int data;
  Node *next;
};

/* This function is called when the value found in the matrix is not zero and serves as what is outputed*/
void create_new_node(Node **p, int rowid, int colid, int x)
{
    Node *temp = *p;
    Node *r;
     
   /* The head of the linked list is NULL to start, this is so that the linkedlist is created before we create the many nodes for the matrix. Without the head the linklist could not be created. */
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = rowid;
        temp->col = colid;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
   /* After the head is created, the linked list will create the nodes for the linked list, getting the row, column, and value of each number in the matrix.*/
    else
    {
        while (temp->next != NULL)  
            temp = temp->next;
             
        r = new Node();
        r->row = rowid;
        r->col = colid;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

/* This  is where the nodes are printed when the function is run, after determining the values in  the matrix that aren't zero*/
void printList(Node *start)
{
    Node *matrix = start;
    cout << "row_position: ";
    while (matrix != NULL)
    {
        cout << matrix->row << " ";
        matrix = matrix->next;
    }
    
    cout << "\ncolumn_position: ";
 
    matrix = start;
    while (matrix != NULL)
    {
        cout << matrix->col << " ";
        matrix = matrix->next;
    }
    
    cout << "\nValue: ";
    matrix = start;
     
    while (matrix != NULL)
    {
        cout << matrix->data << " ";
        matrix = matrix->next;
    }
}

int main()
{
     
    
    int sparseMatrix[4][4] = { { 0 , 0 , 0 , 3 },
                               { 0 , 0 , 0 , 0 },
                               { 5 , 78 , 0 , 0 },
                               { 0 , 0 , 0 , 12 } };
     
    /* Creating head/first node of list as NULL */
    Node *first = NULL;
    
    /* Moving through the 3D array, through its columns and rows. */
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 4; b++)
        {
             
            /* Pass only those values which are non - zero */
            if (sparseMatrix[a][b] != 0)
                create_new_node(&first, a, b, sparseMatrix[a][b]);
        }
    }
    printList(first);
 
    return 0;
}
