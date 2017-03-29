#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
}typedef Lista;


void inserir(Lista**,int);
void exibir(Lista*);
Lista* inverteLista(Lista *l);
int main(){
	Lista *l = NULL;
	int i;
	for(i=0;i<5;i++){
		inserir(&l,rand()%15);
	}
	exibir(l);
	printf("\n");
	l = inverteLista(l);
	exibir(l);
}

void inserir(Lista **pp, int info){
	if(*(pp) == NULL){
		*(pp) = (Lista*)malloc(sizeof(Lista));
		(*pp)->info = info;
		(*pp)->prox = NULL;
	}else{
		Lista *aux2 = *pp;
		while(1){
			if(aux2->prox == NULL){
				aux2->prox = (Lista*)malloc(sizeof(Lista));
				aux2->prox->info = info;
				aux2->prox->prox = NULL;
				break;
			}
			aux2 = aux2->prox;
		}
	}
}

void exibir(Lista* l){
	if(l==NULL) return;
	while(1){
		printf("%d\t",l->info);
		l = l->prox;
		if(l == NULL) break;
	}
}
Lista* inverteLista(Lista *l){
	if(l->prox == NULL)
		return l;
	else{
		Lista* aux = inverteLista(l->prox);
		
		//procura o ultimo elemento da lista
		Lista* aux1 = aux;
		while(aux1->prox != NULL){
			aux1 = aux1->prox;
		}
		l->prox = NULL;
		aux1->prox = l;
		return aux;
	}
}
