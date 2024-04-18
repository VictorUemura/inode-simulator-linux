int pegaNumero(char comando[]){
	int numero;
    if (strncmp(comando, "bad ", 4) != 0) {
        return -1;
    }
    int i = 4;
    
    while (comando[i] != '\0') {
        if (!isdigit(comando[i])) {
            return -1;
        }
        i++;
    }

    sscanf(comando,"%*s %d", &numero);
    return numero;
}


void comandoBad(char comando[], Bloco disco[]){
	int numBloco = pegaNumero(comando);
	if(numBloco == -1)
		printf("-bash: bad: invalid argument\n");
	else if(numBloco <= qtdePilhas)
		printf("-bash: bad: invalid value\n");
	else{
		disco[numBloco].tipo = 'b';
		printf("The 'bad' command with argument '%d' has corrupted the block.\n", numBloco);
	}
}
