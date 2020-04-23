#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"

struct pilha {
	int qtd;
	Aluno dados[MAX];
};

Pilha *cria_pilha() {
	Pilha *pi;

	pi = (Pilha *) malloc(sizeof(Pilha));
	if (pi != NULL) {
		pi->qtd = 0;
	}
	return pi;
}

void libera_pilha(Pilha *pi) {
	free(pi);
}

int tamanho_pilha(Pilha *pi) {
	if (pi == NULL) {
		return -1;
	}
	return pi->qtd;
}

int pilha_cheia(Pilha *pi) {
	if (pi == NULL) {
		return -1;
	}
	return (pi->qtd == MAX);
}

int pilha_vazia(Pilha *pi) {
if (pi == NULL) {
		return -1;
	}
	return (pi->qtd == 0);
}

int insere_pilha(Pilha *pi, Aluno al) {
	if (pi == NULL 
		|| pilha_cheia(pi)) {
		return 0;
	}
	pi->dados[pi->qtd] = al;
	pi->qtd++;
	return 1;
}

int remove_Pilha(Pilha *pi) {
	if (pq == NULL
		|| pi->qtd == 0) {
		return 0;
	}
	pi->qtd--;
	return 1;
}

int acessa_topo_pilha(Pilha *pi, Aluno *al) {
	if (pq == NULL
		|| pi->qtd == 0) {
		return 0;
	}
	*al = pi->dados[pi->qtd - 1];
	return 1;	
}
