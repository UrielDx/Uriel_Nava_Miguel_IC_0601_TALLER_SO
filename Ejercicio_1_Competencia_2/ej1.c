#include <stdio.h>
#include <stdlib.h>

int main(){

	int x, *p;				//paso 1
	int y, *puntero;		//paso 2
	
	printf("\nPrograma 1\n\n");

	x = 10;					//paso 3
	p = &x;					//paso 4
	printf("El contenido del puntero p es: %i\n", p);						//paso 5
	p = p+1;																//paso 6
	printf("Sumando 1, ahora el contenido del puntero p es: %i\n", p);		//paso 7
	p = p+2;																//paso 8
	printf("Sumando 2, ahora el contenido del puntero p es: %i\n", p);		//paso 9
	
	y=20;																	//paso 10
	puntero = &y;															//paso 11
	printf("El contenido del puntero llamado puntero es: %i\n", puntero);	//paso 12
	
	
	printf("\n-----------------------------------------------------------------\n");
	
	printf("\nPrograma 2\n\n");
	
	int arrayInt[5];					//paso 1
	
	//paso 2
	for(int i=0; i<5; i++){				
		arrayInt[i] = i;
	}

	int *punteroInt = &arrayInt[0];		//paso 3
	int *punteroIntDos = &arrayInt[0];	//paso 4

	printf("El contenido del primer elemento del array es: %i\n", arrayInt[0]);					//paso 5
	printf("El contenido del primer elemento de punteroInt es: %i\n", punteroInt);				//paso 6
	printf("El contenido del primer elemento de punteroIntDos es: %i\n", punteroIntDos);		//paso 7
	printf("El contenido del quinto elemento del array es: %i\n", arrayInt[4]);					//paso 8
	printf("El contenido del quinto elemento de punteroInt es: %i\n", punteroInt+2);			//paso 9
	printf("El contenido del quinto elemento de punteroIntDos es: %i\n", punteroIntDos+2);		//paso 10
	
	//paso 11
	for(int a=0; a<5; a++){
		punteroInt++;
		printf("El punteroInt se encuentra en la posicion %i con el valor %i\n", a, punteroInt);
	}

	//paso 12
	for(int b=0; b<5; b++){
		punteroIntDos++;
		printf("El punteroIntDos se encuentra en la posicion %i con el valor %i\n", b, punteroIntDos);
	}
	
	return 0;
}