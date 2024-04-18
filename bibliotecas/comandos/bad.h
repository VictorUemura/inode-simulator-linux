int pegaNumero(char input[]) {
    int numero;

    sscanf(input, "%*s %d", &numero);
    
    return numero;
}

void comandoBad(char comando[], Bloco disco[]){
	int numBloco = pegaNumero(comando);
	printf("Bloco: %d", numBloco);
}
