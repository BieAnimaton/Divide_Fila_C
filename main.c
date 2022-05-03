//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------
#define tamanho 10  // tamanho maximo da FILA
/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/



typedef struct fila{
        int item [tamanho] ;
        int inicio, fim;
} T_FILA;



// ==================================================================
int  inicializa (T_FILA *f)
{
  (*f).inicio = -1;
  (*f).fim = -1;
  return 0;
}


// ==================================================================
int estado(T_FILA f)
{
    if ((f.inicio == -1 ) || (f.inicio == tamanho) || (f.inicio == f.fim+1))
       return 0;  // fila vazia
    else {
       if (f.fim == tamanho-1 )
          return 1;   // fila cheia
       else
          return 2;  // fila não vazia com capacidade de armazenamento
    }
}



// ==================================================================
int insere(T_FILA *f, int x)
{

    int erro = estado (*f);
    if ((erro == 0) || (erro == 2))
    {
       (*f).fim++;
       (*f).item[(*f).fim]=x;// inserção efetuada
       if ((*f).inicio == -1)
          (*f).inicio = 0;
       return 0;
    }
    else
       return 1; // impossivel inserção. overflow
}



// ==================================================================
int remover(T_FILA *f)
{
    int erro = estado (*f);
    if (erro != 0)
    {
      (*f).inicio++;  // remocao efetuada
       return 0;
    }
    else
       return 1; // impossivel remover. Underflow
}



// ==================================================================
int listar(T_FILA f)
{  int i,erro;
    erro = estado (f);
    if ((erro == 1) || (erro ==2))
    {
       for (i=f.inicio; i<=f.fim; i++)
           printf("%d - ",f.item[i]);
       printf("\n");
       return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}




// ==================================================================
int obter_primeiro(T_FILA f, int *dado)
{
    if ((f.inicio == -1 ) || (f.inicio == tamanho) || (f.inicio == f.fim+1))
       return 1;   // fila vazia
    else {
       *dado =  f.item[f.inicio];
       return 0;
    }
}
// ==================================================================
// ==================================================================



// ==================================================================
int divide_fila (T_FILA *F, T_FILA *F1, T_FILA *F2) {
    int i, erro, metade_fila, dado;
    erro = estado (*F);

    printf("\n");
    if ((erro == 1) || (erro ==2)) {
        if ((*F).fim % 2 != 0) {
            metade_fila = (*F).fim / 2;



            for (i = (*F).inicio; i <= metade_fila; i++) {
                //printf("%d) ", (*F).item[i]);
                obter_primeiro(*F, &dado);
                remover(F);
                insere(F1, dado);
            }
            for (i = metade_fila; i < (*F).fim; i++) {
                //printf("%d ", (*F).item[i]);
                obter_primeiro(*F, &dado);
                remover(F);
                insere(F2, dado);
            }
            printf("\n");
        } else {
            printf("Lista ímpar. Impossivel achar metade!");
            return 6;
        }

        return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}
// ==================================================================
// ==================================================================


int main(void)
{
    int info;
    int erro; /* valor de erro retornado pelas funcoes */
    // Criar pilhas
    T_FILA s, f1, f2;

    // Inicializa pilhas
    inicializa (&s);
    inicializa (&f1);
    inicializa (&f2);

    //remover(&s);

    insere(&s, 102);
    insere(&s, 56);
    insere(&s, 7);
    insere(&s, 12);
    insere(&s, 23);
    insere(&s, 1);
    insere(&s, 2);
    insere(&s, 56);
    insere(&s, 67);
    insere(&s, 99);

    printf("Fila total: ");
    listar(s);

    divide_fila (&s, &f1, &f2);

    printf("Fila F1: ");
    listar(f1);

    printf("Fila F2: ");
    listar(f2);

    //obter_primeiro(s, &info);
}
