#define MAX 100

typedef struct aluno {
	int matricula;
	char *nome;
	float n1, n2, n3;
}Aluno;

typedef struct pilha Pilha;

Pilha *cria_pilha();
void libera_pilha(Pilha *pi);
int acessa_topo_pilha(Pilha *pi, Aluno *al);
int insere_pilha(Pilha *pi, Aluno al);
int remove_Pilha(Pilha *pi);
int tamanho_pilha(Pilha *pi);
int pilha_vazia(Pilha *pi);
int pilha_cheia(Pilha *pi);