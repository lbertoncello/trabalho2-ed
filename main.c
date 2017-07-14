#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compacta.h"
#include "descompacta.h"

int main(int agrc, char *argv[])
{
    unsigned char vet[59];

    Arv* arv = CriaVazia();

    vet[0] = 0;
    vet[1] = 0;
    vet[2] = 1;
    vet[3] = 0;
    vet[4] = 1;
    vet[5] = 1;
    vet[6] = 0;
    vet[7] = 1;
    vet[8] = 1;
    vet[9] = 1;
    vet[10] = 1;
    vet[11] = 1;
    vet[12] = 0;
    vet[13] = 1;
    vet[14] = 1;
    vet[15] = 0;
    vet[16] = 1;
    vet[17] = 1;
    vet[18] = 0;
    vet[19] = 1;
    vet[20] = 0;
    vet[21] = 0;
    vet[22] = 1;
    vet[23] = 0;
    vet[24] = 1;
    vet[25] = 1;
    vet[26] = 0;
    vet[27] = 0;
    vet[28] = 1;
    vet[29] = 0;
    vet[30] = 1;
    vet[31] = 1;
    vet[32] = 0;
    vet[33] = 1;
    vet[34] = 1;
    vet[35] = 1;
    vet[36] = 0;
    vet[37] = 0;
    vet[38] = 1;
    vet[39] = 1;
    vet[40] = 0;
    vet[41] = 1;
    vet[42] = 0;
    vet[43] = 0;
    vet[44] = 1;
    vet[45] = 0;
    vet[46] = 0;
    vet[47] = 0;
    vet[48] = 0;
    vet[49] = 0;
    vet[50] = 1;
    vet[51] = 0;
    vet[52] = 1;
    vet[53] = 1;
    vet[54] = 0;
    vet[55] = 0;
    vet[56] = 0;
    vet[57] = 1;
    vet[58] = 0;

    arv = DescompactaArquivo(vet, 1024, 59);
}
