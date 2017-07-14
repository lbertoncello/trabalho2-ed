#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore Arv;

int RetornaPeso(Arv *a);

Arv* CriaVazia(void);

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaNo(int peso, Arv* esq, Arv* dir);

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaFolha(int peso, unsigned char c);

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv);

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv);



/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
// float Avalia(Arv* arv);



/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv);

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv);

Arv* AcessarAtributoEsquerda(Arv* arv);

Arv* AcessarAtributoDireita(Arv* arv);

void GravarAtributoEsquerda(Arv* arv, Arv* esquerda);

void GravarAtributoDireita(Arv* arv, Arv* direita);

#endif // ARVORE_H_INCLUDED
