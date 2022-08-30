//Davi Baechtold Campos
//Trabalho 3 - Lista encadeada

/*
  Sua  tarefa  será  construir  uma  estrutura  de  dados,  baseada  em  listas  encadeadas  sem  usar  qualquer  estrutura  de  dados  já disponíveis nas  linguagens  de  programação.  Lembre-se  que  para  tal você precisará definir uma aquitetura de memória e, no mínimo, os métodos de 
inclusão, exclusão e busca de dados nesta estrutura.  

  Você deverá criar uma lista com, no mínimo, 200.000 itens armazenados. Estes itens devem ser  números inteiros randomicamente gerados (use o twister de Mersenne para gerar os inteiros), em um  range de 1 a 1.000.000. Seu objetivo será medir o tempo para criar a lista, o tempo para reverter esta lista, o tempo necessário para encontrar o item que está no meio da lista e o tempo necessário para  apagar todos os itens da lista, liberando a memória. 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct item
{
  int valor;
  struct item* next;
};
//Cria lista com valores aleatorios de 1 a 100000
void insere(struct item** head, int valor) 
{
  struct item* novo = (struct item*)malloc(sizeof(struct item));
  novo->valor = valor;
  novo->next = (*head);
  (*head) = novo;
}

//Inverte a lista e faz o primeir o se tornar o ultimo e o ultimo ser o primeiro
void inverter (struct item** head) 
{
    clock_t before = clock();
  
    struct item* anterior = NULL;
    struct item* atual = *head;
    struct item* proximo = NULL;
  
    while (atual != NULL) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual; // alteração de posição
        atual = proximo;
    }
    *head = anterior;
    clock_t dif = clock() - before;
    int msec = dif * 1000 / CLOCKS_PER_SEC;
    printf("\n Inverter a lista: %f Seg\n", (float) msec/10);
}

//Indentifica todos os valores atribuidos na lista
int procura(struct item** head, int valor) 
{
  struct item* item_atual = *head;
  while (item_atual != NULL) {
    if (item_atual->valor == valor) return 1;
    item_atual = item_atual->next;
  }
  return 0;
}

// pega o item do meio da lista encadeada, sendo impar. ela ira puxar o da esquerda
int MeioLista(struct item** head)
{
  clock_t before = clock();
  struct item* atual = *head;
  for(int i = 0; i <= (300000/2)+1; i++){
    atual = atual->next;
  }
  clock_t dif = clock() - before;
  int msec = dif * 1000 / CLOCKS_PER_SEC;
  printf("\nAchar o meio da lista: %f Seg\n ", 300000, (float) msec/1000);
  return atual->valor;
}

// Apaga toda lista
void apagarLista(struct item** head) 
{
  clock_t before = clock();
  struct item* atual = *head;
   struct item* proximo;
 
   while (atual != NULL)
   {
       proximo = atual->next;
       free(atual);
       atual = proximo;
   }
   
  *head = NULL;
  clock_t dif = clock() - before;
  int msec = dif * 1000 / CLOCKS_PER_SEC;
  printf("\nTempo de apagar lista: %f Seg\n", (float) msec/1000);
}


int main() 
{
  struct item* inicio = NULL;

  clock_t before = clock();
  for(int i= 0; i<= 300000; i++){
    int random = rand() % 100000;
    insere(&inicio, random);
  }
  clock_t dif = clock() - before;
  int msec = dif * 1000 / CLOCKS_PER_SEC;
  printf("Tempo criação de lista: %f\n", 300000, (float) msec/1000);

  int meio = MeioLista(&inicio);
  printf("Item do meio da lista encadeada:%d\n", meio);
  inverter(&inicio);
  apagarLista(&inicio);

}