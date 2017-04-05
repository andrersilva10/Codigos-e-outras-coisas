#include <stdio.h>
#include <stdlib.h>

struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}typedef Lista2;


void inserirFinal(Lista2**,int);
void exibir(Lista2*);
int main(){
	
	Lista2 *l = NULL;
	inserirFinal(&l,2);
	inserirFinal(&l,2);
	inserirFinal(&l,5);
	inserirFinal(&l,2);
	inserirFinal(&l,2);
	exibir(l);
	return 0;
}

void inserirFinal(Lista2** l, int v){
	Lista2* n = (Lista2*)malloc(sizeof(Lista2));
	n->prox = NULL;
	n->info = v;
	if((*l)!=NULL){
		Lista2 *p = (*l);
		while(p->prox != NULL){
			p = p->prox;
		}
		p->prox = n;
		n->ant = p;
	}else{
		n->ant = NULL;
		(*l) = n;
	}


}
void exibir(Lista2 *l){
	Lista2 *aux = l;
	while(1){
		printf("%d\t",l->info);
		l = l->prox;
		if(l == NULL) break;
	}
}
