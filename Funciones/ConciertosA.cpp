#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct Fecha
{
	int Dia;
	int Mes;
	int Ano;
};
typedef struct ConciertosT {//Solo para conciertos
	char Titulo[51];
	Fecha RegFecha;//Revisar
	char Lugar[51];
	char Direccion[51];
	int Edad;
	float Precios;
	int Capacidad;
	int Estacionamiento;
	int Clave;
	int Activo;

};
		FILE *Conciertos;
		ConciertosT RegConciertos;
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
	RegConciertos.Clave = 0;
	Conciertos = fopen("Archivos//Conciertos.dat","a+b");
	printf("[CREAR CONCIERTO]\n" );
	do
	{
		system("cls");
		fflush(stdin);
		printf("Titulo:");
		gets(RegConciertos.Titulo);
		printf("\nFecha:");
		fflush(stdin);
		printf("\n>Dia:");
		scanf("%d",&RegConciertos.RegFecha.Dia);
		printf("\n>Mes:");
		scanf("%d",&RegConciertos.RegFecha.Mes);
		printf("\n>Anio:");
		scanf("%d",&RegConciertos.RegFecha.Ano);
		fflush(stdin);
		printf("\nLugar:");
		gets(RegConciertos.Lugar);
		printf("\nDireccion:");
		fflush(stdin);
		gets(RegConciertos.Direccion);
		printf("\nEdad Minima:");
		scanf("%d",&RegConciertos.Edad);
		printf("\nPrecio:");
		scanf("%f",&RegConciertos.Precios);
		printf("\nCapacidad Max Personas:");
		scanf("%d",&RegConciertos.Capacidad);
		printf("\nMax Estacionamiento:");
		scanf("%d",&RegConciertos.Estacionamiento);
		fwrite(&RegConciertos, sizeof(RegConciertos), 1, Conciertos);
		fflush(stdin);
		RegConciertos.Clave++;
		RegConciertos.Activo = 1;
		printf("\nOtra alta? (S/N)\n");
		 scanf("%c",&Desea);
		 // Desea = getchar();
		 // Desea= toupper(Desea);
		fflush(stdin);
	} while (Desea == 'S' || Desea=='s');
		fclose(Conciertos);
	
}

void EliminarConciero(){
	system("cls");

}

void ModConcierto(){
	system("cls");

}
