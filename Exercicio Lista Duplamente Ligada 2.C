#include <stdio.h>
#include <stdlib.h>
  
/*
Construa um programa que insira números em uma lista ligada.
O usuário poderá escolher se deseja incluir o número no ínício da lista ou no final da lista;
*/
//Professor, o senhor não pediu para mostrar os valores, entretanto, coloquei essa opção

//exerciciolistaligada2.c

typedef struct lista{
  int qtd;
  struct registro *inicio;
  struct registro *fim;
}lista;

typedef struct registro{
  int vlr;
  struct registro *ant;
  struct registro *prox;
}registro;


lista *aloca_lista(){
  lista *novo;
  novo = (lista*) malloc (sizeof(lista));
  novo->qtd=0;
  novo->inicio=NULL;
  novo->fim=NULL;
  return novo;
}

registro *criar_registro(){
  registro *novo;
  novo = (registro*)malloc(sizeof(registro));
    novo->vlr=0;
    novo->prox=NULL;
    novo->ant=NULL;
    return novo;
}

void incluir_valor_fim(lista *l){
  int i;
  registro *novo, *aux;
  novo= criar_registro();
  printf ("\nDigite o valor: ");
  scanf("%d",&i);
  novo->vlr=i;
  if (l->qtd==0){
    l->inicio=novo;
    l->fim=novo;
    l->qtd++;
  } else{
    aux=l->inicio;
    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    l->fim=novo;
    aux->prox=novo;
    novo->ant=aux;
    l->qtd++;
  }
}

void incluir_valor_inicio(lista *l){
  int i;
  registro *novo, *aux;
  novo= criar_registro();
  printf ("\nDigite o valor: ");
  scanf("%d",&i);
  novo->vlr=i;
  if (l->qtd==0){
    l->inicio=novo;
    l->fim=novo;
    l->qtd++;
  } else{
    aux= l->inicio;
    l->inicio=novo;
    novo->prox=aux;
    aux->ant=novo;
    l->qtd++;
  }
}

void mostrar_valores(lista *l){
  int i,stop;
  registro *aux;
  if (l->qtd==0){
    printf("Nao ha valores\n");
  } else{
    stop=l->qtd;
    aux=l->inicio;
    for (i=0;i<stop;i++){
      printf("%d\t",aux->vlr);
      aux=aux->prox;
    }
  }
}

int main (){
  lista *l;
  int stop=10, num;
  l= aloca_lista();
  while(stop!=0){
    printf("\n\tMenu\n");
    printf("1-Inserir Valor no Inicio");
    printf("\n2-Inserir Valor no Final");
    printf("\n3-Mostrar Valores");
    printf("\n0-Finalizar");
    printf("\nDigite a função desejada: ");
    scanf("%d",&stop);
    switch (stop){
      case 1:
        incluir_valor_inicio(l);
        break;

      case 2:
        incluir_valor_fim(l);
        break;

      case 3:
        mostrar_valores(l);
        break;

      case 0:
        printf("O programa será finalizado");
        break;

      default:
        printf("Funcao invalida");
    }
  }
  return 0;
}
