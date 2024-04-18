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

// busca um nome de inode dentro de um bloco do tipo de diretorio pelo nome do inode
int buscaInodePorEnderecoDiretorio(Diretorio diretorio, char nome[]) {
	int flag = 0;
	for(int i = 0; i < 10; i++) {
		if(diretorio.entradas[i].inodeEndereco != -1) {
			if(strcmp(diretorio.entradas.nome, nome) == 0)
				return diretorio.entradas.inodeEndereco;
		}
	}
	return -1;
}

// busca diretorio pelo seu nome com o endereco de algum diretorio com entradas
int buscaDiretorio(Bloco disco[], int endDiretorio, char nome[]) {
	int endInodeDiretorio;
	
	endInodeDiretorio = buscaInodePorEnderecoDiretorio(disco[end].diretorio, nome);
	if(endInodeDiretorio != -1)
		return endInodeDiretorio;
	return -1;
}

int buscaDiretorioInode(Bloco disco[], int endInode, char nome[]) {
	int enderecoBuscado;
	for(int i = 0; i < 5; i++) {
		int end = disco[endInode].inode[direto];
		if(end != -1) {
			enderecoBuscado = buscaDiretorio(disco, end, nome);
			if(enderecoBuscado != -1)
				return enderecoBuscado;
		}
	}
	return -1;
}

