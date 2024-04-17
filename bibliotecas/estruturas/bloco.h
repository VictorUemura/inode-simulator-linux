struct Bloco {
	char tipo;
	struct Diretorio diretorio;
	struct Inode inode;
	struct Link link;
	struct Pilha pilha;
	struct Indr indireto;
};
