struct Inode{
    char permissoes[11];
    char data[11];
    char hora[6];
    int tamanho;
    char nome[50];
    int contador = 0;
    int direto[5] = {-1,-1,-1,-1,-1};
    int indireto = -1;
    int dobroIndireto = -1;
    int triploIndireto = -1;
};

Inode criaModeloInode(char name[50], char tipo, char permissoes[11]) {
	struct Inode inode;
	
	inode.tipo = tipo;
	strcpy(inode.permissoes, permissoes);
	strcpy(inode.nome, name);
	
	time_t tempoAtual = time(NULL);
	struct tm *dataHoraLocal = localtime(&tempoAtual);
	strftime(inode.data, sizeof(inode.data), "%d/%m/%Y", dataHoraLocal);
	strftime(inode.hora, sizeof(inode.hora), "%H:%M", dataHoraLocal);
	inode.tamanho = 0;
	inode.contador = 0;
	
	return inode;
}
