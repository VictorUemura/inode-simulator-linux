// ============================= funcoes uteis ===========================================

// retorna 1 se existir algum bloco livre e 0 para o contrario
int haBlocosLivres(Bloco disco[]) {
	int flag = 0;    
    // Percorre cada pilha para verificar se há blocos livres
    for (int i = 0; i < qtdePilhas && flag == 0; i++) {
        if (!pilhaVazia(disco[i].pilha)) {
            flag = 1;
        }
    }
    return flag;
}

// retorna a quantidade total de blocos livres existentes dentro do disco
int calcularBlocosLivres(Bloco disco[]) {
    int totalBlocosLivres = 0;
    
    // Percorre cada pilha e conta os blocos livres
    for (int i = 0; i < qtdePilhas; i++) {
        totalBlocosLivres += disco[i].pilha.topo + 1;
    }
    
    return totalBlocosLivres;
}

void funcaoTesteQtdeBlocosLivres(Bloco disco[]) {
	int qtdeBlocosLivres = calcularBlocosLivres(disco);
	if(haBlocosLivres(disco))
		printf("Existem blocos livres: %d\n", qtdeBlocosLivres);
	else
		printf("Nao existem blocos livres");
}

// funcao que retorna o proximo bloco livre e -1 se nao tiver bloco livre
int obterBlocoLivre(Bloco disco[]) {
    int i, flag = 0;
    // Percorre cada pilha procurando por um bloco livre
    for (i = 0; i < qtdePilhas && flag == 0; i++) {
        if (!pilhaVazia(disco[i].pilha)) {
            flag = 1;
        }
    }
    if(flag == 1)
        return pop(disco[i - 1].pilha);
    return -1;
}


