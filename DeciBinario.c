#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct fila{
    No *prim;
    No *fim;
    int tam;
}Fila;
typedef struct fila Fila;

Fila* criar_fila(){
    Fila *fila;
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->prim == NULL){
            fila->prim = novo;
            fila->fim = novo;
        }
        else{
            fila->fim->proximo = novo;
            fila->fim = novo;
        }
        fila->tam++;
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(Fila *fila){
    No *remover = NULL;

    if(fila->prim){
        remover = fila->prim;
        fila->prim = remover->proximo;
        fila->tam--;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(Fila *fila){
    No *aux = fila->prim;
    printf("\t------- FILA --------\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}
void liberar(Fila *f) { free(f); }
int vazia(Fila *f) {
return (f->prim == NULL);
}
void decbin(int n, char * t)
{
Fila * f = criar_fila();
do{
    inserir_na_fila(f,n%2);
    n /= 2;
} while (n);

while (!vazia(f)){
    *t++ = '0'+ remover_da_fila(f);
    *t = '\0';
    liberar(f);
  }
}

int main(){
    No *r;
    Fila *fila;
    int opcao, valor;
    char bin[10];
    

    criar_fila();

    do{
        printf("\tOpções:\n\t0 - Sair\n\t1 - Inserir o valor a ser convertido\n\t2 - Imprimir\nDigite sua escolha: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(fila, valor);

            decbin(valor,bin);
            printf("O valor em binário fica: %d(dec) -> %s(binario)\n",valor,bin);
            break;
        case 2:
            imprimir(fila);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}