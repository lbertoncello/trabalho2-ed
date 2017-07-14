#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compacta.h"
#include "arvore.h"

//Zera todos as posições de um vetor de 256 posição, Generalizar isso?
void inicia_vetor(int *v)
{
    int i;
    for(i=0; i<256; i++)
    {
        v[i]=0;
    }
}

//Lê todo o arquivo de entrada
void ler_caracteres(FILE *arq, int *v)
{
    unsigned char c[1];
    while(!feof(arq))
    {
        //fread vai ler byte a byte do arquivo binario
        fread(c,sizeof(c),1,arq);
        v[c[0]]++;
        //conta quantas vezes aquele byte se repete no arquivo
    }
}

/*Nem todos os caracteres (bytes) podem ser usados no arquivo, essa função conta quantos realmente estão sendo usados
Ou seja, conta quandas posições do vetor de 256 posições são diferentes de 0*/
int caracteres_usados(int *v)
{
    int i,k=256;
    for(i=0; i<256; i++)
    {
        if(v[i] == 0)
        {
            k--;
        }
    }
    return k;
}

//Essa função vai gerar um vetor onde cada posição do vetor é uma folha da arvore de codificação,
//A árvore vai ser gerada a partir desse vetor
Arv** gera_folhas(int *v, int k)
{
    int i,j=0;
    Arv **folhas = (Arv**)malloc(k*sizeof(Arv*));

    for(i=0; i<256; i++)
    {
        if(v[i] != 0)
        {
            Arv *a = CriaFolha(v[i],i);
            folhas[j] = a;
            j++;
        }
    }
    return folhas;
}

//função que vai fazer a comparação do peso, e vai ser utilizada pela qsort para ordenar o vetor de forma crescente
int compara (const void* v1, const void* v2)
{
    Arv *a1 = *(Arv**)v1;
    Arv *a2 = *(Arv**)v2;

    int pesoA1, pesoA2;
    pesoA1 = RetornaPeso(a1);
    pesoA2 = RetornaPeso(a2);

    if (pesoA1 > pesoA2) return 1;
    else if (pesoA1 < pesoA2) return -1;
    else return 0;
}

//por enquanto a função que faz tudo e nada simultaneamente.
void gera_arvore(int *v)
{
    //int i;
    int k;
    Arv **folhas;
    k = caracteres_usados(v);

    folhas = gera_folhas(v,k);

    qsort(folhas,k,sizeof(Arv*),compara);

    /*
        for(i=0;i<k;i++){
            printf("%i: ",i+1);
            Imprime(folhas[i]);
            printf("\n");
        }
    */

}
