#include <stdio.h>
#include <stdlib.h>

struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}typedef Lista2;


Lista2* inserirFinal(Lista2*,int);
void exibir(Lista2*);
int main(){
	
	Lista2 *l = NULL;
	l = inserirFinal(l,1);
	printf("%d",l->info);
	l = inserirFinal(l,2);
	l = inserirFinal(l,3);
	l = inserirFinal(l,4);
	l = inserirFinal(l,5);
	exibir(l);
	return 0;
}

Lista2* inserirFinal(Lista2* l, int v){
	Lista2* n = (Lista2*)malloc(sizeof(Lista2));
	Lista2 *p = l;
	if(l!=NULL){
		while(p->prox != NULL)
			p = p->prox;
		p->prox = n;
	}
	n->ant = p;
	n->prox = NULL;
	n->info = v;
	if(l=NULL)
		return n;
	else
		return l;
}
void exibir(Lista2 *l){
	Lista2 *aux = l;
	while(aux != NULL){
		printf("%d\t",aux->info);
		aux = aux->prox;
	}
}
