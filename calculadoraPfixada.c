#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct pilha {
  int topo;
  float vet[MAX];
};
typedef struct pilha Pilha;

Pilha *cria() {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0; 
  return p;
}

void insere(Pilha *p, int valor) {
  if (p->topo == MAX) {
    printf("Pilha cheia");
    exit(1);
  }
  p->vet[p->topo] = valor;
  p->topo++;
}

struct calculadora{ 
  Pilha* p; 
};

typedef struct calculadora Calculadora;

Calculadora* cria_calculadora(){
 	Calculadora* c = (Calculadora*) malloc(sizeof(Calculadora));
  c->p = cria(); 
 	return c;
}

void opera(Calculadora* c){
    int operacao;
    int opcao;
	  float valor1, valor2, resultado;
	do{
        printf("\nDigite 1 para utilizar a calculadora ou digite 2 para encerrar a calculadora: ");
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("Escolha o primeiro termo: ");
            scanf("%f", &valor1);
            printf("Escolha o segundo termo: ");
            scanf("%f", &valor2);
            printf("\tDigite:\n-1 para somar\n-2 para subtrair\n-3 para dividir\n-4 para multiplicar\n\tSua escolha: ");
            scanf("%d", &operacao);
            switch(operacao){
              case 1:
                    resultado = valor1 + valor2;
                    printf("\nResultado: %.2f\n", resultado); 
                    break;
 		          case 2: 
 			              resultado = valor1 - valor2; 
 			              printf("\nResultado: %.2f\n", resultado);  
                    break;
 		          case 3: 
                    resultado = valor1 / valor2;
                    printf("\nResultado: %.2f\n", resultado);   
 			              break;
 		          case 4 : 
 			              resultado = valor1 * valor2; 
 		        	      printf("\nResultado: %.2f\n", resultado); 
                    break; 
              default :
                    printf ("\nOperação invalida!\n");
                }
            insere(c->p, resultado);    
            }
            else if(opcao == 2){
              printf("Calculadora encerrada!");
            }
            else{
              printf("Digite uma opção válida!");
            }
    }
    while(opcao !=2);
}
        
int main() { 
  Calculadora* l;
  l = cria_calculadora("%.2f");
  opera(l);

  return 0; 
}
