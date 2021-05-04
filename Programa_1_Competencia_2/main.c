#include "scheduler.h"

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);


//Funcion que concatena la accion a realizar por los hilos
void *accion(void *arg){
	char *txt = (char *)arg;
	printf("%s", txt);
}


int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}

//Funciones que crean los hilos
void reproducir_musica(void){
	pthread_t ac1;
	pthread_create(&ac1, NULL, accion, "Reproduciendo música\n");
}

void abrir_youtube(void){
	pthread_t ac2;
	pthread_create(&ac2, NULL, accion, "Abriendo youtube\n");
}


void escribir_texto_word(void){
	pthread_t ac3;
	pthread_create(&ac3, NULL, accion, "Escribiendo texto en word\n");
}

void descargar_archivo(void){
	pthread_t ac4;
	pthread_create(&ac4, NULL, accion, "Descargando archivo\n");
}

void subiendo_archivo(void){
	pthread_t ac5;
	pthread_create(&ac5, NULL, accion, "Subiendo archivo\n");
}

void compilando_programa(void){
	pthread_t ac6;
	pthread_create(&ac6, NULL, accion, "Compilando programa\n");
}

void ejecutando_programa(void){
	pthread_t ac7;
	pthread_create(&ac7, NULL, accion, "Ejecutando programa\n");
}

void usando_terminal(void){
	pthread_t ac8;
	pthread_create(&ac8, NULL, accion, "Usando terminal\n");
}
