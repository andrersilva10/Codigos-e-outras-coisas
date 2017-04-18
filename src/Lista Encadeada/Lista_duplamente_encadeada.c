#include <stdio.h>
#include <stdlib.h>

struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}typedef Lista2;


void inserirFinal(Lista2**,int);
void exibir(Lista2*);
Lista2* separa(Lista2*,int);
Lista2* concatena(Lista2*,Lista2*);
int main(){
	
	Lista2 *l = NULL;
	inserirFinal(&l,2);
	inserirFinal(&l,2);
	inserirFinal(&l,5);
	inserirFinal(&l,4);
	inserirFinal(&l,6);
	exibir(l);
	Lista2 *l2 = separa(l,5);
	l = concatena(l,l2);
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
	printf("\n");
}

Lista2* separa(Lista2 *l,int n){
	Lista2* aux = l;
	Lista2* retorno = NULL;
	if(aux != NULL){
		while(aux != NULL){
			if(aux->info == n){
				retorno = aux->prox;
				retorno->ant = NULL;
				aux->prox = NULL;
				break;
			}
			aux = aux->prox;
		}
	}
	return retorno;
}
Lista2* concatena(Lista2 *l1, Lista2* l2){
	Lista2* aux = l1;
	if(l1 == NULL && l2 != NULL){
		return l2;
	}else if(l2 == NULL && l1 != NULL){
		return l1;
	}else if(l1== NULL && l2==NULL){
		return NULL;
	}else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = l2;
		l2->ant = aux;
		return l1;
	}
}
