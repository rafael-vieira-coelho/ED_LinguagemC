#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"


struct fila {
	int inicio, fim, qtd;
	Aluno dados[MAX];
};

void cria_fila(Fila *fi){
	fi->qtd = 0;
	fi->inicio = 0;
	fi->fim = 0;
}

int consulta_fila(Fila *fi, Aluno *al){
	int c = fi->inicio;

	while (c < fi->fim) {
		if (fi->dados[c].matricula == al.matricula) {
			*al = fi->dados[c];
			return 1;
		}
		c++;
	}
	return 0;
}

int mostra_fila(Fila *fi){
	if (fila_vazia(fi)) {
		printf("\nI ->||");
	} else {
		printf("\nI -> ");
		int c = fi->inicio;

		while (c < fi->fim) {
			printf("|%s,%d| -> ", fi->dados[c].nome, fi->dados[c].matricula);
			c++;
		}
		printf("||\n");
	}
	return 0;
}

int insere_fila(Fila *fi, Aluno al){
	if (!fila_cheia(fi)) {
		fi->dados[fi->fim] = al;
		fi->fim = (fi->fim + 1) % MAX;
		fi->qtd++;
		return 1;
	}
	return 0;
}

int remove_fila(Fila *fi){
	if (fila_vazia(fi)) {
		fi->inicio = (fi->inicio + 1) % MAX;
		fi->qtd--;
		return 0;
	}
	return 1;
}

int tamanho_fila(Fila *fi){
	return fi->qtd;
}

int fila_vazia(Fila *fi){
	return tamanho_fila(fi) == 0;
}

int fila_cheia(Fila *fi){
	return tamanho_fila(fi) == MAX;
}

int main(int argc, char **argv) {
	Fila fila;
	Aluno aluno;

	cria_fila(&fila);
	mostra_fila(&fila);
	aluno.matricula = 569;
	aluno.nome = "Jorge";
	aluno.n1 = 10;
	aluno.n2 = 8;
	aluno.n3 = 6;
	insere_fila(&fila, aluno);
	mostra_fila(&fila);
	aluno.matricula = 123;
	aluno.nome = "Maria";
	aluno.n1 = 7;
	aluno.n2 = 10;
	aluno.n3 = 9;
	insere_fila(&fila, aluno);
	mostra_fila(&fila);
	aluno.matricula = 215;
	aluno.nome = "Joe";
	aluno.n1 = 8;
	aluno.n2 = 8;
	aluno.n3 = 9;
	insere_fila(&fila, aluno);
	mostra_fila(&fila);
	remove_fila(&fila);
	mostra_fila(&fila);
	remove_fila(&fila);
	mostra_fila(&fila);
	remove_fila(&fila);
	mostra_fila(&fila);
	return 0;
}