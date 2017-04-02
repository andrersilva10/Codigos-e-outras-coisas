#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lista{
	int info;
	struct lista *prox;
}typedef Lista;
Lista* inserirNoCirc(Lista* l, int n);
void inserirNoFinalCirc(Lista**,int n);
void imprimirListaCirc(Lista*);
void removerNoCirc(Lista**,int );
int tamanhoLista(Lista*);
int main(int argc, char *argv[]) {
	Lista* l = NULL;
	/*
	l = inserirNoCirc(l,1);
	l = inserirNoCirc(l,2);
	l = inserirNoCirc(l,3);
	l = inserirNoCirc(l,4);
	l = inserirNoCirc(l,5);
	l = inserirNoCirc(l,6);
	l = inserirNoCirc(l,7);
	l = inserirNoCirc(l,8);
	*/
	
	
	inserirNoFinalCirc(&l,1);
	inserirNoFinalCirc(&l,2);
	inserirNoFinalCirc(&l,3);
	inserirNoFinalCirc(&l,4);
	inserirNoFinalCirc(&l,5);
	removerNoCirc(&l,4);
	imprimirListaCirc(l);
	return 0;
}

Lista* inserirNoCirc(Lista *l, int n){
	Lista *aux;
	Lista *p = (Lista*)malloc(sizeof(Lista));
	p->info = n;
	aux = l;
	if(aux!=NULL){
		p->prox = l;
		while(aux->prox!=l){
			aux = aux->prox;
		}
		aux->prox = p;
	}else{
		p->prox = p;
	}
	return p;
	
	
}
void imprimirListaCirc(Lista* l){
	Lista *aux = l;
	if(aux!=NULL){
		do{
			printf("%d\t",aux->info);
			aux=aux->prox;
		}while(aux != l);
	}
}

void inserirNoFinalCirc(Lista** l,int n){
	Lista *p = (Lista*)malloc(sizeof(Lista));
	p->info = n;
	
	if((*l) != NULL){
		p->prox = (*l);
		Lista *aux = (*l);
		while(aux->prox != (*l)){
			aux = aux->prox;
		}
		aux->prox = p;
	}else{
		p->prox = p;
		(*l) = p;
	}
}
void removerNoCirc(Lista** l, int posicao){
	if((*l) != NULL){
		int i = 0;
		Lista* aux = (*l);
		Lista* aux2 = (*l);
		if(posicao == 0){

			while(aux->prox != (*l)){
				aux=aux->prox;
			}
			aux->prox = (*l)->prox;
			(*l) = (*l)->prox;
			free(aux2);
		}else if(posicao < (tamanhoLista((*l)) - 1)){
			while(i < posicao -1){
				aux = aux->prox;
				i++;
			}
			aux2 = aux->prox;
			printf("%d\n aaaaa",aux2->info);
			aux = aux->prox->prox;
			free(aux2);
		}
	}
}
int tamanhoLista(Lista* l){
	int i = 0;
	Lista* aux = l;
	if(aux == NULL){
		return 0;
	}
	while(aux->prox != l){
		aux = aux->prox;
		i++;
	}
	return i;
}

