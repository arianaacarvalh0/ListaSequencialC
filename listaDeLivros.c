#include <stdlib.h>
#include <stdio.h>
#include "listaDeLivros.h"

//Defiicao da lista
struct lista{
  int qtd;
	struct livro dados[MAX];	
};

//Criando uma lista
  Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
		li->qtd = 0;
    return li;
};
	
//Destruindo uma lista
void libera_lista(Lista* li){
    free(li);
};

//Insere dado no final
int insere_lista_final(Lista* li, struct livro lv){
  if(li == NULL || li == lista_cheia(li))
    return -1;
  else
    li->dados[li->qtd] = lv;
    li->qtd++;
    return 0;
};

//busca livro pela posição
int busca_lista_pos(Lista* li, int pos, struct livro *lv){
  if (li == NULL || pos < 0 || pos >= li->qtd) {
    return -1; 
  }
  *lv = li->dados[pos];
  return 0;
};

//busca livro pelo ISBN
int busca_lista_isbn(Lista* li, int isbn, struct livro *lv){
  if (li == NULL) {
    return -1; 
  }

  int i;
  for(i = 0; i < li->qtd; i++){
    if(li->dados[i].id == isbn){
      break;
    }
  }
  *lv = li->dados[i];
  return 0;
};

//remove o livro da lista pelo ISBN
int remove_lista(Lista* li, int isbn){
  if (li == NULL || li->qtd == 0) {
    return -1;
  }

  int pos = -1;
  for (int i = 0; i < li->qtd; i++) {
    if (li->dados[i].id == isbn) {
      pos = i;
      break;
    }
  }

  if (pos == -1) {
    return -1;
  }

  for (pos; pos < li->qtd - 1; pos++) {
    li->dados[pos] = li->dados[pos + 1];
  }
  li->qtd--;
  return 0;
};

//tamanho da lista
int tamanho_lista(Lista* li){
  if(li == NULL)
		return -1;
  else
		return li->qtd;
};
	
//Lista Vazia
int lista_vazia(Lista* li){
  if(li == NULL)
		return -1;
  else
		return(li->qtd == 0);
};
	
//Lista cheia
int lista_cheia(Lista* li){
  if(li == NULL)
		return -1;
  else
		return(li->qtd == MAX);
};