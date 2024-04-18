// ============================= bibliotecas padroes da linguagem ============================

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<windows.h>
#include <ctype.h>
#include <time.h>

// ============================= constantes definidas =========================================

#define TAM_PADRAO_BLOCOS 1000
#define TAM_PADRAO_PILHAS 91

// ============================= variaveis globais definidas para utilizacao ==================

int qtdeBlocos = TAM_PADRAO_BLOCOS; // valor padrao de quantidade
int qtdePilhas = TAM_PADRAO_PILHAS; // numero padrao de plihas para insercao nos blocos


// ============================= bibliotecas desenvolvidas ===================================

#include "./bibliotecas/estruturas.h"
#include "./bibliotecas/importacomandos.h"
#include "./bibliotecas/cliconfig.h"
#include "./bibliotecas/utils.h"

// ============================= funcoes para definicao de blocos =============================

// inicializa o bloco
Bloco initBlocoPilha(int prox) {
	Bloco novo;
	novo.tipo = 'R'; // bloco reservado para a pilha
	initPilha(novo.pilha, prox);
	
	return novo;
}

// retorna a quantidade de pilhas de acordo com o numero de blocos definidos
/*
// versao 1
int pilhasQtde() {
	int auxBlocos = qtdeBlocos;
	int qtdePilhasInt;
	
	while(auxBlocos % 10 != 0)
		auxBlocos++;
	int porcent = auxBlocos * 0.10;
	if(auxBlocos >= 100) {
		if(porcent >= 10)
			porcent /= 10;
		qtdePilhasInt = auxBlocos / 10 - porcent;
	}
	else {
		qtdePilhasInt = auxBlocos / 10;
		if(qtdeBlocos % 10 == 1)
			qtdePilhasInt--;
	}
	
	return qtdePilhasInt;
}
*/

// versao 2
int pilhasQtde() {
	int auxBlocos = qtdeBlocos;
	int qtdePilhasInt;

	int pilhasCheias = auxBlocos / 10;
	int qtdeRetirada = pilhasCheias / 10;
	qtdePilhasInt = pilhasCheias - qtdeRetirada;
	
	int qtdeAtualBlocos = auxBlocos - qtdePilhasInt * 10 - qtdePilhasInt;
	if(qtdeAtualBlocos >= 1)
		qtdePilhasInt++;
	
	return qtdePilhasInt;
}

// cria as pilhas
void criaPilha(Bloco disco[]) {
	
    // numero de pilhas necessaria para alocar os blocos
	int numPilhas = pilhasQtde();
	printf("Quantidade de pilhas definidas para: %d.\n", numPilhas);
	
	// calcula o numero inicial
	int numeroInicial = numPilhas; 
    
    // cria o vetor de pilhas
    for(int i = 0; i < numPilhas; i++) {
    	disco[i] = initBlocoPilha(i + 1);
    }
    
    printf("Pilhas criadas\n");
    
    // preenche cada vetor com as posicoes disponiveis em disco
    int qtdeAtual = qtdeBlocos - 1, index = 0;
    for (int i = numPilhas - 1; i >= 0; i--, index++) {
        for (int j = 0; j < 10 && qtdeAtual >= numPilhas; j++) {
            push(disco[i].pilha, qtdeAtual);
            qtdeAtual--;
        }
    }
    
    qtdePilhas = numPilhas;
    printf("Pilhas preenchidas\n");
}

void defineQtdeBlocos() {
    char input[20];
	printf("Informe a quantidade de blocos para o programa [-1:PADRAO MAX = 1000]:");
    
	fflush(stdout);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    qtdeBlocos = atoi(input);
    
	if(qtdeBlocos <= 10 || qtdeBlocos > 1000) {
		printf("Quantidade invalida - UTILIZANDO TAMANHO PADRAO\n");
        qtdeBlocos = 1000;
	} else
		printf("QUANTIDADE DEFINIDA PARA: %d\n", qtdeBlocos);
}

void testeExibicaoPilhas(Bloco disco[]) {
    printf("Exibindo pilhas:\n");
    for (int i = 0; i < qtdePilhas; i++) {
        printf("Pilha %d:\n", i + 1);
        Pilha pilha = disco[i].pilha;
        printf("Topo: %d\n", pilha.topo);
        printf("Blocos livres: ");
        for (int j = 0; j <= pilha.topo; j++) {
            printf("%d ", pilha.vetor[j]);
        }
        printf("\n");
    }
}

void initCli() {
	defineQtdeBlocos();
}

// ============================= inicializa o diretorio do root  =========================

void initRoot(Bloco disco[], int &endRoot) {
	Inode inodeRoot = criaModeloInode("~", 'd', "rw-r--r--");
	
	endRoot = obterBlocoLivre(disco);
	
	if(endRoot != -1) {
		disco[endRoot] = initBlocoInode();
		disco[endRoot].inode = inodeRoot;
		textcolor(LIGHTGREEN); printf("Root inicializado...\n");
		textcolor(WHITE); printf("Direcionando para o terminal...\n");
	}
}

// ============================= interface da CLI do programa ============================

void CLI(Bloco disco[], int endRoot) {
	// o caminho inicial e "~" ja determinado
	char comando[100], comandoFlag[100], caminho[100] = "~";
	int codigoComando;
	
	while(true){
		exibeLinhaComando(caminho);
		codigoComando = leituraComando(comando, comandoFlag);
		
		menuComando(codigoComando, comando, comandoFlag, disco, caminho);
	}
}

// ============================= funcao para chamar testes ===============================

void teste(Bloco disco[]) {
	testeCodigoPrimeiroComando("ls");
	funcaoTesteQtdeBlocosLivres(disco);
	testeExibicaoPilhas(disco);
}

// =======================================================================================

int main(void) {
	int endRoot;
	
	// inicio do programa para a definicao do disco
	initCli();
	Bloco disco[qtdeBlocos];
	criaPilha(disco);
	
	initRoot(disco, endRoot);
	
	Sleep(2000);
	system("cls");
	
	teste(disco); // <- funcao que chama os testes criados - tire o comentario para testar
	CLI(disco, endRoot);
	return 0;
}
