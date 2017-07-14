#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"
#include "descompacta.h"
#include "bitmap/bitmap.h"


void CriaArvoreAPartirBits(Arv* arv, bitmap* bm, unsigned int* posicaoAtual, int maxTamVet)
{
    unsigned char caracter;
    unsigned char temp;
    unsigned int posicaoNoCaracter;

    printf("\nPosicao Atual: %d\n", *posicaoAtual);

    if(*posicaoAtual < maxTamVet)
    {
        if(bitmapGetBit(*bm, *posicaoAtual) == 0)
        {
            GravarAtributoEsquerda(arv, CriaNo(0, NULL, NULL));
            *posicaoAtual = *posicaoAtual + 1;
            CriaArvoreAPartirBits(AcessarAtributoEsquerda(arv), bm, posicaoAtual, maxTamVet);
        }
        else
        {
            *posicaoAtual = *posicaoAtual + 1;
            caracter = 0;

            for(posicaoNoCaracter = 0; posicaoNoCaracter < 8; posicaoNoCaracter = posicaoNoCaracter + 1)
            {
                temp = bitmapGetBit(*bm, *posicaoAtual + posicaoNoCaracter);
                temp = temp<<(7 - posicaoNoCaracter);
                caracter = caracter | temp;
            }

            *posicaoAtual = *posicaoAtual + 8;

            GravarAtributoEsquerda(arv, CriaFolha(0, caracter));
        }

        printf("\nPosicao Atual: %d\n", *posicaoAtual);

        if(*posicaoAtual < maxTamVet)
        {
            if(bitmapGetBit(*bm, *posicaoAtual) == 0)
            {
                printf("\nTeste\n");
                GravarAtributoDireita(arv, CriaNo(0, NULL, NULL));
                *posicaoAtual = *posicaoAtual + 1;
                CriaArvoreAPartirBits(AcessarAtributoDireita(arv), bm, posicaoAtual, maxTamVet);
            }
            else
            {
                *posicaoAtual = *posicaoAtual + 1;
                caracter = 0;

                for(posicaoNoCaracter = 0; posicaoNoCaracter < 8; posicaoNoCaracter = posicaoNoCaracter + 1)
                {
                    temp = bitmapGetBit(*bm, *posicaoAtual + posicaoNoCaracter);
                    temp = temp<<(7 - posicaoNoCaracter);
                    caracter = caracter | temp;
                }

                *posicaoAtual = *posicaoAtual + 8;

                GravarAtributoDireita(arv, CriaFolha(0, caracter));
            }
        }
    }
}

Arv* DescompactaArquivo(unsigned char vet[], unsigned int maxTamBitmap, int maxTamVet)
{
    unsigned int posicaoAtual;

    Arv* arv = CriaVazia();

    arv = CriaNo(0, NULL, NULL);

    bitmap bm = bitmapInit(maxTamBitmap);

    for(posicaoAtual = 0; posicaoAtual < maxTamVet; posicaoAtual++)
    {
        bitmapAppendLeastSignificantBit(&bm, vet[posicaoAtual]);
    }

    posicaoAtual = 1;

    CriaArvoreAPartirBits(arv, &bm, &posicaoAtual, maxTamVet);

    printf("\n");
    Imprime(arv);

    return arv;
}







