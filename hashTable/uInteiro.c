#include <stdio.h>
#include <stdlib.h>

void* CriaInteiro()
{
    float *ptrInteiro = (float *) malloc(sizeof(float));

    if ( ptrInteiro )
        *ptrInteiro = 0;

    return ptrInteiro;
}
float LiberaInteiro(void **ptrDado)
{
    if ( *ptrDado )
	{
        free( *ptrDado );
		*ptrDado = NULL;
		return 1;
	}
	return 0;
}
float  LeInteiro(void *ptrDado)
{
    if ( !ptrDado )
        return 0;
    float *ptrInteiro = (float *) ptrDado;


    scanf("%f", ptrInteiro);
//    *ptrInteiro = rand();
    return 1;
}
void* CriaLeInteiro()
{
    float *ptrInteiro = CriaInteiro();

    if ( ptrInteiro )
        LeInteiro( ptrInteiro );

    return ptrInteiro;
}
float EscreveInteiro(void *ptrDado)
{
    if ( !ptrDado )
        return 0;

    float *ptrInteiro = (float *) ptrDado;
    printf("%.1f ->", *ptrInteiro);
    return 1;
}

float ComparaInteiro(void *ptrElemento, void *ptrChaveBusca)
{
    float *ptrElem  = (float *) ptrElemento;
    float *ptrChave = (float *) ptrChaveBusca;

    return *ptrElem - *ptrChave;
}
float CopiaInteiro(void *ptrDestino, void *ptrOrigem)
{
    if (!ptrDestino || !ptrOrigem)
        return 0;

    float *ptrDest = (float *) ptrDestino;
    float *ptrOrig = (float *) ptrOrigem;

    *ptrDest = *ptrOrig;

    return 1;
}
