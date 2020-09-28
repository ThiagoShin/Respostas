# Respostas
#include <stdio.h>
#include <stdlib.h>

/*
Construa um programa que insira números em uma lista ligada.
O usuário poderá escolher se deseja incluir o número no ínício da lista ou no final da lista;
*/

typedef struct lista{
  int qtd;
  struct registro *inicio;
}lista;

typedef struct registro{
  int valor;
  struct registro *prox;
}registro;

lista *aloca_lista(){
  lista *l;
  l=(lista*) malloc (sizeof(lista));
  l->qtd=0;
  l->inicio=NULL;
  return l;
}

registro *aloca_registro(){
  registro *r;
  r=(registro*)malloc(sizeof(registro));
  r->valor=0;
  r->prox=NULL;
  return r;
}

void inserir_valores_inicio(lista *l, int n){
  registro *r, *aux;
  int x;
  r=aloca_registro();
  r->valor=n;
  if(l->qtd==0){
    l->inicio=r;
    l->qtd++;
  }else {
    aux=l->inicio;
    l->inicio=r;
    r->prox=aux;
    l->qtd++;
  }
}

void inserir_valores_fim(lista *l, int n){
  registro *r, *aux;
  r=aloca_registro();
  r->valor=n;
  if(l->inicio==NULL){
    l->inicio=r;
    l->qtd++;
  } else {
    aux=l->inicio;
    while(aux->prox!=NULL){
      aux=aux->prox;
    }
    aux->prox=r;
    l->qtd++;
  }
}

void mostrar_valores (lista *l){
  int stop;
  registro *aux;
  stop = l->qtd;
  if(stop==0){
    printf ("Nao ha valores");
    return ;
  }else {
    aux= l->inicio;
    while (aux!=NULL){
      printf("%d\t",aux->valor);
      aux=aux->prox;
    }
  }
  
}

int main(){
  lista *l;
  int stop=10, num;
  l= aloca_lista ();
  while (stop!=0){
    printf("\n\tMenu\n");
    printf("1-Inserir Valor no Inicio");
    printf("\n2-Inserir Valor no Final");
    printf("\n3-Mostrar Valores");
    printf("\n0-Finalizar");
    printf("\nDigite a função desejada: ");
    scanf("%d",&stop);
    switch (stop){
      case 1:
      printf("Digite o valor desejado: ");
      scanf("%d",&num);
      inserir_valores_inicio(l,num);
      break;

      case 2:
      printf("Digite o valor desejado: ");
      scanf("%d",&num);
      inserir_valores_fim(l,num);
      break;

      case 3:
      mostrar_valores(l);
      break;

      case 0:
      printf("Programa Finalizado: ");
      break;

      default:
      printf("Função não existe: ");
    }
  }
  return 0;
}
