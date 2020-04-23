#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO {
	int info;
	struct NO *esq;
	struct NO *dir;
};

ArvBin * cria() {
	ArvBin *raiz = (ArvBin *) malloc (sizeof(ArvBin));

	if (raiz != NULL) {
		*raiz = NULL;
	}
	return raiz;
}

void libera_no(struct NO *no) {
	if (no == NULL) {
		return;
	}
	libera_no(no->esq);
	libera_no(no->dir);
	free(no);
	no = NULL;
}

void libera(ArvBin *raiz) {
	if (raiz == NULL) {
		return;
	}
	libera_no(*raiz); //libera cada nó
	free(raiz); //libera raiz
}

int esta_vazia(ArvBin *raiz) {
	if (raiz == NULL 
		|| *raiz == NULL) {
		return 1;
	}
	return 0;
}

int total_no(ArvBin *raiz) {
	if (raiz == NULL 
		|| *raiz == NULL) {
		return 0;
	}
	int total_esq = total_no(&((*raiz)->esq));
	int total_dir = total_no(&((*raiz)->dir));

	return (total_esq + total_dir + 1);
}

int altura(ArvBin *raiz) {
	if (raiz == NULL 
		|| *raiz == NULL) {
		return 0;
	}
	int alt_esq = altura(&((*raiz)->esq));
	int alt_dir = altura(&((*raiz)->dir));

	if (alt_esq > alt_dir)
		return (alt_esq + 1);

	return (alt_dir + 1);
}

void pre_ordem(ArvBin *raiz) {
	if (raiz == NULL) 
		return;

	if (*raiz != NULL) {
		printf("%d\n", (*raiz)->info);
		pre_ordem(&((*raiz)->esq));
		pre_ordem(&((*raiz)->dir));
	}
}

void em_rodem(ArvBin *raiz) {
	if (raiz == NULL) 
		return;

	if (*raiz != NULL) {
		em_ordem(&((*raiz)->esq));
		printf("%d\n", (*raiz)->info);
		em_ordem(&((*raiz)->dir));
	}
}

void pos_rodem(ArvBin *raiz) {
	if (raiz == NULL) 
		return;

	if (*raiz != NULL) {
		pos_ordem(&((*raiz)->esq));
		pos_ordem(&((*raiz)->dir));
		printf("%d\n", (*raiz)->info);
	}
}
