typedef struct aluno {
	int matricula;
	char *nome;
	float n1, n2, n3;
}Aluno;

typedef struct elemento Elem;

typedef struct fila Fila;

Fila *cria_fila();
int consulta_fila(Fila *fi, Aluno al);
int insere_fila(Fila *fi, Aluno al);
int remove_fila(Fila *fi);
int tamanho_fila(Fila *fi);
int fila_vazia(Fila *fi);
int fila_cheia(Fila *fi);