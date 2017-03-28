
#include <stdio.h>
#include <stdlib.h>
#define T 15
/* run this program using the console pauser or add your own getch, system("pause") or input loop  */

struct pessoa{
	int idade;
	struct pessoa *proximo;
};
void criar(struct pessoa *p);
void insere(struct pessoa*,int);
void exibir(struct pessoa*);
int main(int argc, char *argv[]) {
	
		srand(time(NULL));
		struct pessoa *p = (struct pessoa*) malloc(sizeof(struct pessoa));
		p->proximo=NULL;
		p->idade = 13;
		int i = 0;
		for(i = 0;i<14;i++){
			insere(p,rand()%100);
		}
		exibir(p);
	
	printf("%c",7);
	return 0;
}

void insere(struct pessoa *p, int idade){
	struct pessoa *cont;
	for(cont=p;cont !=NULL;cont = cont->proximo){
		if(cont->proximo == NULL){
			cont->proximo = (struct pessoa*) malloc(sizeof(struct pessoa));
			cont->proximo->idade = idade;
			cont->proximo->proximo=NULL;
			break;
		}
	}
}
void exibir(struct pessoa *p){
	int i = 0;
	while(p != NULL){
		printf("Pessoa %d ---> Idade = %d\n",(i+1),p->idade);
		i++;
		p = p->proximo;
	}
	
}

