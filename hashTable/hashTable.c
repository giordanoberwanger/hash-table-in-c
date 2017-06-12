/*
 ============================================================================
 Arquivo     : Tabela Hash (.c)
 Autor       : Giordano Berwanger (Cryogenio)
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"


int hashFunction(int value)
{
    char *hash = (char*) malloc (sizeof(char) * 10);
    unsigned long hashCode = 287243481;
    int c;
    itoa(value, hash, 10);
    while((c = *hash++))
        hashCode = ((hashCode << 10) + hashCode) + c;
    return hashCode % TAM;
}

int hashFunction2 (int value)
{
    char floatString[100];
    int hashFinal = 0, i;

    itoa(value, floatString, 10);

    for(i=0; floatString[i] != '\0'; i++)
        hashFinal += floatString[i];

    return hashFinal % TAM;
}
