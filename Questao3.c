#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *Funcao_num_primos(void *args){

	
	int valor;
	
	valor = *(int *)args; 
	printf("Executando Thread \n");
	int resto, count,i,j,n;
	int limit = valor + 1000;
    
    if(limit <= 99999){    
		for(i = valor ; i < limit  ; i++){
			count = 0;
			for(j = 1; j <= i ;j++){
				resto = i%j;
				if(resto == 0)
					count++;	
			}
		if(count == 2)
			printf("%d is primo\n",i); 
		}
	}

	printf("Thread Finalizada\n");
}

int main (){
	
	int resto, count,i,j, contador = 0, c;
	int valor;
	pthread_t threads;
	
	printf("Imprimindo numeros primos entre 0 e 99999\n");
    for(i = 1 ; i <= 99999 ; i++){
		count = 0;
		for(j = 1; j <= i ;j++){
			resto = i%j;
			if(resto == 0)
              count++;
	}
	
		if(count == 2)
			printf("%d is primo\n",i); 
		
		contador++;
		if(contador == 1000){
			valor = i;
			if(valor < 10000){
				c = pthread_create(&threads, NULL,Funcao_num_primos,&valor);
				if (c){
					printf("ERRO = %d\n", c);
					exit(-1);
				}
			}
			i = i + 1000;
			contador = 0;
		}
   }
   pthread_join(threads,NULL);
   
	return 0;   

}

