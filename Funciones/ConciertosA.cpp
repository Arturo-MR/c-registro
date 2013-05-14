#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Esta Funcion la lee el Admin y es la que se encarga de todo en los Conciertos
//Se Leen Funciones 
void CrearConcierto();
void EliminarConciero();
void ModConcierto();
//FIN Leer Funciones
//Empieza la funcion central Conciertos
void ConciertosA(){
	//Variables
	
	int opc;
	system("cls");
	printf("1. Crear Concierto\n");
	printf("2. Eliminar Concierto\n");
	printf("3. Modificar Concierto\n");
	scanf("%d",&opc);
	//OPCIONES
	switch (opc){
		case 1:
			CrearConcierto();
		break;

		case 2:

			EliminarConciero();

		break;

		case 3:
			ModConcierto();

		break;
	}
}

void CrearConcierto(){
	system("cls");
	//Variables
	char Desea;
	printf("[CREAR CONCIERTO]\n" );
	
}

void EliminarConciero(){
	system("cls");

}

void ModConcierto(){
	system("cls");

}
