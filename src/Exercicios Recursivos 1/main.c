#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maior(int);
int menor(int);
int entre5e8(int);
int contaPares(int);
int main(int argc, char *argv[]) {
	long long a = INT_MIN ;
	printf("%d",a);
	return 0;
}

int maior(int cont){
	if(cont>=8){
		return INT_MIN;
	}else{
		int num;
		scanf("%d",&num);
		int retorno = maior(cont+1);
		if(num > retorno){
			return num;
		}else{
			return retorno;
		}
	}
}
int menor(int cont){
	if(cont > 8){
		return INT_MAX;
	}else{
		int num, retorno;
		retorno = menor(cont+1);
		if(num < retorno){
			return num;
		}else{
			return retorno;
		}
	}
}
int entre5e8(int cont){
	if(cont>8){
		return 0;
	}else{
		int num, retorno;
		scanf("%d",&num);
		retorno = entre5e8(cont+1);
		int estaNoIntervalo = (num>=5 && num<=8) ? 1 : 0 ;
		return retorno + estaNoIntervalo;
	}
}
int contaPares(int cont){
	if(cont>8){
		return 0;
	}else{
		int num, retorno;
		scanf("%d",&num);
		retorno = contaPares(cont+1);
		int ehPar = (num % 2 == 0) ? 1 : 0;
		return retorno + ehPar;
	}
}
