#include <stdio.h>
#include <stdlib.h>
/*— agenda::
nome;
telefone;
email;

método: 
listar, criar, apagar, alterar.

módulo h e c.*/
typedef struct{
    char nome[50];
    char telefone[15]; //coloquei como char pois pode ter parenteses, traço e etc...
    char email[100];
}Lista;
Lista *inicializa();
int cadastrar(Lista **l, int qtd, int tam);
void listar(Lista **l, int qtd);
void alterar(Lista **l, int qtd);
int excluir(Lista **l, int qtd);

