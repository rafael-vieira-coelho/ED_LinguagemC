typedef struct grafo Grafo;

Grafo *cria_grafo(int nro_vert, int Gmax, int eh_ponderado);
void libera_grafo(Grafo *gr);
int insere_aresta(Grafo *gr, int orig, int dest, int digrafo, float peso);
int remove_aresta(Grafo *gr, int orig, int dest, int digrafo);