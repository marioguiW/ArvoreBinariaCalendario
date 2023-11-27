#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
    int dia;
    int mes;
    char desc[100];
    struct No *esq;
    struct No *dir;
};

typedef struct No no;

typedef struct No *Evento;

struct Node {
    Evento evento;
    struct Node* prox;
};

typedef struct Node node;
typedef node* lista;

#include "includes/deletarEvento.h"
#include "includes/atualizarEvento.h"
#include "includes/visualizarEvento.h"
#include "includes/criarEvento.h"
#include "includes/balaceamentoEventos.h"

Evento* criaArvore(){
    Evento *raiz = (Evento*) malloc (sizeof(Evento));
    if (raiz != NULL){
        *raiz = NULL;
    }else{
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}

int verificaData(int dia, int mes) {
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12){
    return 1;
    }
    else{
        return 0;
    }
}

void libera_no(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }else{
        libera_no(no_liberar->esq);
        libera_no(no_liberar->dir);
        free(no_liberar);
    }
}

int libera_arvore(Evento * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        libera_no(*raiz);
    }
    free(raiz);
}
int main(){
    lista* cabeca = criaLista();
    Evento *raiz = criaArvore();
    int option, mes, dia, achou, cont_balanceamento = 0, cont = 0;
    char descricao[100];
    system("cls");

    while (1){
        if(cont_balanceamento == 3){
            printf("Realizando o Balanceamento!\n");
            construirLista(*raiz, cabeca);
            cont = contar_nos(raiz);
            *raiz = listaParaArvore(cabeca, cont);
            cont_balanceamento = 0;
        }

        printf("--BEM VINDO A AGENDA--\n");
        printf("\nMenu:\n");
        printf("1 - Adicionar evento\n");
        printf("2 - Atualizar evento\n");
        printf("3 - Deletar evento\n");
        printf("4 - Listar eventos\n");
        printf("5 - Sair\n");

        printf("Escolha uma opcao: ");
        printf(">> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            do{


                printf("--Novo Evento--\n");
                printf("Insira o dia: ");
                scanf("%d", &dia);
                printf("Insira o dia do mes: ");
                scanf("%d", &mes);


                if (verificaData(dia, mes) == 1){
                        printf("Data Incorreta!\n");
                }else{
                    printf("Digite a descricao: ");
                    fflush(stdin);
                    gets(descricao);
                }
            } while (verificaData(dia, mes) == 1);
            criarElemento(raiz, dia, mes, descricao);
            system("cls");
            printf("Evento inserido com sucesso.\n");
            cont_balanceamento++;
            break;
        case 2:
            system("cls");
            do{
                printf("--Editar--\n");
                printf("Insira o dia: ");
                scanf("%d", &dia);
                printf("Insira o dia do mes: ");
                scanf("%d", &mes);
                if (verificaData(dia, mes) == 1){
                        printf("Data invalida. Tente novamente.\n");
                }else{
                    printf("Informe a descricao: ");
                    fflush(stdin);
                    gets(descricao);
                }
            } while (verificaData(dia, mes) == 1);

            editar_no(*raiz, dia, mes, descricao, *raiz);
            break;
        case 3:
            system("cls");
            printf("--Excluir--\n");
            printf("Insira o dia: ");
            scanf("%d", &dia);
            printf("Insira o dia do mes: ");
            scanf("%d", &mes);
            remove_no(raiz, dia, mes);
            break;
        case 4:
            system("cls");
            printf("--Eventos--\n");
            listarArvore(*raiz);
            break;
        case 5:
            libera_arvore(raiz);
            exit(1);
        default:
            printf("Opcao invalida\n");
        }
    }
    libera_arvore(raiz);
    return 0;
}

