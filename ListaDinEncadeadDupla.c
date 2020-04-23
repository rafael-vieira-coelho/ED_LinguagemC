#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

typedef struct elemento {
	Aluno dados;
	struct elemento * ant;
	struct elemento * prox;
}Elem;

Lista *cria_lista(){
	Lista *li = (Lista *) malloc(sizeof(Lista));

	if (li != NULL) {
		*li = NULL;
	}
	return li;
}

void libera_lista(Lista *li){
	if (!lista_vazia(li)) {
		Elem *no;

		while ((*li) != NULL) {
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int tamanho_lista(Lista *li) {
	if (li == NULL) {
		return 0;
	}
	int cont = 0;
	Elem *no = *li;

	while (no != NULL) {
		cont++;
		no = no->prox;
	}
	return cont;
}
 
int busca_lista_pos(Lista *li, int pos, Aluno *al){
	if (li == NULL
		|| pos <= 0) {
		return 0;
	}
	Elem *no = *li;
	int i = 1;

	while (no != NULL 
		&& i < pos) {
		no = no->prox;
		i++;
	}
	if (no == NULL) {
		return 0;
	} else {
		*al = no->dados;
		return 1;
	}
}

int busca_lista_mat(Lista *li, int mat, Aluno *al){
	if (li == NULL) {
		return 0;
	}
	Elem *no = *li;

	while (no != NULL 
		&& no->dados.matricula != mat) {
		no = no->prox;
	}
	if (no == NULL) {
		return 0;
	}
	*al = no->dados;
	return 1;
}

int insere_lista_final(Lista *li, Aluno al){
	if (li == NULL) {
		return 0;
	}
	Elem *no;

	no = (Elem *) malloc(sizeof(Elem));
	if (no == NULL) {
		return 0;
	}
	no->dados = al;
	no->prox = NULL;
	if (lista_vazia(li)) { //insere no inicio
		no->ant = NULL; ////////////
		(*li) = no;
	} else {
		Elem *aux = *li;

		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = no;
		no->ant = aux; ///////////
	}
	return 1;
}

int insere_lista_inicio(Lista *li, Aluno al){
	if (li == NULL) {
		return 0;
	}
	Elem *no;

	no = (Elem *) malloc(sizeof(Elem));
	if (no == NULL) {
		return 0;
	}
	no->dados = al;
	no->prox = (*li);
	no->ant = NULL; /////////////
	if (*li != NULL) { //////////
		(*li)->ant = no; ////////
	} ///////////////////////////
	*li = no;
	return 1;
}

int insere_lista_ordenada(Lista *li, Aluno al){
	if (li == NULL) {
		return 0;
	}
	Elem *no = (Elem *) malloc (sizeof(Elem));

	if (no == NULL) {
		return 0;
	}
	no->dados = al;
	if (lista_vazia(li)) {//insere no inicio
		no->ant = NULL; ////////////////////
		(*li)->ant = no; ///////////////////
		no->prox = (*li); //////////////////
		*li = no;
		return 1;
	} else {
		Elem *ant, *atual = *li;

		while (atual != NULL
			&& atual->dados.matricula < al.matricula) {
			ant = atual;
			atual = atual->prox;
		}
		if (atual == *li) { //insere no inicio
			(*li)->ant = no; //////////////
			no->prox = (*li);
			*li = no;
		} else { //insere depois de 
			no->prox=ant->prox; /////////
			no->ant = ant; ////////////
			ant->prox = no;
		}
	}
	return 1;
}

int remove_lista(Lista *li, int mat){
	if (li == NULL 
		|| lista_vazia(li)) {
		return 0;
	}
	Elem *atual = *li;

	while (atual != NULL
		&& atual->dados.matricula != mat) {
		atual = atual->prox;
	}
	if (atual == NULL) { //nao encontrado
		return 0;
	}
	if (atual->ant == NULL) { //remove o primeiro
		*li = atual->prox;
	} else {
		atual->prox->ant = atual->prox;
	}
	free(atual);
	return 1;
}

int remove_lista_inicio(Lista *li){
	if (li == NULL) {
		return 0;
	}
	if (lista_vazia(li)) {
		return 0;
	}
	Elem *no = *li;

	*li = no->prox;
	if (no->prox != NULL) {  ///////////
		no->prox->ant = NULL; ///////////
	} ///////////////////////////////////
	free(no);
	return 1;
}

int remove_lista_final(Lista *li){
	if (li == NULL 
		|| lista_vazia(li)) {
			return 0;
	}
	Elem *ant, *no = *li;

	while (no->prox != NULL) {
		no = no->prox;
	}
	if (no->ant == NULL) { //remove o primeiro elemento
		*li = no->prox;
	} else {
		no->ant->prox = NULL;
	}
	free(no);
	return 1;
}

int lista_vazia(Lista *li){
	if ((*li) == NULL) {
		return 1;
	}
	return (*li == NULL);
}

void mostra_lista(Lista *li) {
	if (lista_vazia(li)) {
		printf("\nI ->||");
	} else {
		printf("\nI -> ");
		Elem *no = *li;
		
		while (no != NULL) {
			printf("|%s,%d| -> ", no->dados.nome, no->dados.matricula);
			no = no->prox;
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