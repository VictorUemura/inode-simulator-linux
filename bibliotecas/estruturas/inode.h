struct Inode{
    char permissoes[11];
    char data[11];
    char hora[6];
    int tamanho;
    char nome[50];
    int contador;
    int direto[5] = {0,0,0,0,0};
    int indireto = 0;
    int dobroIndireto = 0;
    int triploIndireto = 0;
};

Inode criaInode(char name[50], int length, char permissions[10]) {
	struct Inode inode;
	
    return inode;	
}
