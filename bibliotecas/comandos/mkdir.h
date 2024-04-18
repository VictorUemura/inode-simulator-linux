// Função que implementa o comando mkdir
void comandoMkdir(Bloco disco[], char comando[], char caminho[], int endRoot) {
    if(!haBlocosLivres(disco)) {
		printf("-bash: mkdir: No free blocks.\n");
        return;
	}
	
	// verifica se o comando mkdir contem argumentos
    if (strlen(comando) == 0) {
        printf("-bash: mkdir: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }
    
    // extrai o nome do diretorio novo
    char *token = strtok(comando, " ");
    token = strtok(NULL, " ");
    
    if (token == NULL) {
        printf("-bash: mkdir: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }
	
    char nomeDiretorio[50];
    strcpy(nomeDiretorio, token);
    
	// andar pelo caminho ate o inode do ultimo endereco
	int endAux = endRoot;
	char *token2 = strtok(caminho, "/");
	// implementar o andar pelos caminhos
	
	// busca entrada livre
	int endDiretorio;
	int endNovaEntrada;
	
	// se flag 0 nao encontrou se flag 1 encontrou entrada se flag 2 cria nova entrada
	int flag = 0;
	int endIndexDireto;
	int flagEntrada;
	int endEntrada;
	int endIndex;
	
	for(int i = 0; i < 5 && flag == 0; i++) {
		if(disco[endAux].inode.direto[i] == -1) {
			flag = 2;
			endIndexDireto = i;
		}
				
		else {
			flag = 1;
			// busca dentro das entradas para ver se existe posicao livre
			flagEntrada = 0;
			endEntrada = disco[endAux].inode.direto[i];
			
			for(int j = 0; j < 10 && flagEntrada == 0; j++) {
				if(disco[endEntrada].diretorio.entradas[j].inodeEndereco == -1) {
					flagEntrada = 1;
					endIndex = j;
				}
			}
			
			if(flagEntrada == 0)
				flag = 0;
		}
	}
	
	// tem uma entrada direta disponivel
	if(flag == 1) {
		int blocoLivre = obterBlocoLivre(disco);
		disco[blocoLivre] = initBlocoInode();
		disco[blocoLivre].inode = criaModeloInode(nomeDiretorio, 'd', "rw-r--r--");
		
		disco[endEntrada].diretorio.entradas[endIndex].inodeEndereco = blocoLivre;
		strcpy(disco[endEntrada].diretorio.entradas[endIndex].nome, nomeDiretorio);
	}
	if(flag == 2) {
		int blocoLivre = obterBlocoLivre(disco);
		disco[blocoLivre] = initBlocoDiretorio();
		
		int blocoLivreNovo = obterBlocoLivre(disco);
		disco[blocoLivre].diretorio.entradas[0].inodeEndereco = blocoLivreNovo;
		strcpy(disco[blocoLivre].diretorio.entradas[0].nome, nomeDiretorio);
	
		disco[blocoLivreNovo] = initBlocoInode();
		disco[blocoLivreNovo].inode = criaModeloInode(nomeDiretorio, 'd', "rw-r--r--");
	}
}

