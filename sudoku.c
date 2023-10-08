#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n) {
    int row_mark[9][10] = {0}; // Arreglo para marcar números en filas
    int col_mark[9][10] = {0}; // Arreglo para marcar números en columnas
    int subgrid_mark[9][10] = {0}; // Arreglo para marcar números en submatrices

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int num = n->sudo[row][col];

            // Verificar en la fila
            if (row_mark[row][num] == 1) {
                return 0; // Número repetido en la fila, no es válido
            }
            row_mark[row][num] = 1; // Marcar el número en la fila

            // Verificar en la columna
            if (col_mark[col][num] == 1) {
                return 0; // Número repetido en la columna, no es válido
            }
            col_mark[col][num] = 1; // Marcar el número en la columna

            // Calcular el índice de la submatriz
            int subgrid_idx = 3 * (row / 3) + (col / 3);

            // Verificar en la submatriz
            if (subgrid_mark[subgrid_idx][num] == 1) {
                return 0; // Número repetido en la submatriz, no es válido
            }
            subgrid_mark[subgrid_idx][num] = 1; // Marcar el número en la submatriz
        }
    }

    // Si no se encontraron números repetidos en filas, columnas o submatrices, el estado es válido
    return 1;
}



List* get_adj_nodes(Node* n)
{
    List* list=createList();
    for (int fila = 0; fila < 9; fila++)
      {
        for (int columna = 0; columna < 9; columna++)
          {
            if (n->sudo[fila][columna] == 0)
            {
              for (int num = 1; num <= 9; num++)
                {
                  Node* nuevoNodo = copy(n);
                  nuevoNodo->sudo[fila][columna] = num;
                  pushBack(list, nuevoNodo);
                }
              return list;
            }
          }
      }
    return list;
}


int is_final(Node* n)
{
  for (int fila = 0; fila < 9; fila++)
    {
      for (int columna = 0; columna < 9; columna++)
        {
          if(n->sudo[fila][columna] == 0)
          {
            return 0;
          }
        }
    }
    return 1;
}

Node* DFS(Node* initial, int* cont)
{
  /*Stack* stack = createStack();
  push(stack, initial);
  *cont = 0;

  while (top(stack) != NULL)
    {
      Node* current = (Node*)top(stack);
      pop(stack);

      (*cont)++;

      if (is_final(initial))
      {
        free(current);
        
        return current;
      }
    }
  */
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/