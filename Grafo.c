#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo {
	int eh_ponderado;
	int nro_vert;
	int Gmax;
	int **arestas;
	float **pesos;
	int *grau;
};

Grafo *cria_grafo(int nro_vert, int Gmax, int eh_ponderado) {
	Grafo *gr = (Grafo *)malloc(sizeof(struct grafo));

	if (gr != NULL) {
		int i;

		gr->nro_vert = nro_vert;
		gr->Gmax = Gmax;
		gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
		gr->grau = (int *) calloc (nro_vert, sizeof(int));

		gr->arestas = (int **)malloc(nro_vert * sizeof(int *));
		for (i = 0; i < nro_vert; i++) {
			gr->arestas[i] = (int *) malloc (Gmax * sizeof(int));
		}
		if (gr->eh_ponderado) {
			gr->pesos = (float **) malloc (nro_vert * sizeof(float));
			for (i = 0; i < nro_vert; i++) {
				gr->pesos[i] = (float *) malloc (Gmax * sizeof(float));
			}
		}
	}
	return gr;
	Grafo *gr = (Grafo *) malloc (sizeof(struct grafo));

	if (gr != NULL) {
		int i;

		gr->nro_vert = nro_vert;
		gr->Gmax = Gmax;
		gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
		gr->grau = (int *) calloc (nro_vert, sizeof(int));
		for (i = 0; i < nro_vert; i++) {
			gr->arestas[i] = (int *) malloc(Gmax * sizeof(int));
		}
		if (gr->eh_ponderado) {
			gr->pesos = (float **) malloc (nro_vert * sizeof(float *));
			for (i = 0; i < nro_vert; i++) {
				gr->pesos[i] = (float *) malloc(Gmax * sizeof(float));
			}
		}
	}
	return gr;
}

void libera_grafo(Grafo *gr) {
	if (gr != NULL) {
		int i;

		for (i = 0; i < gr->nro_vert; i++) {
			free(gr->arestas[i]);
		}
		free(gr->arestas);
		if (gr->eh_ponderado) {
			for (i = 0; i < gr->nro_vert; i++) {
				free(gr->pesos[i]);
			}
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);
	}
}

int insere_aresta(Grafo *gr, int orig, int dest, int digrafo, float peso) {
	if ((gr == NULL)
		|| (orig < 0 || orig >= gr->nro_vert) 
		|| (dest < 0 || dest >= gr->nro_vert))
		return 0;

	gr->arestas[orig][gr->grau[orig]] = dest;
	if (gr->eh_ponderado) 
		gr->pesos[orig][gr->grau[orig]] = peso;

	gr->grau[orig]++;
	if (digrafo == 0)
		insere_aresta(gr, dest, orig, 1, peso);

	return 1;
}

int remove_aresta(Grafo *gr, int orig, int dest, int digrafo) {
	if ((gr == NULL)
		|| (orig < 0 || orig >= gr->nro_vert) 
		|| (dest < 0 || dest >= gr->nro_vert))
		return 0;

	int i = 0;

	while (i < gr->grau[orig] 
		&& gr->arestas[orig][i] != dest) {
		i++;
	}
	if (i == gr->grau[orig]) //elemento não encontrado
		return 0;

	gr->grau[orig]--;
	gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
	if (digrafo == 0)
		remove_aresta(gr, dest, orig, 1);

	return 1;
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont) {
	int i;

	visitado[ini] = cont;
	for (i = 0; i < gr->grau[ini]; i++) {
		if (!visitado[gr->arestas[ini][i]]) {
			buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1);
		}
	}
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado) {
	int i, cont = 1;

	for (i = 0; i < gr->nro_vert; i++) {
		visitado[i] = 0;
	}
	buscaProfundidade(gr, ini, visitado, cont);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado) {
	int i, vert, NV, cont = 1;
	int *fila, IF = 0, FF = 0;

	for (i = 0; i < gr->nro_vert; i++) {
		visitado[i] = 0;
	}
	NV = gr->nro_vert;
	fila = (int *) malloc (NV * sizeof(int));
	FF++;
	fila[FF] = ini;
	visitado[ini] = cont;
	while (IF != FF) {
		IF = (IF + 1) % NV;
		vert = fila[IF];
		cont++;
		for (i = 0; i < gr->grau[vert]; i++) {
			if (!visitado[gr->arestas[vert][i]]) {
				FF = (FF + 1) % NV;
				fila[FF] = gr->arestas[vert][i];
				visitado[gr->arestas[vert][i]] = cont;
			}
		}
	}
	free(fila);
}

int procuraMenorDistancia(float *dist, int *visitado, int NV) {
	int i, menor = -1, primeiro = 1;

	for (i = 0; i < NV; i++) {
		if (dist[i] >= 0
			&& visitado[i] == 0) {
			if (primeiro) {
				menor = i;
				primeiro = 0;
			} else {
				if (dist[menor] > dist[i]) {
					menor = i;
				}
			}
		}
	}
	return menor;
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist) {
	int i, cont, NV, ind, *visitado, vert;

	cont = NV = gr->nro_vert;
	visitado = (int *) malloc (NV * sizeof(int));
	for (i = 0; i < NV; i++) {
		ant[i] = -1;
		dist[i] = -1;
		visitado[i] = 0;
	}
	dist[ini] = 0;
	while (cont > 0) {
		vert = procuraMenorDistancia(dist, visitado, NV);

		if (vert == -1)
			break;

		visitado[vert] = 1;
		cont--;
		for (i = 0; i < gr->arestas[vert]; i++) {
			ind = gr->arestas[vert][i];
			if (dist[ind] < 0) {
				dist[ind] = dist[vert] + 1;
				ant[ind] = vert;
			} else {
				if (dist[ind] > dist[vert] + 1) {
					dist[ind] = dist[vert] + 1;
					ant[ind] = vert;
				}
			}
		}
	}
	free(visitado);
}
