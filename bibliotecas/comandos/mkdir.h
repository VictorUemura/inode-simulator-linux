// Função que implementa o comando mkdir
void comandoMkdir(Bloco disco[], char comando[], char caminho[], int endRoot) {
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
	char *token2 = strtok(caminho, "/");
	printf("token2 %s\n", token2);
	while(token2 != )    
}

