#include "diretorio.h"
#include "inode.h"
#include "link.h"
#include "pilha.h"

struct Indr {
	int endereco[5];
};

struct Bloco {
	char tipo;
	struct Diretorio diretorio;
	struct Inode inode;
	struct Link link;
	struct Pilha pilha;
	struct Indr indireto;
};
