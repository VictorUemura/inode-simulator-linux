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
    
    // Atualizar a entrada do diretório pai com o novo diretório
    // Esta parte precisa ser implementada de acordo com a lógica do seu sistema de arquivos
    // Por exemplo, você precisa verificar a estrutura do diretório pai e atualizar suas entradas conforme necessário
    
    // Exemplo de atualização da estrutura de diretório do root
    // Isso pode variar dependendo da estrutura exata do seu sistema de arquivos
    // Aqui, assumimos que o diretório root é um diretório padrão com uma estrutura de array de entradas de diretório

    // Verificar se há espaço na entrada do diretório pai para adicionar o novo diretório
    if (indiceEntradaVazia == -1) {
        printf("Erro: Não há espaço suficiente no diretório pai para adicionar o novo diretório.\n");
        return;
    }
    
    // Adicionar a nova entrada ao diretório pai
    strcpy(disco[0].diretorio.entradas[indiceEntradaVazia].nome, nomeDiretorio);
    disco[0].diretorio.entradas[indiceEntradaVazia].inodeEndereco = blocoLivre;
    
    // Atualizar o caminho atual
    strcat(caminho, "/");
    strcat(caminho, nomeDiretorio);
    
    printf("Diretório '%s' criado com sucesso.\n", nomeDiretorio);
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
