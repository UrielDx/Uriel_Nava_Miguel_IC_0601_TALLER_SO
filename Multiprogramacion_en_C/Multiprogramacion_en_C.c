#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Definicion de la cantidad de procesos (hilos) a simular
//#define numProcesos 10

//Funcion que realiza la ejecucion/finalizacion de procesos
void *ejecucion(void *hilo){
   int h = (long)hilo;
   
   printf("Se ejecuta y finaliza el proceso %ld \n", h);   
   pthread_exit(NULL);	
}

//Aqui se indica la creacion de los procesos
int main(int argc, char *argv[]){
	int numProcesos;
	printf("\nIndique la cantidad de procesos a simular: ");
	scanf("%d", &numProcesos);
	printf("\n");
	
	pthread_t procesos[numProcesos];
   	int init, i;
   	
   	for(i = 0; i < numProcesos; i++){
	   printf("Llegada del proceso %ld \n", i);
	   init = pthread_create(&procesos[i], NULL, ejecucion, (void *)i);
   }
   pthread_exit(NULL);	   
}

