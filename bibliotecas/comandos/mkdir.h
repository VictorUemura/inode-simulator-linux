// Função para criar um novo diretório
void criarDiretorio(char nomeDiretorio[], Bloco disco[], char caminho[], int endRoot) {
    // Verificar se há blocos livres disponíveis
    int blocoLivre = obterBlocoLivre(disco);
    if (blocoLivre == -1) {
        printf("Error: There are no free blocks available to create the directory.\n");
        return;
    }
    
    // Criar um novo inode para o diretório
    Inode inodeDiretorio = criaModeloInode(nomeDiretorio, 'd', "rw-r--r--");
    
    // Inicializar um novo bloco para o inode do diretório
    disco[blocoLivre] = initBlocoInode();
    disco[blocoLivre].inode = inodeDiretorio;
    
    // Atualizar a entrada do diretório pai com o novo diretório
    int indiceEntradaVazia = obterIndiceEntradaVazia(disco[endRoot].diretorio);
    if (indiceEntradaVazia == -1) {
        printf("Error: There is not enough space in the parent directory to add the new directory.\n");
        return;
    }
    
    // Adicionar a nova entrada ao diretório pai
    strcpy(disco[endRoot].diretorio.entradas[indiceEntradaVazia].nome, nomeDiretorio);
    disco[endRoot].diretorio.entradas[indiceEntradaVazia].inodeEndereco = blocoLivre;
    
    // Atualizar o caminho atual
    strcat(caminho, "/");
    strcat(caminho, nomeDiretorio);
    
    printf("Directory '%s' created successfully.\n", nomeDiretorio);
}

// Função que implementa o comando mkdir
void comandoMkdir(Bloco disco[], char comando[], char caminho[], int endRoot) {
    // Verificar se o comando mkdir contém argumentos
    if (strlen(comando) == 0) {
        printf("Error: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }
    
    // Extrair o nome do diretório do comando
    char *token = strtok(comando, " ");
    token = strtok(NULL, " ");
    
    if (token == NULL) {
        printf("Error: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }

    char nomeDiretorio[50];
    strcpy(nomeDiretorio, token);
    
    // Criar o diretório
    criarDiretorio(nomeDiretorio, disco, caminho, endRoot);
}

