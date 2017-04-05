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
	/*inserirNoFinalCirc(&l,2);
	inserirNoFinalCirc(&l,3);
	inserirNoFinalCirc(&l,4);
	inserirNoFinalCirc(&l,5);*/
	removerNoCirc(&l,0);
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
		Lista* aux2;
		if(posicao == 0 && tamanhoLista(aux)>1){//excluir primeiro elemento de uma lista cheia
			while(aux->prox != (*l)){
				aux=aux->prox;
			}
			aux->prox = (*l)->prox;
			(*l) = (*l)->prox;
			free(aux2);
		}else if(posicao == tamanhoLista(aux) - 1 && tamanhoLista(aux)>1){//excluir ultimo elemento de uma lista cheia
			while(aux->prox->prox!=(*l)){
				aux = aux->prox;
			}
			aux2 = aux->prox;
			aux->prox = (*l);
			free(aux2);
		}else if(posicao > 0 && tamanhoLista(aux) > 1){ //excluir elemento do 'meio' de uma lista cheia
			while(i < posicao - 1){
				aux = aux->prox;
				i++;
			}
			aux2 = aux->prox;
			aux->prox = aux2->prox;
			free(aux2);
		}else{//excluir elemento de uma lista com um elemento somente
			free((*l));
			(*l) = NULL;
		}
	}
}
int tamanhoLista(Lista* l){
	
	Lista* aux = l;
	if(aux == NULL){
		return 0;
	}
	int i = 0;
	do{
		aux = aux->prox;
		i++;
	}while(aux != l);
	return i;
}

