int pegaNome(const char *comando, char *arquivo) {
    char comando_copy[256];
    strcpy(comando_copy, comando);

    char *token = strtok(comando_copy, " ");
    
    if (token == NULL || strcmp(token, "rm") != 0) {
        arquivo[0] = '\0';
        return -2; 
    }

    token = strtok(NULL, " ");
    
    if (token != NULL && strtok(NULL, " ") == NULL) {
        strcpy(arquivo, token);
        return 0; 
    } else {
        arquivo[0] = '\0';
        return -1; 
    }
}

void comandoRm(char comando[], Bloco disco[], int endRoot){
    char nomeArq[50];
    int flag;
    
    flag = pegaNome(comando, nomeArq);

    if (flag == 0){
    	int endAux = endRoot;
    	for(int i = 0; i < 5 ; i++){
    		if(strcmp(disco[endAux].inode.nome, pegaNome) == 0)
    			disco[endAux].tipo = '-';
    	}
		
    } 
    else if(flag == -1)
    	printf("-bash: fm: invalid argument\n", comando);
    else
    	printf("rm: missing operand)
    
}

