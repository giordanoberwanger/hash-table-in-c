#ifndef INT_H_INCLUDED
#define INT_H_INCLUDED

void* CriaInteiro();
int   LiberaInteiro(void **ptrDado);
int   LeInteiro(void *ptrDado);
void* CriaLeInteiro();
int   EscreveInteiro(void *ptrDado);

int   ComparaInteiro(void *ptrElemento, void *ptrChaveBusca);
int   CopiaInteiro  (void *ptrDestino , void *ptrOrigem    );

#endif // INT_H_INCLUDED
