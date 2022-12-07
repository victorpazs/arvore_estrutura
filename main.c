#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //necessário para strcpy - função que adiciona a string de pergunta para a pergunta do nodo




typedef struct {
       char resposta[10], pergunta[1000];
} INFORMACAO;


typedef struct arv {
       INFORMACAO info;   // pergunta e resposta
       struct arv* subd;  // ponteiro para o nodo da direita
       struct arv* sube;  // ponteiro para o nodo da esquerda
} ARVORE;

void criarArvore(ARVORE** r);  // inicializa �rvore vazia

void inserePerguntas(ARVORE** r); //insere todas as perguntas da árvore

void printaHistorico(ARVORE* aux);

void percorrePerguntas(ARVORE** p);



int main()
{
    int op = -1;       // op��o do menu

    ARVORE* r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros
    setlocale(LC_ALL, "");
    criarArvore(&r);
    inserePerguntas(&r);

    while( op != 0 ){

         system("cls");
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Menu\n");
         printf( "\n [1] Começar");
         printf( "\n [2] Ver histórico");
         printf( "\n [3] Limpar histórico");
		 printf( "\n [0] Para sair do programa" );
         printf( "\n /---------------------------------------------------/" );
         printf( "\n Opção: " );
         scanf("%d", &op);

        switch( op ) {
           case 1:   // faz as perguntas e grava as respostas do lead
               if (strcmp(r->info.resposta, "") == 0){
                percorrePerguntas(&r);
               } else {
                    limpaHistorico( r );
                    criarArvore(&r);
                    inserePerguntas(&r);
                    percorrePerguntas(&r);
               }
                break;
         case 2:   // mostra o historico pro lead
             if (strcmp(r->info.resposta, "") == 0){
                system("cls");
                printf("Nenhum histórico a ser exibido");
                printf("\nPressione ENTER para voltar ao menu");
                getch();
             } else {
                system("cls");
                printf("\n======================\n");
                printf( "Seu histórico de respostas:");
                printf("\n======================\n");
                printaHistorico( r );
                printf("\n\nPressione ENTER para voltar ao menu");
                getch();
             }
               break;
         case 3:
            limpaHistorico( r );
            criarArvore(&r);
            inserePerguntas(&r);
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

//função que cria a arvore
void criarArvore( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta

}

void inserePerguntas( ARVORE** r ) {


    //perguntas do lado direito da árvore
    ARVORE* pd1 = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria
    strcpy(pd1->info.pergunta, "Você gosta de doces?"); // cola a pergunta no
    pd1->subd= NULL;                                 // inicializa sub�rvore da direita
    pd1->sube= NULL;								 // inicializa sub�rvore da esquerda

    //pd1 = sim
    ARVORE* pd2 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(pd2->info.pergunta, "Que tal uma sobremesa gelada?");
    pd1->sube = pd2;
    pd2->subd= NULL;
    pd2->sube= NULL;


    //pd1 = nao
    ARVORE* rpd1 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpd1->info.pergunta, "Gostaria de uma salada de frutas?");
    pd1->subd = rpd1;
    rpd1->subd= NULL;
    rpd1->sube= NULL;

    //pd2 = sim
    ARVORE* rpd2 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpd2->info.resposta, "Gostaria de um sorvete?");
    pd2->sube = rpd2;
    rpd2->subd= NULL;
    rpd2->sube= NULL;

    //pd2 = não
    ARVORE* pd3 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(pd3->info.pergunta, "O que você acha de uma sobremesa quente?");
    pd2->subd = pd3;
    pd3->subd= NULL;
    pd3->sube= NULL;


    //pd3 = sim
    ARVORE* rpd3sim = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpd3sim->info.pergunta, "Gostaria de um brownie?");
    pd3->sube = rpd3sim;
    rpd3sim->subd= NULL;
    rpd3sim->sube= NULL;

    //pd3 = nao
    ARVORE* rpd3nao = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpd3nao->info.pergunta, "O que acha de comprar um petit gateau (peti gatô)?");
    pd3->subd = rpd3nao;
    rpd3nao->subd= NULL;
    rpd3nao->sube= NULL;

    // lado esquerdo da árvore

    ARVORE* pe1 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(pe1->info.pergunta, "Gosta de lanches fritos?");
    pe1->subd= NULL;
    pe1->sube= NULL;

    //pe1 = sim
    ARVORE* rpe1 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpe1->info.pergunta, "O que você acha de uma porção de batata frita?");
    pe1->sube = rpe1;
    rpe1->subd= NULL;
    rpe1->sube= NULL;

    //pe1 = nao
    ARVORE* pe2 = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(pe2->info.pergunta, "Você gosta de lanches assados?");
    pe1->subd = pe2;
    pe2->subd= NULL;
    pe2->sube= NULL;

    //pe2 = sim
    ARVORE* rpe2sim = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpe2sim->info.pergunta, "Uma pizza seria do seu agrado?");
    pe2->sube = rpe2sim;
    rpe2sim->subd= NULL;
    rpe2sim->sube= NULL;

    //pe2 = nao
    ARVORE* rpe2nao = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(rpe2nao->info.pergunta, "Que tal um sanduíche?");
    pe2->subd = rpe2nao;
    rpe2nao->subd= NULL;
    rpe2nao->sube= NULL;


    //raiz pergunta inicial
    ARVORE* perguntaRaiz = ( ARVORE * ) malloc ( sizeof( ARVORE ));
    strcpy(perguntaRaiz->info.pergunta, "Você gostaria de um salgado?");
    strcpy(perguntaRaiz->info.resposta, "");
    perguntaRaiz->subd= pd1;
    perguntaRaiz->sube= pe1;
    *r = perguntaRaiz;
}

void percorrePerguntas(ARVORE** p) {
    char resposta[4];

    if (*p != NULL){
        system("cls");
        printf("\n======================\n");
        printf("Pergunta: %s", (*p)->info.pergunta);
        printf("\n======================\n");
        printf("\nResposta: ");
        scanf("%s.3", &resposta);

        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0 || strcmp(resposta, "SIM") == 0 || strcmp(resposta, "s") == 0){
            strcpy((*p)->info.pergunta, (*p)->info.pergunta);
            strcpy((*p)->info.resposta, resposta);
            percorrePerguntas(&(*p)->sube);
        } else if (strcmp(resposta, "não") == 0 || strcmp(resposta, "NÃO") == 0 || strcmp(resposta, "Não") == 0 || strcmp(resposta, "nao") == 0 || strcmp(resposta, "n") == 0 ){
            strcpy((*p)->info.pergunta, (*p)->info.pergunta);
            strcpy((*p)->info.resposta, resposta);
            percorrePerguntas(&(*p)->subd);
        } else {
            printf("\nOpção inválida!");
            printf("\nPressione ENTER para tentar novamente!");
            getch();
            percorrePerguntas(&(*p));
        }
    }
}

void printaHistorico(ARVORE* aux) {
   if( aux != NULL ){
        printf("\n======================\n");
        printf("Pergunta: %s", aux->info.pergunta);
        printf("\nResposta: %s", aux->info.resposta);
        printf("\n======================");
    if (strcmp(aux->info.resposta, "sim") == 0 || strcmp(aux->info.resposta, "Sim") == 0 || strcmp(aux->info.resposta, "SIM") == 0 || strcmp(aux->info.resposta, "s") == 0){
            printaHistorico(aux->sube);
        } else if (strcmp(aux->info.resposta, "não") == 0 || strcmp(aux->info.resposta, "NÃO") == 0 || strcmp(aux->info.resposta, "Não") == 0 || strcmp(aux->info.resposta, "nao") == 0 || strcmp(aux->info.resposta, "n") == 0 ){
            printaHistorico(aux->subd);
    }

}
}

void limpaHistorico(ARVORE* a){
    if (a != NULL) {
    limpaHistorico(a->subd);
    limpaHistorico(a->sube);
    free(a);
}
}
