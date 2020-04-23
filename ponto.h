typedef struct ponto Ponto;

Ponto *Ponto_cria(float x, float y);

void Ponto_libera(Ponto *p);

int Ponto_acessa(Ponto *p, float *x, float *y);

int Ponto_atribui(Ponto *p, float x, float y);

float Ponto_distancia(Ponto *p1, Ponto *p2);