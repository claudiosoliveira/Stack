#include<stdio.h>
#include<stdlib.h>
#include"TADPilha.h"

int main()
{
   Pilha* P = (Pilha*)malloc(sizeof(Pilha*));
   int b;
   printf("\n-1 - Sair\n");
   printf("1 - Inserir\n");
   printf("2 - Remover\n");
   printf("3 - Buscar\n");
   printf("4 - Tamanho\n");
   printf("5 - Imprimir\n");
   scanf("%i",&b);
   Menu(P,b);
   saida(P);
   return 0;
}
