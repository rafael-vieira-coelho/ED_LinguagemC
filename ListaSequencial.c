#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista {
	int qtd;
	Aluno dados[MAX];
};

Lista *cria_lista(){
	Lista *li = (Lista *) malloc(sizeof(Lista));

	if (li != NULL) {
		li->qtd = 0;
	}
	return li;
}

void libera_lista(Lista *li){
	free(li);
}

int busca_lista_pos(Lista *li, int pos, Aluno *al){
	if (li == NULL
		|| pos <= 0
		|| pos > li->qtd) {
		return 0;
	}
	*al = li->dados[pos - 1];
	return 1;
}

int busca_lista_mat(Lista *li, int mat, Aluno *al){
	if (li == NULL) {
		return 0;
	}
	int i = 0;

	while (i < li->qtd 
		&& li->dados[i].matricula != mat) {
		i++;
	}
	if (i == li->qtd) {
		return 0;
	}
	*al = li->dados[i];
	return 1;
}

int insere_lista_final(Lista *li, Aluno al){
	if (li == NULL 
		|| lista_cheia(li)) {
		return 0;
	}
	li->dados[li->qtd] = al;
	li->qtd++;
	return 1;
}

int insere_lista_inicio(Lista *li, Aluno al){
	if (li == NULL
		|| lista_cheia(li)) {
		return 0;
	}
	int i;

	for (i = li->qtd - 1; i >= 0; i--) {
		li->dados[i+1] = li->dados[i];
	}
	li->dados[0] = al;
	li->qtd++;
	return 1;
}

int insere_lista_ordenada(Lista *li, Aluno al){
	if (li == NULL
		|| lista_cheia(li)) {
		return 0;
	}
	int k, i = 0;

	while (i < li->qtd 
		&& li->dados[i].matricula < al.matricula) {
		i++;
	}
	for (k = li->qtd - 1; k >= i; k--) {
		li->dados[k+1] = li->dados[k];
	}
	li->dados[i] = al;
	li->qtd++;
	return 1;
}

int remove_lista(Lista *li, int mat){
	if (li == NULL
		|| lista_vazia(li)) {
		return 0;
	}
	int k, i = 0;

	while (i < li->qtd 
		&& li->dados[i].matricula != mat) {
		i++;
	}
	if (i == li->qtd) {
		return 0;
	}
	for (k = i; k < li->qtd - 1; k++) {
		li->dados[k] = li->dados[k + 1];
	}
	li->qtd--;
	return 1;
}

int remove_lista_inicio(Lista *li){
	if (lista_vazia(li)) {
		return 0;
	}
	int k = 0;

	for (k = 0; k < li->qtd - 1; k++) {
		li->dados[k] = li->dados[k + 1];
	}
	li->qtd--;
	return 1;
}

int remove_lista_final(Lista *li){
	if (li == NULL 
		|| lista_vazia(li)) {
		return 0;
	}
	li->qtd--;
	return 1;
}

int tamanho_lista(Lista *li){
	if (li == NULL) {
		return -1;
	}
	return li->qtd;
}

int lista_cheia(Lista *li){
	if (li == NULL) {
		return -1;
	}
	return (li->qtd == MAX);
}

int lista_vazia(Lista *li){
	if (li == NULL) {
		return -1;
	}
	return (li->qtd == 0);
}

void mostra_lista(Lista *li) {
	if (lista_vazia(li)) {
		printf("\nI ->||");
	} else {
		printf("\nI -> ");
		int i = 0;

		while (i < tamanho_lista(li)) {
			printf("|%s,%d| -> ", li->dados[i].nome, li->dados[i].matricula);
			i++;
		}
		printf("||");
	}
}

int main(int argc, char **argv) {
	Lista *lista = cria_lista();
	Aluno aluno;

	aluno.matricula = 569;
	aluno.nome = "Jorge";
	aluno.n1 = 10;
	aluno.n2 = 8;
	aluno.n3 = 6;
	insere_lista_inicio(lista, aluno);
	mostra_lista(lista);
	aluno.matricula = 123;
	aluno.nome = "Maria";
	aluno.n1 = 7;
	aluno.n2 = 10;
	aluno.n3 = 9;
	insere_lista_final(lista, aluno);
	mostra_lista(lista);
	aluno.matricula = 215;
	aluno.nome = "Joe";
	aluno.n1 = 8;
	aluno.n2 = 8;
	aluno.n3 = 9;
	insere_lista_ordenada(lista, aluno);
	mostra_lista(lista);
	remove_lista_final(lista);
	mostra_lista(lista);
	remove_lista_inicio(lista);
	mostra_lista(lista);
	remove_lista(lista, 569);
	mostra_lista(lista);
	return 0;
}