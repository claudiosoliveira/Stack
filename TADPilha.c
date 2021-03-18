#include"TADPilha.h"
#include<stdio.h>
#include<stdlib.h>

void criaPilha( Pilha *P)
{
    P->topo=NULL;
}

void Inserir( Pilha *P, int n)
{
   Celula *nova = (Celula*)malloc(sizeof(Celula));
   nova->valor = n;
   if(P->topo==NULL)
   {
      P->topo = nova;
      nova->proximo = NULL;
   }
   else
   {
      nova->proximo = P->topo;
      P->topo = nova;
   }
}

void Remover(Pilha *P)
{
   Celula *temp1, *temp2;
   if(P->topo==NULL)
   {
      printf("Pilha Vazia!");
   }
   else
   {
      temp1 = P->topo;
      temp2 = P->topo;
      if(temp1->proximo==NULL)
      {
         P->topo=NULL;
         free(temp1);
         free(temp2);
      }
      else
      {
         temp1= temp1->proximo;
         free(temp2);
         P->topo = temp1;
      }
   }
}

int Tamanho(Pilha *P)
{
   int i=0;
   Celula *temp;
   temp = P->topo;
   if(P->topo==NULL)
   {
      return i;
   }
   else
   {
      i++;
      while(temp!=NULL)
      {
         temp=temp->proximo;
         i++;
      }
      return i;
   }
}

int Busca(Pilha *P, int n)
{
   Celula *temp;
   temp = P->topo;
   if(P->topo==NULL)
   {
      printf("Pilha Vazia!");
      return 2;
   }
   else
   {
      while(temp!=NULL)
      {
         if(temp->valor==n)
         {
            return 1;
         }
         else
         {
            temp = temp->proximo;
         }
      }
   }
   return 2;
}

void Imprime(Pilha *P)
{
   Celula *temp;
   temp = P->topo;
   if(P->topo==NULL)
   {
      printf("Pilha Vazia!");
   }
   else
   {
      printf("|%i\n",temp->valor);
      while(temp!=NULL)
      {
         temp = temp->proximo;
         if(temp==NULL)
         {
            exit(1);
         }
         printf("|%i\n",temp->valor);
      }
   }
}

void Menu (Pilha *P, int j)
{
   int i,a;
   while(j!=-1)
   {
      switch(j)
      {
         case 1:
            scanf("%i",&i);
            Inserir(P,i);

         case 2:
            Remover(P);
 
         case 3:
            scanf("%i",&i);
            a = Busca(P,i);
            if(a==1)
            {
               printf("Existe o valor");
            }
            if(a==2)
            {
               printf("Este Elemento Não Existe Na Pilha!");
            } 

        case 4:
           i = Tamanho(P);
        
        case 5:
           Imprime(P);
        default:
           printf("Opcao invalida"); 
      }
      printf("\n-1 - Sair\n");
      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Buscar\n");
      printf("4 - Tamanho\n");
      printf("5 - Imprimir\n");
      scanf("%i",&j);
      Menu(P,j);
   }
}

void saida (Pilha *P)
{
   while(P->topo!=NULL)
   {
      Remover(P);
   }
   free(P);
}
