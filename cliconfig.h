// biblioteca de configuracoes da cli do inode

// primeiro argumento digitado na cli retorna um código referente a funcao que deve ser chamada
int codigoPrimeiroComando(char command[100]) {
	// casos possiveis de comando
	if(stricmp("chmod", command) == 0) 
		return 0;	
	else if(stricmp("vi", command) == 0) 
		return 1;
	else if(stricmp("ls", command) == 0) 
		return 2;
	else if(stricmp("mkdir", command) == 0) 
		return 3;
	else if(stricmp("rmdir", command) == 0) 
		return 4;
	else if(stricmp("rm", command) == 0) 
		return 5;	
	else if(stricmp("cd", command) == 0) 
		return 6;	
	else if(stricmp("link", command) == 0) 
		return 7;	
	else if(stricmp("unlink", command) == 0) 
		return 8;
	else if(stricmp("bad", command) == 0) 
		return 9;
	else if(stricmp("touch", command) == 0) 
		return 10;
	else if(stricmp("df", command) == 0)
		return 11;
	else
		return - 1;
}

// funcao de teste
int testeCodigoPrimeiroComando(char primeiroComando[]) {
	int teste = codigoPrimeiroComando(primeiroComando);
	printf("Codigo do primeiro comando: %d\n", teste);
}
