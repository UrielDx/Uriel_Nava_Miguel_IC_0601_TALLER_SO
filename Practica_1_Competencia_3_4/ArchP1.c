#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define tam_nombre 50
#define MAX 200

typedef struct Lista Lista;
typedef struct Nodo Nodo;
typedef struct Nodo{
	char *palabra;
	Nodo *next;
}a;
struct Lista{
	Nodo *cabeza;
};
Lista *lista_nueva(void);
int existe_archivo(char *txt_entrada);
int existe_archivo_e(char *txt_entrada);
int crear_archivo_e(char *txt_entrada);
void cerrar_archivo_e(FILE *ptrArchivoE, char *txt_entrada);
int existe_archivo_s(char *txt_salida);
int crear_archivo_s(char *txt_salida);
void cerrar_archivo_s(FILE *ptrArchivoS, char *txt_salida);
void leer_entrada(char *txt_entrada);
void escribir_salida(char *txt_salida, char *txt_entrada);
void ordenamiento(char *txt_salida, char *txt_entrada);
void insertarLk(Lista *L, char *cadena);
void imprimirLK(const Lista *L);
void listaLK(Lista *L);


int main(int argc, char const *argv[]){

	char txt_entrada[tam_nombre];
	strcpy(txt_entrada, argv[1]);
	char txt_salida[tam_nombre];
	strcpy(txt_salida, argv[2]);
	int fin_e = 0, fin_s = 0;

	if(argc == 3){
		do{
			int existe_arch_e = existe_archivo_e(txt_entrada);
			if(existe_arch_e){
				printf("\t-------------------------------------------\n");
				printf("--> El archivo %s YA existe\n", txt_entrada);
				leer_entrada(txt_entrada);
				printf("\t-------------------------------------------\n");
			}
			else{
				printf("\t-------------------------------------------\n");
				printf("--> El archivo %s NO existe\n", txt_entrada);
				printf("--> Creando...\n");
				printf("\t-------------------------------------------\n");
				if(crear_archivo_e(txt_entrada)){
					printf("\t-------------------------------------------\n");
					printf("--> El archivo %s fue creado EXITOSAMENTE\n", txt_entrada);	
					printf("--> Procediendo a leer datos\n");
					leer_entrada(txt_entrada);
					printf("\t-------------------------------------------\n");
				}
				else{
					printf("\t-------------------------------------------\n");
					printf("\t--> El archivo %s NO pudo crearse\n", txt_entrada);		
					printf("\t-------------------------------------------\n");	
				}
			}
		fin_e = 1;
		}while(fin_e == 0);
		do{
			int existe_arch_s= existe_archivo_s(txt_salida);
			if(existe_arch_s){
				printf("\t-------------------------------------------\n");
				printf("--> El archivo %s YA existe\n", txt_salida);
				printf("\t--> Recibiendo datos de archivo %s\n", txt_entrada);
				printf("\t-------------------------------------------\n");
			}
			else{
				printf("\t-------------------------------------------\n");
				printf("--> El archivo %s NO existe\n", txt_salida);
				printf("--> Creando...\n");
				if(crear_archivo_s(txt_salida)){
					printf("--> El archivo %s fue creado EXITOSAMENTE\n", txt_entrada);	
					printf("\t--> Reciebiendo datos de %s\n", txt_entrada);
					printf("\t-------------------------------------------\n");
				}
				else{
					printf("\t-------------------------------------------\n");
					printf("\t--> El archivo %s NO pudo crearse\n", txt_salida);		
					printf("\t-------------------------------------------\n");	
				}
			}
		fin_s = 1;
		}while(fin_s == 0);
	ordenamiento(txt_entrada, txt_salida);
	}
	else{
		printf("No se especificaron los parametros necesarios\n");
	}
}

int crear_archivo_e(char *txt_entrada){
	char caracter;
	int creado = 0;
	FILE *ptrArchivoE;
	ptrArchivoE = fopen(txt_entrada, "r");
	if( ptrArchivoE == NULL ){
		creado = 0;
	}	
	else{
		creado = 1;
	}
	return creado;
}

int existe_archivo_e(char *txt_entrada){
	struct stat buffer;
	char caracter;
	int exist = stat(txt_entrada, &buffer);
	if(exist == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void leer_entrada(char *txt_entrada){
	char temp[MAX];
	FILE *ptrArchivoE;
	ptrArchivoE = fopen(txt_entrada, "r");
	printf("--> Leyendo datos del archivo %s\n", txt_entrada);
	printf("\t--> El contenido del archivo %s es:\n", txt_entrada);
		printf("\t");
		while(!feof(ptrArchivoE)){
			fgets(temp,MAX,ptrArchivoE);
		}
		printf("%s", temp);
}

void cerrar_archivo_e(FILE *ptrArchivoE, char *txt_entrada){
	fclose(ptrArchivoE);
	printf("\t-------------------------------------------\n");
	printf("---> El archivo %s se ha cerrado correctamente.\n", txt_entrada);
}

int crear_archivo_s(char *txt_salida){
	char caracter;
	int creado = 0;
	FILE *ptrArchivoS;
	ptrArchivoS = fopen(txt_salida, "w");
	if( ptrArchivoS == NULL ){
		creado = 0;
	}	
	else{
		creado = 1;
	}
	return creado;
}

int existe_archivo_s(char *txt_salida){
	struct stat buffer;
	char caracter;
	int exist = stat(txt_salida, &buffer);
	if(exist == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void cerrar_archivo_s(FILE *ptrArchivoS, char *txt_salida){
	fclose(ptrArchivoS);
	printf("---> El archivo %s se ha cerrado Correctamente.\n", txt_salida);
	printf("\t-------------------------------------------\n");
}

Lista *lista_nueva(void){
	Lista *L;
	L = (Lista *) malloc(sizeof(Lista));
	L->cabeza = NULL;
	return L;
}

void insertarLK(Lista *L, char *palabra){
	Nodo *n, *m;
	if(L->cabeza == NULL){
		L->cabeza = (Nodo *)malloc(sizeof(Nodo));
		L->cabeza->palabra = palabra;
		L->cabeza->next = NULL;
		return;
	}
	n = L->cabeza;
	while(n !=NULL){
		m = n;
		n = n->next;
		return;
	}
	m->next = (Nodo *)malloc(sizeof(Nodo));
	m->next->next = NULL;
	m->next->palabra = palabra;
}

void imprimirLK(const Lista *L){
	Nodo *i;
	for(i = L->cabeza; i == NULL; i= i->next){
		printf("%s", i->palabra);
	}
	printf("\n");	
}

void listaLK(Lista *L){
	if(L->cabeza == NULL){
		return;
	}
	if(L->cabeza->next == NULL){
		return;
	}
	Nodo *n, *m, *p;
	while(n != NULL){
		m = n;
		n = n->next;
	}
	free(m);
	p->next = NULL;
	listaLK(L);
}

void ordenamiento(char *txt_entrada, char *txt_salida){
	FILE *ptrArchivoE;
	ptrArchivoE = fopen(txt_entrada, "r");
	FILE *ptrArchivoS;
	ptrArchivoS = fopen(txt_salida, "w");
	char tmp[20];
	char ordn[20][20];
	int o,p,q;
	int a=0;
	Lista *lk;
	lk = lista_nueva();
	
	printf("\n\t--> Realizando ordenacion de palabras\n");
	while(!feof(ptrArchivoE)){
		fscanf(ptrArchivoE, "%s", ordn[a]);
		insertarLK(lk, ordn[a]);
		printf("\n\t %s ---> Leido", ordn[a]);
		a++;
	}
	for(o=0; o<a-1; o++){
        	q = o;
        	strcpy(tmp, ordn[o]);
        	for(p=o+1; p<a; p++){
            	if(strcmp(ordn[p], tmp)<0){
               	q = p;
                strcpy(tmp, ordn[p]);
            	}
        	}
        	strcpy(ordn[q],ordn[o]);
        	strcpy(ordn[o],tmp);
    }
  	printf("\n\n\t-------------------------------------------\n");
   	printf("\n\t--> Palabras ordenadas\n\n");
   	for(o=0; o<a; o++){
       	printf("\t--> %s",ordn[o]);
       	fprintf(ptrArchivoS,"%s\n",ordn[o]);
       	insertarLK(lk,ordn[o]);
       	listaLK(lk);
       	printf("\n");
	}
	printf("\n\t-------------------------------------------\n");
	cerrar_archivo_e(ptrArchivoE, txt_entrada);
	cerrar_archivo_s(ptrArchivoS, txt_salida);
}
