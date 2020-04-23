#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

struct elemento {
	Aluno dados;
	struct elemento *prox;
};

struct fila {
	Elem *inicio;
	Elem *fim;
	int qtd;
};

Fila *cria_fila() {
	Fila *fi = (Fila*) malloc(sizeof(Fila));

	if (fi != NULL) {
		fi->fim = NULL;
		fi->inicio = NULL;
		fi->qtd = 0;
	}
	return fi;
}

void libera_fila(Fila *fi) {
	if (fi != NULL) {
		Elem *no;

		while (fi->inicio != NULL) {
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

int mostra_fila(Fila *fi){
	if (fila_vazia(fi)) {
		printf("\nI ->||");
	} else {
		printf("\nI -> ");
		Elem *no = fi->inicio;

		while (fi != NULL 
			&& no != fi->fim) {
			no = no->prox;
			printf("|%s,%d| -> ", no->dados.nome, no->dados.matricula);
		}
		printf("||\n");
	}
	return 0;
}

int tamanho_fila(Fila *fi) {
	if (fi == NULL) {
		return 0;
	}
	return fi->qtd;
}

int fila_vazia(Fila *fi) {
	if (fi == NULL) {
		return -1;
	}
	return (fi->inicio == NULL);
}

int insere_fila(Fila *fi, Aluno al) {
	if (fi == NULL) {
		fi = cria_fila();
	}
	Elem *no = (Elem *) malloc(sizeof(Elem));

	if (no == NULL) {
		return 0;
	}
	no->dados = al;
	no->prox = NULL;
	if (fi->fim == NULL) { //fila vazia
		fi->inicio = no;
	} else {
		fi->fim->prox = no;
	}
	fi->fim = no;
	fi->qtd++;
	return 1;
}

int remove_fila(Fila *fi) {
	if (fila_vazia(fi)) {
		return 0;
	}
	Elem *no = fi->inicio;

	fi->inicio = fi->inicio->prox;
	free(no);
	if (fi->inicio == NULL) { //fila ficou vazia
		fi->fim = NULL;
	}
	fi->qtd--;
	return 1;
}

int main(int argc, char **argv) {
	Fila *fila;
	Aluno aluno;

	fila = cria_fila();
	mostra_fila(fila);
	aluno.matricula = 569;
	aluno.nome = "Jorge";
	aluno.n1 = 10;
	aluno.n2 = 8;
	aluno.n3 = 6;
	insere_fila(fila, aluno);
	mostra_fila(fila);
	aluno.matricula = 123;
	aluno.nome = "Maria";
	aluno.n1 = 7;
	aluno.n2 = 10;
	aluno.n3 = 9;
	insere_fila(fila, aluno);
	mostra_fila(fila);
	aluno.matricula = 215;
	aluno.nome = "Joe";
	aluno.n1 = 8;
	aluno.n2 = 8;
	aluno.n3 = 9;
	insere_fila(fila, aluno);
	mostra_fila(fila);
	remove_fila(fila);
	mostra_fila(fila);
	remove_fila(fila);
	mostra_fila(fila);
	remove_fila(fila);
	mostra_fila(fila);
	return 0;
}