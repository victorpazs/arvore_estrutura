#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>


char perguntas[10][1000] = { "Você pretende comer sozinho?", "É vegetariano ou vegano?", "O grupo é de mais de 5 pessoas?", "O grupo é de mais de 5 pessoas?" };


typedef struct {
       int resposta;
       int position;
} INFORMACAO;


typedef struct arv {
       INFORMACAO info;   // pergunta feita ao usuário
       struct arv* subdireita;  // ponteiro para o nodo da direita
       struct arv* subesquerda;  // ponteiro para o nodo da esquerda
} ARVORE;

void criarArvore( ARVORE** r );  // inicializa �rvore com NULL
void imprimirPergunta( ARVORE* aux, int indice ); // visualiza��o da �rvore em tela, todos os registros
void insereFolha( ARVORE** r, int resp ); // insere folha na subárvore da pergunta - esquerda pra sim, direita pra não
void cria_folha( ARVORE* aux ); // cria a folha para a proxima pergunta;

int main()
{
    int op;       // op��o do menu
    ARVORE* r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros

    setlocale(LC_ALL, "Portuguese");

    while( 1 ){
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Menu do usuário" );
         printf( "\n [1] Começar");
		 printf( "\n [0] Para sair do programa" );
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Opcao: " );
         scanf("%d", &op);

        switch( op ) {
           case 1:   // cria a arvore
                   criarArvore( &r );
                   break;
           case 0:  // t�rmino do programa
                   exit( 1 );
                   break;
           default:
                   printf( "\n Digite uma opcao!" );
                   break;
        } // troca as opções no menu

        fflush( stdin ); // limpa buffer
        printf( "\n" );
     } // fim do loop

 return 0;
}


//funcao que imprime as perguntas da arvore
void imprimirPergunta( ARVORE* aux, int indice ){
    int opt = 0;
    if( aux != NULL ){              // verifica se a raiz � diferente de vazio
        printf( "\n Pergunta: \n");
        printf("%s", perguntas[indice]);
        printf( "\n");
        printf( "\n[1] - SIM");
        printf( "\n[2] - NÃO");
        printf( "\nOpção:");
        scanf("%d", &opt);
        if (opt == 1 || opt == 2){
            aux->info.resposta = opt;
        } else {
            printf("Opção inválida!");
            exit(1);
        }
        insereFolha( &aux, opt );
        system( "cls" );
        if (opt == 1){
          imprimirPergunta( aux->subesquerda, indice + 1 );
        } else if (opt == 2){
          imprimirPergunta( aux->subdireita, indice + 2 );
        }


    }
    else
       printf("\nNenhuma pergunta a se exibir!");
}


//função que cria a arvore
void criarArvore( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta
    system( "cls" );
    imprimirPergunta( &r, 0 );
}

void insereFolha( ARVORE** p, int resp ){
      if( *p == NULL ){                                     // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
         no->subdireita= NULL;                                 // inicializa sub�rvore da direita
         no->subesquerda= NULL;								 // inicializa sub�rvore da esquerda
         *p= no;                                         // anterior aponta para novo registro
         printf( "\n Registro inserido!" );
   }else{
         if ( resp == 1 )                   // verifica se c�digo a ser inserido � menor que o valor do registro para qual o p aponta
              insereFolha( &(*p)->subesquerda, resp );      // anda com o ponteiro p para a esquerda, pois o c�digo procurado � menor
         else insereFolha( &(*p)->subdireita, resp ); // anda com o ponteiro p para a direita, pois o c�digo procurado � maior

		 }

}

void cria_folha( ARVORE* aux )
{
    aux->subdireita = NULL;    // n�o aponta
    aux->subesquerda = NULL;    // n�o aponta

}
