// ============================= bibliotecas padroes da linguagem ============================

#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<windows.h>
#include <ctype.h>

// ============================= bibliotecas desenvolvidas ===================================

#include "bloco.h"
#include "cliconfig.h"

// ============================= constantes definidas =========================================

#define TAM_PADRAO_BLOCOS 1000
#define TAM_PADRAO_PILHAS 90

// ============================= variaveis globais definidas para utilizacao ==================

int qtdeBlocos = TAM_PADRAO_BLOCOS; // valor padrao de quantidade
int qtdePilhas = TAM_PADRAO_PILHAS; // numero padrao de plihas para insercao nos blocos

// ============================= funcoes para definicao de blocos =============================

// inicializa o bloco
Bloco initBlocoPilha(int prox) {
	Bloco novo;
	novo.tipo = 'R'; // bloco reservado para a pilha
	initPilha(novo.pilha, prox);
	
	return novo;
}

// retorna a quantidade de pilhas de acordo com o numero de blocos definidos
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

// cria as pilhas
void criaPilha(Bloco disco[]) {
	
    // numero de pilhas necessaria para alocar os blocos
	int numPilhas = pilhasQtde();
	printf("Quantidade de pilhas definidas\n");
	
	// calcula o numero inicial
	int numeroInicial = numPilhas; 
    
    // cria o vetor de pilhas
    for(int i = 0; i < numPilhas; i++) {
    	disco[i] = initBlocoPilha(i + 1);
    }
    
    printf("Pilhas criadas\n");
    
    // preenche cada vetor com as posicoes disponiveis em disco
    int qtdeAtual = qtdeBlocos - 1;
    for (int i = 0; i < numPilhas; i++) {
        for (int j = 0; j < 10 && qtdeAtual >= 0; j++) {
            push(disco[i].pilha, qtdeAtual--);
        }
    }
    
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

void initCli() {
	defineQtdeBlocos();
}

// ============================= funcoes uteis ===========================================


// ============================= interface da CLI do programa ============================

void CLI(Bloco disco[]) {
	// o caminho inicial e "~" ja determinado
	char comando[100], comandoFlag[100], caminho[100] = "~";
	int codigoComando;
	
	while(true){
		
		exibeLinhaComando(caminho);
		codigoComando = leituraComando(comando, comandoFlag);
		
		menuComando(codigoComando);
	}
}

// ============================= funcao para chamar testes ===============================

void teste() {
	testeCodigoPrimeiroComando("ls");
}

// =======================================================================================

int main(void) {
	// inicio do programa para a definicao do disco
	initCli();
	Bloco disco[qtdeBlocos];
	criaPilha(disco);
	
	Sleep(2000);
	system("cls");
	
	CLI(disco);
	return 0;
}
