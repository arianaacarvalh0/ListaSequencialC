#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDeLivros.h"

int main() {
    Lista* lista = cria_lista();

    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Buscar livro\n");
        printf("4. Listar livros\n");
        printf("5. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct livro novoLivro;
                printf("\nDigite a matrícula do livro: ");
                scanf("%d", &novoLivro.id);
                getchar();

                printf("Digite o nome do livro: ");
                fgets(novoLivro.nome, 30, stdin);
                novoLivro.nome[strcspn(novoLivro.nome, "\n")] = '\0';

                if (insere_lista_final(lista, novoLivro)) {
                    printf("Livro inserido com sucesso!\n");
                } else {
                    printf("Erro ao inserir livro!\n");
                }
                break;
            }
            case 2: {
                int id;
                printf("\nDigite o ISBN do livro a ser removido: ");
                scanf("%d", &id);

                if (remove_lista(lista, id)) {
                    printf("LIvro removido com sucesso!\n");
                } else {
                    printf("Erro ao remover livro!\n");
                }
                break;
            }
            case 3: {
                int id;
                printf("\nDigite o ISBN do livro a ser buscado: ");
                scanf("%d", &id);

                struct livro livroEncontrado;
                if (busca_lista_isbn(lista, id, &livroEncontrado)) {
                    printf("\nLivro encontrado:\n");
                    printf("ISBN: %d, Nome: %s\n",
                           livroEncontrado.id, livroEncontrado.nome);
                } else {
                    printf("Livro não encontrado!\n");
                }
                break;
            }
            case 4: {
                if (tamanho_lista(lista) == 0) {
                    printf("\nA lista está vazia!\n");
                } else {
                    printf("\nLivros na lista:\n");
                    for (int i = 0; i < tamanho_lista(lista); i++) {
                        struct livro lv;
                        busca_lista_pos(lista, i, &lv);
                        printf("ISBN: %d, Nome: %s\n",
                               lv.id, lv.nome);
                    }
                }
                break;
            }
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 5);

    libera_lista(lista);

    return 0;
}