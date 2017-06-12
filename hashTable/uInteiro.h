/*
 ============================================================================
 Arquivo     : Biblioteca Auxiliar para Inteiros (.h)
 Autor       : Giordano Berwanger (Cryogenio)
 ============================================================================
 */

void* CriaInteiro();
int   LiberaInteiro(void **ptrDado);
int   LeInteiro(void *ptrDado);
void* CriaLeInteiro();
int   EscreveInteiro(void *ptrDado);

int   ComparaInteiro(void *ptrElemento, void *ptrChaveBusca);
int   CopiaInteiro  (void *ptrDestino , void *ptrOrigem    );
