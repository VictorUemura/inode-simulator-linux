void criarDiretorio(char nomeDiretorio[], Bloco disco[], char caminho[], int endRoot) {
    int blocoLivre = obterBlocoLivre(disco);
    
    // verifica se existe algum bloco livre
    if (blocoLivre == -1) {
        printf("Error: There are no free blocks available to create the directory.\n");
        return;
    }
    
    Inode inodeDiretorio = criaModeloInode(nomeDiretorio, 'd', "rw-r--r--");
    
    disco[blocoLivre] = initBlocoInode();
    disco[blocoLivre].inode = inodeDiretorio;
    
    // Atualizar a entrada do diret�rio pai com o novo diret�rio
    // Esta parte precisa ser implementada de acordo com a l�gica do seu sistema de arquivos
    // Por exemplo, voc� precisa verificar a estrutura do diret�rio pai e atualizar suas entradas conforme necess�rio
    
    // Exemplo de atualiza��o da estrutura de diret�rio do root
    // Isso pode variar dependendo da estrutura exata do seu sistema de arquivos
    // Aqui, assumimos que o diret�rio root � um diret�rio padr�o com uma estrutura de array de entradas de diret�rio

    // Verificar se h� espa�o na entrada do diret�rio pai para adicionar o novo diret�rio
    if (indiceEntradaVazia == -1) {
        printf("Erro: N�o h� espa�o suficiente no diret�rio pai para adicionar o novo diret�rio.\n");
        return;
    }
    
    // Adicionar a nova entrada ao diret�rio pai
    strcpy(disco[0].diretorio.entradas[indiceEntradaVazia].nome, nomeDiretorio);
    disco[0].diretorio.entradas[indiceEntradaVazia].inodeEndereco = blocoLivre;
    
    // Atualizar o caminho atual
    strcat(caminho, "/");
    strcat(caminho, nomeDiretorio);
    
    printf("Diret�rio '%s' criado com sucesso.\n", nomeDiretorio);
}

void comandoMkdir(Bloco disco[], char comando[], char caminho[], int endRoot) {
    // verifica se mkdir contem argumentos
    if (strlen(comando) == 0) {
        printf("Error: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }
    
    // recupera o nome do diretorio
    char *token = strtok(comando, " ");
    token = strtok(NULL, " ");
    
    if (token == NULL) {
        printf("Error: The 'mkdir' command requires an argument (directory name to be created).\n");
        return;
    }

    char nomeDiretorio[50];
    strcpy(nomeDiretorio, token);
    
    // busca diretorio
    
    criarDiretorio(nomeDiretorio, disco, caminho);
}
