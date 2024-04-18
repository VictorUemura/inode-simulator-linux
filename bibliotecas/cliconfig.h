// biblioteca de configuracoes da cli do inode

// primeiro argumento digitado na cli retorna um código referente a funcao que deve ser chamada
int codigoPrimeiroComando(char comando[100]) {
	// casos possiveis de comando
	if(stricmp("chmod", comando) == 0) 
		return 0;	
	else if(stricmp("vi", comando) == 0) 
		return 1;
	else if(stricmp("ls", comando) == 0) 
		return 2;
	else if(stricmp("mkdir", comando) == 0)
		return 3;
	else if(stricmp("rmdir", comando) == 0) 
		return 4;
	else if(stricmp("rm", comando) == 0) 
		return 5;	
	else if(stricmp("cd", comando) == 0) 
		return 6;	
	else if(stricmp("link", comando) == 0) 
		return 7;	
	else if(stricmp("unlink", comando) == 0) 
		return 8;
	else if(stricmp("bad", comando) == 0) 
		return 9;
	else if(stricmp("touch", comando) == 0) 
		return 10;
	else if(stricmp("df", comando) == 0)
		return 11;
	else if(stricmp("cls", comando) == 0)
		return 12;
	else if(stricmp("exit", comando) == 0)
		return 13;
	return - 1;
}

// funcao de teste
int testeCodigoPrimeiroComando(char primeiroComando[]) {
	int teste = codigoPrimeiroComando(primeiroComando);
	printf("Codigo do primeiro comando: %d\n", teste);
}

// funcao de linha padrao do cli
void exibeLinhaComando(char caminho[]) {
	// texto de rota padrao sempre exibido
	textcolor(LIGHTGREEN); printf("root@root");
	textcolor(WHITE); printf(":");
	textcolor(LIGHTBLUE);printf("%s", caminho);
	
	textcolor(WHITE);printf("$ ");
}

void primeiroCodigo(char comando[], char comandoFlag[]) {
    int i = 0;
    while (isspace(comando[i])) {
        i++;
    }
    int j = 0;
    while (comando[i] != '\0' && !isspace(comando[i])) {
        comandoFlag[j++] = comando[i++];
    }
    comandoFlag[j] = '\0';
}

int leituraComando(char comando[], char comandoFlag[]) {
    fflush(stdin);
    int resultado = scanf("%99[^\n]", comando);

    if (resultado == 0) {
        return -2;
    } else {
        primeiroCodigo(comando, comandoFlag);
        return codigoPrimeiroComando(comandoFlag);
    }
}

void erroComando(char comandoFlag[]) {
	printf("-bash: %s: command not found\n", comandoFlag);
}

void menuComando(int codigoComando, char comando[], char comandoFlag[], Bloco disco[], char caminho[], int endRoot) {
	// menu de comandos
	switch(codigoComando) {
		// chmod
		case 0:
			break;
			
		// vi			
		case 1:
			break;
			
		// ls
		case 2:
			comandoLs(endRoot, disco, caminho);
			break;
			
		// mkdir
		case 3:
			comandoMkdir(disco, comando, caminho, endRoot);
			break;
			
		// rmdir
		case 4:
			break;
			
		// rm
		case 5:
			comandoRm(comando, disco, endRoot);
			break;
			
		// cd
		case 6:
			break;
			
		// link 
		case 7:
			break;
			
		// unlink
		case 8:
			break;
			
		// bad
		case 9:
			comandoBad(comando, disco);
			break;
			
		// touch
		case 10:
			break;
			
		// df
		case 11:
			break;
			
		// cls
		case 12:
			comandoCls();
			break;
		
		// exit
		case 13:
			comandoExit();
			break;
		
		// enter pressionado
		case -2:
			break;
		
		// caso de erro
		default:
			erroComando(comandoFlag);
			break;
	}
}
