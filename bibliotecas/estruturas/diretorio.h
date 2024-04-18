struct Diretorio {
	struct Entrada entradas[10];
};

void initDiretorio(Diretorio &diretorio) {
	for(int i = 0; i < 10; i++) 
		diretorio.entradas[i].inodeEndereco = -1;
}
