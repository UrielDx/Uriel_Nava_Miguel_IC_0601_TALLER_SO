#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_nombre 50

typedef struct{
	char *palabra;
}nodo;

nodo *nod;

int existe_archivo_e(char *txt_entrada);
int crear_archivo_e(char *txt_entrada);
void cerrar_archivo_e(FILE *ptrArchivo, char *txt_entrada);
int existe_archivo_s(char *txt_salida);
int crear_archivo_s(char *txt_salida);
void cerrar_archivo_s(FILE *ptrArchivo, char *txt_salida);
void leer_entrada(char *txt_entrada);
void escribir_salida(char *txt_salida, char *txt_entrada);

int main(int argc, char const *argv[]){

	char txt_entrada[tam_nombre];
	strcpy(txt_entrada, argv[1]);
	char txt_salida[tam_nombre];
	strcpy(txt_salida, argv[2]);
	int existe_arch_e = 0;
	int existe_arch_s = 0;
	
	do{
		existe_arch_e = existe_archivo_e(txt_entrada);
		if(!existe_arch_e){
		/*
		printf("----------------------------------------------\n");
		printf("\tEl archivo %s YA existe.\n", txt_entrada);
		printf("----------------------------------------------\n");
		}
		else{ */
		printf("----------------------------------------------\n");
		printf("\n--> El archivo %s NO existe.\n", txt_entrada);
		printf("----------------------------------------------\n");
		if(crear_archivo_e(txt_entrada)){
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\n --> El archivo %s fue creado EXITOSAMENTE.\n", txt_entrada);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			else{
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\tEl archivo -> %s <- NO pudo crearse.\n", txt_entrada);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				}
			}
	}while(existe_arch_e == 0);
	
	leer_entrada(txt_entrada);
	
	do{
		existe_arch_s = existe_archivo_s(txt_salida);
		if(!existe_arch_s){/*
		printf("-----------------------------------------------\n");
		printf("\tEl archivo %s YA existe.\n", txt_salida);
		printf("-----------------------------------------------\n");
		}
		else{	*/
		printf("-----------------------------------------------\n");
		printf("\tEl archivo %s NO existe.\n", txt_salida);
		printf("-----------------------------------------------\n");
		if(crear_archivo_s(txt_salida)){
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\tEl archivo %s fue creado EXITOSAMENTE.\n", txt_salida);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			else{
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\tEl archivo -> %s <- NO pudo crearse.\n", txt_salida);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				}
			}
	}while(existe_arch_s == 0);

	escribir_salida(txt_salida, txt_entrada);
}

int crear_archivo_e(char *txt_entrada){
	char caracter;
	int creado = 0;
	FILE *ptrArchivoE;
	ptrArchivoE = fopen(txt_entrada, "w");
	if( ptrArchivoE == NULL ){
		// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
		printf("----> El archivo -> %s <- no pudo crearse (abrir; uso de w).\n", txt_entrada);
	}	
	else{
		creado = 1;
		printf("----> Archivo -> %s <- Creado (abierto; uso de w).\n", txt_entrada);
		printf("El contenido del archivo %s es: ", txt_entrada);
		while((caracter = fgetc(ptrArchivoE)) != EOF){
			printf("%c", caracter);
		}
		cerrar_archivo_e(ptrArchivoE, txt_entrada);
	}
	return creado;
}

int existe_archivo_e(char *txt_entrada){
	char caracter;
	FILE *ptrArchivoE;
	int existe = 0;
	// Con r abre un archivo para lectura.
	ptrArchivoE = fopen(txt_entrada, "r");
	if( ptrArchivoE != NULL ){
		existe = 1;
		printf("\t\n --> El archivo %s YA existe", txt_entrada);
		//cerrar_archivo_e(ptrArchivo, txt_entrada);
	}
	return existe;
}

void cerrar_archivo_e(FILE *ptrArchivoE, char *txt_entrada){
	fclose(ptrArchivoE);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", txt_entrada);
}

void leer_entrada(char *txt_entrada){
	char temp[50];
	//char caracter;
	FILE *ptrArchivoE;
	ptrArchivoE = fopen(txt_entrada, "r");
	printf("\n\t-----------------------------------------------");
	printf("\n --> Leyendo datos del archivo %s", txt_entrada);
	printf("\t\n --> El contenido del archivo %s es:\n", txt_entrada);
		printf("\t");
		while(!feof(ptrArchivoE)){
			fgets(temp,50,ptrArchivoE);
		}
		printf("%s", temp);
	printf("\t-----------------------------------------------\n");
}

int crear_archivo_s(char *txt_salida){
	int creado = 0;
	FILE *ptrArchivoS;
	ptrArchivoS = fopen(txt_salida, "w");
	if( ptrArchivoS == NULL ){
		// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
		printf("--> El archivo -> %s <- no pudo crearse (abrir; uso de w).\n", txt_salida);
	}	
	else{
		creado = 1;
		printf("----> Archivo -> %s <- Creado (abierto; uso de w).\n", txt_salida);
		cerrar_archivo_s(ptrArchivoS, txt_salida);
	}
	return creado;
}

int existe_archivo_s(char *txt_salida){
	FILE *ptrArchivoS;
	int existe = 0;
	// Con r abre un archivo para lectura.
	ptrArchivoS = fopen(txt_salida, "w");
	if( ptrArchivoS != NULL ){
		existe = 1;
		printf("\t----------------------------------------------");
		printf("\t\n --> El archivo %s existe\n", txt_salida);
		printf("\t----------------------------------------------\n");
		//cerrar_archivo_e(ptrArchivo, txt_entrada);
	}	
	
	return existe;
}

void cerrar_archivo_s(FILE *ptrArchivoS, char *txt_salida){
	fclose(ptrArchivoS);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", txt_salida);
}

void escribir_salida(char *txt_salida, char *txt_entrada){
	char b[100] = "Esto es un texto";
	FILE *ptrArchivoS;
	FILE *ptrArchivoE;
	ptrArchivoS = fopen(txt_salida, "w");
	ptrArchivoE = fopen(txt_entrada, "r");
	printf("\t--------------------------------------------\n");
	printf(" --> Enviando datos de %s a %s", txt_salida, txt_entrada); 
	printf("\n\t--------------------------------------------\n");
	fprintf(ptrArchivoS, "%s", "Holi");
	//fprintf(ptrArchivoS, txt_entrada);
}

//void ord

/*
void ordenamiento(Palabra *cabeza, int numP){
	Palabra *nodAux = cabeza;
	char aux[MAXLONG];
	
	for(int i = 0; i<numP; i++){
		while(nodAux != NULL && nodAux->sig != NULL){
			if(strcmp(nodAux->palabra, nodAux->sig->palabra)>0){
				strcpy(aux, nodAux->palabra);
				strcpy(nodAux->palabra, nodAux->sig->palabra);
				strcpy(nodAux->sig->palabra, aux);
			}
		nodAux = nodAux->sig;
		}
	nodAux = cabeza;
	}*/
