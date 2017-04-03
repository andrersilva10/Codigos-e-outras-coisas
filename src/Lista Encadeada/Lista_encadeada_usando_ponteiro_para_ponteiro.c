#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
}typedef Lista;

int tamanhoLista(Lista*);
void inserir(Lista**,int);
void exibir(Lista*);
Lista* inverteLista(Lista *l);
void excluirElemento(Lista**,int posicao);
int main(){
	Lista *l = NULL;
	int i;
	for(i=0;i<5;i++){
		inserir(&l,rand()%15);
	}
	exibir(l);
	printf("\n");
	//l = inverteLista(l);
	scanf("%d",&i);
	excluirElemento(&l,i);
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

void excluirElemento(Lista** l,int posicao){
	if(*(l)!=NULL){
		Lista *aux;
		int i = 0;
		if(posicao==0){
			aux = (*l)->prox;
			free((*l));
			*l = aux;
			
		}else if(posicao < (tamanhoLista((*l)) - 1)){
			aux = *l;
			while(i<posicao-1){
				aux = aux->prox;
				i++;
			}
			Lista *aux2 = aux->prox;
			aux->prox = aux->prox->prox;
			free(aux2);
		}else{
			aux = (*l);
			Lista *aux2 = aux;
			while(aux->prox->prox != NULL){
				aux = aux->prox;
				aux2 = aux2->prox;
			}
			aux2 = aux2->prox;
			free(aux2);
			aux->prox = NULL;
		}
	}
}


int tamanhoLista(Lista* l){
	int i = 0;
	Lista* aux = l;
	if(aux == NULL){
		return 0;
	}
	while(aux->prox != NULL){
		aux = aux->prox;
		i++;
	}
	return i;
}
