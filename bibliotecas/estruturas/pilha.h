#define TL_PILHA 10

struct Pilha {
	int topo;
	int vetor[TL_PILHA];
	int endProx;
};

// inicializa a pilha
void initPilha(Pilha &pilha, int prox) {
	pilha.topo = -1;
	pilha.endProx = prox;
}

char pilhaVazia(Pilha pilha) {
	return pilha.topo == -1;
}

char pilhaCheia(Pilha pilha) {
	return pilha.topo == TL_PILHA - 1;
}

void push(Pilha &pilha, int value) {
	if(pilha.topo != TL_PILHA - 1) {
		pilha.vetor[pilha.topo++] = value;
	}
}

int pop(Pilha &pilha) {
	if(!pilhaVazia(pilha)) {
		int index = pilha.vetor[pilha.topo--];
		return index;
	}
	return -1;
}
