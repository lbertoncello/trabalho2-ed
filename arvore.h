#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore Arv;

int RetornaPeso(Arv *a);

Arv* CriaVazia(void);

/*cria um n� raiz de operador dados o operador e as duas sub-�rvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endere�o do n� raiz criado
*/
Arv* CriaNo(int peso, Arv* esq, Arv* dir);

/*cria um n� operando dado o valor do no (como o operando � um n� folha, as sub-arvores da esquerda e da direita s�o nulas
* inputs: o operando
* output: o endere�o do n� raiz criado
*/
Arv* CriaFolha(int peso, unsigned char c);

/*Imprime a �rvore em nota��o InOrder (esq, raiz, direita)
* inputs: o endere�o da raiz da �rvore
* output: nenhum
*/
void Imprime(Arv* arv);

/* Libera mem�ria alocada pela estrutura da �rvore
as sub-�rvores devem ser liberadas antes de se liberar o n� raiz
* inputs: o endere�o da raiz da �rvore
* output: uma �rvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv);



/* Retorna o valor correspondente � avalia��o da express�o representada na �rvore
* inputs: o endere�o da raiz da �rvore
* output: o valor da express�o
*/
// float Avalia(Arv* arv);



/* Retorna o n�mero de folhas da �rvore
* inputs: o endere�o da raiz da �rvore
* output: o n�mero de folhas
*/
int Folhas(Arv* arv);

/* Retorna a altura da �rvore
* inputs: o endere�o da raiz da �rvore
* output: a altura da �rvore
*/
int Altura(Arv* arv);

Arv* AcessarAtributoEsquerda(Arv* arv);

Arv* AcessarAtributoDireita(Arv* arv);

void GravarAtributoEsquerda(Arv* arv, Arv* esquerda);

void GravarAtributoDireita(Arv* arv, Arv* direita);

#endif // ARVORE_H_INCLUDED
