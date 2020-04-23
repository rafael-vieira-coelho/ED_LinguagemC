typedef struct aluno {
	int matricula;
	char *nome;
	float n1, n2, n3;
} Aluno;

typedef struct elemento *Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int busca_lista_pos(Lista *li, int pos, Aluno *al);
int busca_lista_mat(Lista *li, int mat, Aluno *al);
int insere_lista_final(Lista *li, Aluno al);
int insere_lista_inicio(Lista *li, Aluno al);
int insere_lista_ordenada(Lista *li, Aluno al);
int remove_lista(Lista *li, int mat);
int remove_lista_inicio(Lista *li);
int remove_lista_final(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);

