#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>



typedef struct arv {
       int resposta; //resposta para a pergunta
       char pergunta[100];   // pergunta feita ao usuário
       struct arv* subdireita;  // ponteiro para o nodo da direita
       struct arv* subesquerda;  // ponteiro para o nodo da esquerda
} ARVORE;


void imprimirArvore( ARVORE* aux ); // visualiza��o da �rvore em tela, todos os registros
void criarArvore( ARVORE** r );  // inicializa �rvore com NULL

int main()
{
    int op;       // op��o do menu
    ARVORE* r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros

    setlocale(LC_ALL, "Portuguese");
    criarArvore( &r );

    while( 1 ){
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Menu do usuário                                      " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [2] Imprime                                          " );
		 printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Opcao: " );
         scanf("%d", &op);

        switch( op ) {
           case 1:   // cria a arvore
                   criarArvore( &r );
                   break;

           case 2:   // imprime a árvore atual
                    imprimirArvore( r );
                   break;
           case 0:  // t�rmino do programa
                   exit( 1 );
                   break;

           default :
                   printf( "\n Digite uma opcao!" );
                   break;
        } // troca as opções no menu

        fflush( stdin ); // limpa buffer
        printf( "\n" );
     } // fim do loop

 return 0;
}


//funcao que imprime a arvore
void imprimirArvore( ARVORE* aux ){

    if( aux != NULL ){              // verifica se a raiz � diferente de vazio
        printf( "\n Pergunta: \n");
        printf("%s", aux->pergunta);
        printf( "\n >> sube" );
        imprimirArvore( aux->subesquerda ); // recursivo, segue pelo caminho da esquerda
        printf( "\n >> subd" );
        imprimirArvore( aux->subdireita ); // recursivo, segue pelo caminho da direita
    }
    else
       printf("\n �rvore vazia!");
}


//função que cria a arvore
void criarArvore( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta
}




