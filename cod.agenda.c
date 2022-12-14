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

//lista inicia nula
Lista *inicializa() {
  
return NULL;
  
}

// fazer o cadastro na agenda
int cadastrar(Lista **l, int qtd, int tam){
    if(qtd<tam){
        Lista *novo = malloc(sizeof(Lista));//alocação dinamica de memória
        printf("\nDigite o nome da contato: ");
        scanf("%s[^\n]", novo->nome);
        printf("\nDigite o número de telefone do contato: ");
        scanf("%s[^\n]", novo->telefone);
        printf("Digite o email do contato: ");
        scanf("%s[^\n]", novo->email);
        getchar();
        l[qtd] = novo;
        return 1;
    }
    else{
        printf("\n\tNão foi possivel executar a ação!\n");
    }}

//Listar os dados dos contato presentes na agenda
void listar(Lista **l, int qtd){
    int i;
    printf("\n\tListando Contatos:\n");
    for(i=0; i<qtd; i++){
        printf("indice: %d\nNome: %s\nTelefone: %s\nEmail: %s", i+1, l[i]->nome, l[i]->telefone, l[i]->email);
    }
}
//alterar
void alterar(Lista **l, int qtd){
    int id;
    listar(l, qtd);
    printf("\n\tDigite o indice do contato que desejas alterar: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id>=0 && id < qtd){
        Lista *n = malloc(sizeof(Lista));
        printf("\nDigite o nome do contato: ");
        scanf("%s[^\n]", n->nome);
        printf("\nDigite o número de telefone do contato: ");
        scanf("%s[^\n]", n->telefone);
        printf("Digite o email do contato: ");
        scanf("%s[^\n]", n->email);
        getchar();
        l[id] = n;   
    }
    else{
        printf("\n\tÍndice inválido!\n");

    }
}
//excluir
int excluir(Lista **l, int qtd){
    int id;
    listar(l, qtd);
    printf("\n\tDigite o indice do contato da lista que desejas excluir: \n");
    scanf("%d", &id);
    getchar();
    id--;

    if(id>=0 && id < qtd){
       free(l[id]);
       if(id<qtd-1){
        l[id] = l[qtd -1];
       }
       return -1;
    }
    else{
        printf("\n\tÍndice inválido!\n");
        return 0;
    }
}

int main(){
    Lista *l[50];
    int opcao, t = 50, qt = 0;
              //tam    //quantidade
     printf("Agenda iniciada com sucesso\n");
     inicializa();


    do{
        printf("\nOpções de uso da Agenda:\n1-Cadastrar contatos\n2-Alterar contatos\n3-Listar contatos\n4-Excluir contato\n5-Sair da agenda\nEscolha uma opção: \n");
        scanf("%d", &opcao);
        getchar();
      

        switch(opcao){
            case 1:
                qt+= cadastrar(l, qt, t);
                break;
            case 2:
                alterar(l, qt);
                break;
            case 3:
                listar(l, qt);
                break;
            case 4:
            qt += excluir(l, qt);
                break;
            case 5:
            printf("Saída executada!");
                break;
            default:
                if(opcao != 6){
                    printf("\n\tOpção invalida!");
                }
            
        }
    }while(opcao != 7);
   
    listar(l, qt);

    return 0;
}