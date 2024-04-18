struct Bloco {
	char tipo;
	struct Diretorio diretorio;
	struct Inode inode;
	struct Link link;
	struct Pilha pilha;
	struct Indr indireto;
};

Bloco initBlocoDiretorio() {
	Bloco novo;
	novo.tipo = 'D';
	initDiretorio(novo.diretorio);
	return novo;
}

Bloco initBlocoInode() {
	Bloco novo;
	novo.tipo = 'N';
}
