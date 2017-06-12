#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "listaDinamica.h"
#include "uInteiro.h"

t_lista* Cria_Lista()
{
    t_lista *Lista;
    Lista = (t_lista*) malloc (sizeof(t_lista));
    Lista->qtde = 0;
    return Lista;
}

t_nodeL* Cria_NoLista()
{
    t_nodeL *No;
    No = (t_nodeL*) malloc (sizeof(t_nodeL));
    return No;
}

int Insere_InicioLi (t_lista *Lista, int *x)
{
    t_nodeL *No = Cria_NoLista();
    No->val = x;
    if(Lista->qtde == 0)
    {
        Lista->inicio = No;
        Lista->fim = No;
        No->Prox = NULL;
        No->Ant = NULL;
    }
    else
    {
        No->Prox = Lista->inicio;
        No->Ant = NULL;
        No->Prox->Ant = No;
        Lista->inicio = No;
    }

    Lista->qtde++;
    return 1;
}

int Insere_FimLi (t_lista *Lista, int* x)
{
    t_nodeL *No = Cria_NoLista();
    No->val = x;

    if(Lista->qtde == 0)
    {
        Lista->inicio = No;
        Lista->fim = No;
        No->Prox = NULL;////////
        No->Ant = NULL;
    }
    else
    {
        No->Ant = Lista->fim;
        No->Ant->Prox = No;
        No->Prox = NULL;//////
        Lista->fim = No;
    }

    Lista->qtde++;
    return 1;
}

int Insere_MeioLi (t_lista *Lista, int* x, int Busca)
{
    t_nodeL *aux;
    aux = Lista->inicio;
    int cont=0;
    while(aux != NULL)
    {
        if(cont == Busca)
        {
            if(Busca == 0)
            {
                Insere_InicioLi(Lista,x);
                break;
            }
            if(Busca > 0 && Busca < Lista->qtde-1)
            {
                t_nodeL *No = Cria_NoLista();
                No->val = x;
                No->Prox = aux;
                No->Ant = aux->Ant;
                aux->Ant->Prox = No;
                aux->Ant = No;
                Lista->qtde++;
                break;
            }
            if(Busca >= Lista->qtde-1)
            {
                Insere_FimLi(Lista,x);
                break;
            }

        }
        cont++;
        aux = aux->Prox;
    }
    return 1;
}

void Exibe_Lista (t_lista *Lista)
{
    t_nodeL *aux;
    if(Lista->qtde == 0)
    {
        printf("NULL\n\n");
        return;
    }
    aux = Lista->inicio;
    while(aux != NULL)
    {
        printf("%d ->", *aux->val);
        aux = aux->Prox;
    }
    printf("NULL\n\n");
}

void Exibe_ListaArquivo (t_lista *Lista, FILE *arq)
{
    t_nodeL *aux;
    if(Lista->qtde == 0)
    {
        fprintf(arq,"NULL\n\n");
        return;
    }
    aux = Lista->inicio;
    while(aux != NULL)
    {
        fprintf(arq,"%d ->", *aux->val);
        aux = aux->Prox;
    }
    fprintf(arq,"NULL\n\n");
}

int Exclui_NoLi (t_lista *Lista, int* valor)
{
    t_nodeL *aux = Lista->inicio;

    if(Lista->qtde == 0)
        return 0;

    while(aux != NULL)
    {
        if(*aux->val == *valor)
        {
            if(Lista->qtde > 1 && !aux->Prox && aux->Ant) ///tem mais de um elemento e ele é o ultimo
            {
                Lista->fim = aux->Ant;
                aux->Ant->Prox = NULL;
                free(aux);
                Lista->qtde--;
                return 1;
            }

            if(Lista->qtde > 1 && aux->Prox && aux->Ant) ///tem mais de um elemento e ele não é o ultimo
            {
                aux->Ant->Prox = aux->Prox;
                aux->Prox->Ant = aux->Ant;
                free(aux);
                Lista->qtde--;
                return 1;
            }

            if(Lista->qtde > 1 && !aux->Ant && aux->Prox) ///tem mais de um elemento e ele é o primeiro
            {
                Lista->inicio = aux->Prox;
                aux->Prox->Ant = NULL;
                free(aux);
                Lista->qtde--;
                return 1;
            }

            if(Lista->qtde == 1 && !aux->Prox && !aux->Ant) ///tem um elemento e
            {
                Lista->inicio = NULL;
                Lista->fim = NULL;
                free(aux);
                Lista->qtde--;
                return 1;
            }
        }
        aux = aux->Prox;
    }
    return 0;
}

int Altera_ElemLista (t_lista *Lista, int Busca, int* Elem)
{
    t_nodeL *aux = BuscaLP(Lista,Busca);
    aux->val = Elem;
    return 1;
}
int BuscaL (t_lista *Lista, int *chave)
{
    t_nodeL *aux = Lista->inicio;

    while(aux != NULL)
    {
        if(*aux->val == *chave)
            return 1;

        aux = aux->Prox;
    }
    return 0;
}

t_nodeL* BuscaLP (t_lista *Lista, int pos)
{
    t_nodeL *aux = Lista->inicio;
    int cont=0;
    while(aux != NULL)
    {
        if(cont == pos)
            return aux;

        aux = aux->Prox;
        cont++;
    }
    return NULL;
}
