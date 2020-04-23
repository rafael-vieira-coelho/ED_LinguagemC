typedef struct NO* ArvBin;

ArvBin *cria();
void libera(ArvBin *raiz);
int insere(ArvBin *raiz, int valor);
int remove(ArvBin *raiz, int valor);
int esta_vazia(ArvBin *raiz);
int altura(ArvBin *raiz);
int total_no(ArvBin *raiz);
int consulta(ArvBin *raiz, int valor);
void pre_ordem(ArvBin *raiz);
void em_ordem(ArvBin *raiz);
void pos_ordem(ArvBin *raiz);