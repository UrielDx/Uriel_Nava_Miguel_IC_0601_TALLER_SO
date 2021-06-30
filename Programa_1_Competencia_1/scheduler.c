#include <stdio.h>
#include <stdlib.h>

//estructura para cada proceso
typedef struct{
	int ID, py, nT, t;
}Proceso;

int main(){
	int nP, i=0, j=0;
	
	printf("\n\t--------------------------------------------------------------");
	printf("\n\tIndique la cantidad de procesos: ");
	scanf("%i", &nP);
	printf("\t--------------------------------------------------------------");
	
	Proceso p[nP], tmp;

	//ciclo que declara los atributos para cada proceso 	
	for(int i=0; i<nP; i++){
		p[i].ID = i;
		p[i].py = rand()%3;
		p[i].nT = rand()%21+1;
		p[i].t = rand()%100;
	}
	
	//ciclo que ordena los procesos segun su tiempo de espera
	for (i=0 ; i<nP-1; i++){
	    for (j=0; j<nP-i-1; j++){
	      if (p[j].t < p[j+1].t){
	        tmp = p[j];
	        p[j] = p[j+1];
	        p[j+1] = tmp;
	      }
	    }
  	}

	//ciclo que verifica si existen tareas en cada proceso
	int cn;
	for(i=0; i<nP; i++){
		if(p[i].nT > 0){
			cn = 1;
		}
	}
	
	//ciclo while que se ejecuta siempre y cuando existan tareas en cada proceso
	while(cn == 1){
		cn = 0;
		
		//ciclo que imprime las tareas restantes de cada proceso
		for(i = 0; i < nP; i++){
			if (p[i].nT > 0){
				printf("\n\t--> El proceso con ID %i tiene %i tareas restantes por realizar", p[i].ID, p[i].nT);
			}
		}
		
		//ciclo que decrementa las tareas de cada proceso segun su prioridad
		for(i=0; i<nP; i++){
			if(p[i].py == 0){
				p[i].nT = p[i].nT - 8;
			}
			else if(p[i].py == 1){
				p[i].nT = p[i].nT - 4;
			}
			else{
				p[i].nT = p[i].nT - 2;
			}
		}
		
		//ciclo que evalua si aun existen tareas en cada proceso de acuerdo a su prioridad
		//si no restan tareas en el proceso, lo finaliza
		for(i=0; i<nP; i++){
			if(p[i].nT > 0){
				cn = 1;	
			}
			
			if(p[i].py == 0){
				if(p[i].nT <= 0 && p[i].nT >= -7){
					printf("\n\t--------------------------------------------------------------");
					printf("\n\t El proceso %i ha ralizado todas sus tareas", p[i].ID);
					printf("\n\t Proceso %i finalizado", p[i].ID);
					printf("\n\t--------------------------------------------------------------");
				}
			}
			else if(p[i].py == 1){
				if(p[i].nT <= 0 && p[i].nT >= -3){
					printf("\n\t--------------------------------------------------------------");
					printf("\n\t El proceso %i ha ralizado todas sus tareas", p[i].ID);
					printf("\n\t Proceso %i finalizado", p[i].ID);
					printf("\n\t--------------------------------------------------------------");
				}
			}
			else{
				if(p[i].nT <= 0 && p[i].nT >= -1){
					printf("\n\t--------------------------------------------------------------");
					printf("\n\t El proceso %i ha ralizado todas sus tareas", p[i].ID);
					printf("\n\t Proceso %i finalizado", p[i].ID);
					printf("\n\t--------------------------------------------------------------");
				}
			}
		}
	}
	printf("\n\t--------------------------------------------------------------");
	printf("\n\t ¡TODOS LOS PROCESOS HAN CONCLUIDO EXITOSAMENTE!\n");
	printf("\t--------------------------------------------------------------\n");
	
	return 0;
}
