#define MAX 20
struct livro{
	int id;
	char nome[30];
};

typedef struct lista Lista;
Lista*cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct livro lv);
int busca_lista_pos(Lista* li, int pos, struct livro *lv);
int busca_lista_isbn(Lista* li, int isbn, struct livro *lv);
int remove_lista(Lista* li, int isbn);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);  