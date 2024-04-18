void comandoLs(int endRoot, Bloco disco[], char caminho[]) {
	for(int i = 0; i < 5; i++) {
		int endEntrada = disco[endRoot].inode.direto[i];
		if(endEntrada != -1) {
			for(int j = 0; j < 10; j++) {
				int endBlocoAtual = disco[endEntrada].diretorio.entradas[j].inodeEndereco;
				if(endBlocoAtual != -1) {
					printf("%s\n", disco[endEntrada].diretorio.entradas[j].nome);
				}
			}
		}
	}
}
