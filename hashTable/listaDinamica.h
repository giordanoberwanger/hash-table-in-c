/*
 ============================================================================
 Arquivo     : Lista Dinâmica Duplamente Encadeada (.h)
 Autor       : Giordano Berwanger (Cryogenio)
 ============================================================================
 */

typedef struct nodeL
{
    int *val;
    struct nodeL *Prox, *Ant;
} t_nodeL;

typedef struct lista
{
    int qtde;
    t_nodeL *inicio, *fim;
}t_lista;

t_lista*   Cria_Lista           ();
t_nodeL*   Cria_NoLista         ();
int        Insere_InicioLi      (t_lista *Lista, int* x);
int        Insere_FimLi         (t_lista *Lista, int* x);
void       Exibe_Lista          (t_lista *Lista);
int        Exclui_NoLi          (t_lista *Lista, int* value);
int        Insere_MeioLi        (t_lista *Lista, int* x, int Busca);
int        Altera_ElemLista     (t_lista *Lista, int Busca, int* Elem);
int        BuscaL               (t_lista *Lista, int* chave);
t_nodeL*   BuscaLP              (t_lista *Lista, int pos);


