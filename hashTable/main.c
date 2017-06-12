/*
 ============================================================================
 Arquivo     : Tabela Hash (main.c)
 Autor       : Giordano Berwanger (Cryogenio)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaDinamica.h"
#include "hashTable.h"

enum OPCOES
{
    EXIBIR = 1,
    INSERIR,
    REMOVER,
    BUSCAR,
    POPULA,
    SAIR,
    };

int main()
{
    FILE *arq = fopen("saida.txt", "w+");
    t_lista *Li[TAM];
    int i, op = 0, *value;
    srand(time(NULL));

    for (i=0; i<TAM; i++)
        Li[i] = Cria_Lista();


    while(op != SAIR)
    {
        printf("------ MENU ------\n");
        printf("[1] Exibir\n[2] Inserir\n[3] Remover\n[4] Buscar\n[5] Popula\n[6] Sair\nOpcao:");
        scanf("%d",&op);
        switch(op)
        {

        case EXIBIR:
            for (i=0; i<TAM; i++){
                Exibe_Lista(Li[i]);
                Exibe_ListaArquivo(Li[i], arq);
            }
                system("pause");
            break;

        case INSERIR:
            printf("Entre com o valor a ser inserido:\n");
            value = (int*) malloc (sizeof(int));
            scanf("%d", value);
            if(!Insere_FimLi(Li[hashFunction2(*value)], value))
                printf("Valor nao pode ser inserido\n");
            else
                printf("Valor inserido com sucesso da posicao %d da tabela\n", hashFunction2(*value));

            hashFunction2(*value);
            system("pause");
            break;


        case REMOVER:
            printf("Entre com o valor que sera removido:\n");
            value = (int*) malloc (sizeof(int));
            scanf("%d", value);
            if(!Exclui_NoLi(Li[hashFunction2(*value)], value))
                printf("Valor nao encontrado\n");
            else
                printf("Valor removido com sucesso da posicao %d da tabela\n", hashFunction2(*value));
            system("pause");
            break;


        case BUSCAR:
            printf("Entre com o valor que deseja encontrar:\n");
            value = (int*) malloc (sizeof(int));
            scanf("%d", value);
            if(!BuscaL(Li[hashFunction2(*value)], value))
                printf("Valor nao encontrado\n");
            else
                printf("Valor Encontrado na posicao %d da tabela\n", hashFunction2(*value));

            system("pause");
            break;

        case POPULA:
            for (i=0; i<TAM; i++){
                value = (int*) malloc (sizeof(int));
                *value = rand()% (TAM * 10);
                Insere_FimLi(Li[hashFunction2(*value)], value);
            }
            break;

        case SAIR:

            break;
        }

        system("cls");
    }



    return 0;
}
